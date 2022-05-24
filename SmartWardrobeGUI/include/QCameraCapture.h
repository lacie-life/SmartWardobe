#ifndef QCAMERACAPTURE_H
#define QCAMERACAPTURE_H

#include <QObject>

class QCameraCapture : public QObject
{
    Q_OBJECT
public:
    explicit QCameraCapture(QObject *parent = nullptr);

signals:

};

#endif // QCAMERACAPTURE_H
