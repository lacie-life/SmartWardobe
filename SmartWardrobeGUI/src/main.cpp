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
    qRegisterMetaType<cv::Mat>("cv::Mat");
    MainWindow w;
    w.show();
    return a.exec();

//    QFaceRecognition faceRecognition(nullptr, 0);
//    faceRecognition.faceTrainer();

    return 0;
}
