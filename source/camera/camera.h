#include <LTSController.h>
#include <sapclassbasic.h>
#include <SapAcquisition.h>
#include <QObject>
#include <opencv2/opencv.hpp>

class Camera : public QObject
{
    Q_OBJECT
public:
    Camera();
    ~Camera();

public slots:
    void startCarema(int nums);
    void stopCarema();

public signals:
    void imageCaptured(const cv::Mat &image);
    void captureError(const QString &error);
private:
    void initialize();
    void openLight();
    void closeLight();
};

