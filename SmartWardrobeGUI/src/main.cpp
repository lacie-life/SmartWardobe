#include "MainWindow.h"
#include "QCameraCapture.h"
#include "QFaceRecognition.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    QFaceRecognition faceRecognition;
    faceRecognition.faceTrainer();

    return 0;
}
