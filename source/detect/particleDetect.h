#include <opencv2/opencv.hpp>
#include <QObject> 
#include <QThread>
#include "log/Logger.h"





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
