#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QPixmap>
#include <memory.h>

#include "WardrobeDB.h"
#include "QDataHandler.h"
#include "QFaceRecognition.h"

class AppModel : public QObject
{
    Q_OBJECT

    Q_ENUMS(APP_STATE)

public:

    enum APP_STATE {
        NONE_STATE,
        CHECKING_STATE,
        NO_CHEKCING_STATE,
        END_STATE,
    };

    explicit AppModel(QObject *parent = nullptr);

    bool addSlot(QString& position);
    bool removeSlot(QString& position);
    void addPerson(QString& name, QString& rfid);

    WardrobeDB* m_database;
    QDataHandler* m_handler;
    QFaceRecognition* m_faceRecognition;

signals:
    void slotUpdate();
    void imageReady(QPixmap pixmap);
    void sendIndex(QString index);
    void havePerson();  // start camera widget
    void noPerson();    // close camera widget and switch to wardrobe widget

public slots:
    void processImage(cv::Mat frame);
    void extractData(QString& data);
};

#endif // APPMODEL_H
