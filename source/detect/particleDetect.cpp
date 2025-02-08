#include "particleDetect.h"
#include "common/ThreadPool.h"

ParticleDetect::ParticleDetect()
{
    initThreadPool(std::thread::hardware_concurrency());
    stop = false;
}

ParticleDetect::~ParticleDetect()
{
    stopThreadPool();
}

void ParticleDetect::initThreadPool(size_t threads)
{
    for(size_t i = 0; i < threads; ++i)
    {
        workers.emplace_back([this]
        {
            while(true)
            {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(queue_mutex);
                    condition.wait(lock, [this]
                    {
                        return stop || !tasks.empty();
                    });
                    
                    if(stop && tasks.empty())
                        return;
                        
                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
    }
}

void ParticleDetect::stopThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    
    condition.notify_all();
    for(auto &worker : workers)
    {
        if(worker.joinable())
            worker.join();
    }
}

void ParticleDetect::addImage(const cv::Mat &image)
{
    images.push_back(image);
}

void ParticleDetect::processImage()
{
    Logger::info("Processing images using global thread pool");
    
    std::mutex mtx;  // ������־ͬ��
    std::atomic<int> completed(0);
    int total = images.size();
    std::vector<std::future<void>> futures;
    
    // �ύ����ȫ���̳߳�
    for(const auto &image : images)
    {
        auto future = ThreadPool::getInstance().enqueue(
            [&image, &mtx, &completed, total]()
            {
                cv::Mat gray;
                cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

                cv::Mat edges;
                cv::Canny(gray, edges, 50, 150);
                
                {
                    std::lock_guard<std::mutex> lock(mtx);
                    completed++;
                    Logger::info("Processed image " + std::to_string(completed) + 
                               " of " + std::to_string(total));
                }
            });
        futures.push_back(std::move(future));
    }
    
    // �ȴ������������
    for(auto &future : futures)
    {
        future.wait();
    }
}



