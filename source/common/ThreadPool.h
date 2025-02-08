#pragma once

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>
#include <future>

class ThreadPool {
public:
    static ThreadPool& getInstance() {
        static ThreadPool instance;
        return instance;
    }

    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;

    ~ThreadPool();

private:
    ThreadPool(size_t threads = std::thread::hardware_concurrency());
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    
    std::mutex queue_mutex;
    std::condition_variable condition;
    std::atomic<bool> stop;
}; 