#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QPixmap>
#include <memory.h>
#include <QStringList>

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
        CHECKING_DONE_STATE,
        NO_CHEKCING_STATE,
        ADD_FACE_STATE,
        SLOT_UPDATE,
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
    void slotNotifyUI(QString position);
    void idRecognizedNotify(QString id);
    void stateChanged();

public slots:
    void processImage(cv::Mat frame);
    void extractData(QString& data);
    void checkSlot(QStringList& position);
    void setState(APP_STATE state);

public:
    APP_STATE m_state;
};

#endif // APPMODEL_H
