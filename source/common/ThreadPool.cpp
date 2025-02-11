#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threads) : stop(false)
{
    for(size_t i = 0; i < threads; ++i)
    {
        workers.emplace_back([this] //创建一个线程，并将其添加到workers容器中
        {
            while(true)
            {
                std::function<void()> task; //定义一个std::function对象，用于存储一个可调用对象
                {
                    std::unique_lock<std::mutex> lock(queue_mutex); //创建一个std::unique_lock对象，用于锁定queue_mutex
                    condition.wait(lock, [this] //等待condition条件变量，当condition条件变量被触发时，执行lambda表达式
                    {
                        return stop || !tasks.empty(); //如果stop为true或tasks为空，则返回true，否则返回false
                    });
                    
                    if(stop && tasks.empty()) //如果stop为true且tasks为空，则返回
                        return;
                        
                    task = std::move(tasks.front()); //将tasks.front()的值移动到task中
                    tasks.pop(); //从tasks中移除一个元素
                }
                task(); //执行task
            }
        });
    }
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;//获取返回值类型

    auto task = std::make_shared<std::packaged_task<return_type()>>( //创建一个std::packaged_task对象，用于存储一个可调用对象和其返回值
        std::bind(std::forward<F>(f), std::forward<Args>(args)...) //将f和args绑定在一起，形成一个可调用对象
    );
    
    std::future<return_type> res = task->get_future(); //获取任务的返回值
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.emplace([task](){ (*task)(); }); //将任务添加到任务队列中
    }
    condition.notify_one(); //通知一个等待的线程
    return res; //返回任务的返回值
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all(); //通知所有等待的线程
    for(auto &worker : workers)
    {
        worker.join(); //等待所有线程结束
    }
} 