#include "MainWindow.h"
#include "QCameraCapture.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    QCameraCapture zed2;
    zed2.initCamera();
    zed2.stream();

    return 0;
}
