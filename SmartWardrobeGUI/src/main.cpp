#include "MainWindow.h"
#include "AppConstants.h"
#include "QCameraCapture.h"
#include "QFaceRecognition.h"

#include <QApplication>
#include <opencv2/core.hpp>
#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

//    QFaceRecognition faceRecognition;

//    cv::Mat img = cv::imread(IMAGE_TEST, cv::IMREAD_UNCHANGED);
//    QStringList names = faceRecognition.recognition(img);

//    qDebug() << names;

    return 0;
}
