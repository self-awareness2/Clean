#include "particleDetect.h"



ParticleDetect::ParticleDetect()
{


}

ParticleDetect::~ParticleDetect()
{


}


void ParticleDetect::addImage(const cv::Mat &image)
{
    images.push_back(image);
}


void ParticleDetect::processImage()
{
    Logger::info("Processing image");
    for (const auto &image : images)
    {   
        cv::Mat gray;
        cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

        cv::Mat edges;
        cv::Canny(gray, edges, 50, 150);
    }

}



