#ifndef QCAMERACAPTURE_H
#define QCAMERACAPTURE_H

#include <QObject>
#include <sl/Camera.hpp>
#include <opencv2/opencv.hpp>

class QCameraCapture : public QObject
{
    Q_OBJECT
public:
    explicit QCameraCapture(QObject *parent = nullptr);
    ~QCameraCapture();

    bool initCamera();
    void stream();

signals:

private:
    cv::Mat slMat2cvMat(sl::Mat& input);
    int getOpenCVType(sl::MAT_TYPE type);

private:
    cv::Mat image_ocv;
    cv::Mat depth_image_ocv;

    sl::Camera m_camera;
};

#endif // QCAMERACAPTURE_H
