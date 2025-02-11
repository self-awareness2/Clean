#include "ThreadPool.h"

ThreadPool::ThreadPool(size_t threads) : stop(false)
{
    for(size_t i = 0; i < threads; ++i)
    {
        workers.emplace_back([this] //����һ���̣߳���������ӵ�workers������
        {
            while(true)
            {
                std::function<void()> task; //����һ��std::function�������ڴ洢һ���ɵ��ö���
                {
                    std::unique_lock<std::mutex> lock(queue_mutex); //����һ��std::unique_lock������������queue_mutex
                    condition.wait(lock, [this] //�ȴ�condition������������condition��������������ʱ��ִ��lambda���ʽ
                    {
                        return stop || !tasks.empty(); //���stopΪtrue��tasksΪ�գ��򷵻�true�����򷵻�false
                    });
                    
                    if(stop && tasks.empty()) //���stopΪtrue��tasksΪ�գ��򷵻�
                        return;
                        
                    task = std::move(tasks.front()); //��tasks.front()��ֵ�ƶ���task��
                    tasks.pop(); //��tasks���Ƴ�һ��Ԫ��
                }
                task(); //ִ��task
            }
        });
    }
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;//��ȡ����ֵ����

    auto task = std::make_shared<std::packaged_task<return_type()>>( //����һ��std::packaged_task�������ڴ洢һ���ɵ��ö�����䷵��ֵ
        std::bind(std::forward<F>(f), std::forward<Args>(args)...) //��f��args����һ���γ�һ���ɵ��ö���
    );
    
    std::future<return_type> res = task->get_future(); //��ȡ����ķ���ֵ
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.emplace([task](){ (*task)(); }); //��������ӵ����������
    }
    condition.notify_one(); //֪ͨһ���ȴ����߳�
    return res; //��������ķ���ֵ
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all(); //֪ͨ���еȴ����߳�
    for(auto &worker : workers)
    {
        worker.join(); //�ȴ������߳̽���
    }
} 