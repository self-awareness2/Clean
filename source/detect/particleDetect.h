#include <opencv2/opencv.hpp>
#include <QObject> 
#include <vector>
#include <mutex>
#include "log/Logger.h"
#include <atomic>
#include "../common/ThreadPool.h"

class ParticleDetect
{
public:
    ParticleDetect();
    ~ParticleDetect();
    void addImage(const cv::Mat &image);

private: 
    std::vector<cv::Mat> images;
    void processImage();
};
