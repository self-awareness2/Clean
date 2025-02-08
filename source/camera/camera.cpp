#include "camera.h" 

Camera::Camera()
{
    initialize();
}

Camera::~Camera()
{
}   

void Camera::initialize()
{

}

/// @brief  开始采集
void Camera::startCarema(int nums)
{
}

/// @brief  停止采集
void Camera::stopCarema()
{
}

/// @brief  打开光源
void Camera::openLight()

{
    LTSController_TurnOnAllChannelLength(1, 155);
    LTSController_SetIntensityLength(1, 155);
}

/// @brief  关闭光源
void Camera::closeLight()
{
    LTSController_TurnOffAllChannelLength(1, 155);
    LTSController_SetIntensityLength(1, 0);
}