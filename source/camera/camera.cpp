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

/// @brief  ��ʼ�ɼ�
void Camera::startCarema(int nums)
{
}

/// @brief  ֹͣ�ɼ�
void Camera::stopCarema()
{
}

/// @brief  �򿪹�Դ
void Camera::openLight()

{
    LTSController_TurnOnAllChannelLength(1, 155);
    LTSController_SetIntensityLength(1, 155);
}

/// @brief  �رչ�Դ
void Camera::closeLight()
{
    LTSController_TurnOffAllChannelLength(1, 155);
    LTSController_SetIntensityLength(1, 0);
}