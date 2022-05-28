#include "AppModel.h"
#include "AppConstants.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QStringList>
#include <QImage>
#include <QPixmap>

AppModel::AppModel(QObject *parent)
    : QObject{parent},
      m_database(WardrobeDB::getInstance()),
      m_state(NO_CHEKCING_STATE)
{
    // Serial config
    // Image processing algorithm setting
    m_faceRecognition = new QFaceRecognition();
    m_handler = new QDataHandler();

    connect(m_handler, &QDataHandler::dataReady, this, &AppModel::extractData);
    connect(m_faceRecognition, &QFaceRecognition::recognized, this, &AppModel::checkFace);
}

bool AppModel::addSlot(QString& position)
{
    QSqlQuery query(m_database->getDBInstance());
    query.prepare("update wardrobe set available='N' where slot= '" + position +"'");

    if(!query.exec())
    {
        CONSOLE << query.lastError().text() << query.lastQuery();
        return false;
    }
    else
    {
        if(query.numRowsAffected() > 0)
        {

            CONSOLE << "read was successful "<< query.lastQuery();
        }
        else
        {
            CONSOLE << "Unable to update data";
        }
    }

    emit slotUpdate();

    return true;
}

bool AppModel::removeSlot(QString& position)
{
    QSqlQuery query(m_database->getDBInstance());
    query.prepare("update wardrobe set available='Y' where slot= '" + position +"'");

    if(!query.exec())
    {
        CONSOLE << query.lastError().text() << query.lastQuery();
        return false;
    }
    else
    {
        if(query.numRowsAffected() > 0)
        {

            CONSOLE << "read was successful "<< query.lastQuery();
        }
        else
        {
            CONSOLE << "Unable to update data";
        }
    }

    emit slotUpdate();

    return true;
}

void AppModel::addFace(QString &name, QString &rfid)
{
    // Add person's name and rfid to db => create id for face_db
    // add person image to face_db => update model
}

QFaceInfor AppModel::findFaceInfor(QString faceId)
{
    QSqlQuery query(m_database->getDBInstance());

}

QString AppModel::findSlot(QString rfid)
{
    QSqlQuery query(m_database->getDBInstance());

}

void AppModel::checkFace(QStringList &names)
{
    // Check position of list people recognized (in this case have only one person)
    // Read user_db => rfid
    // Check rfid in wardrobedb
    // send signal to arduino and notify in UI
    // QSqlQuery query(m_database->getDBInstance());

    if(names.size() > 0){
        emit idRecognizedNotify(names.at(0));
        m_state = CHECKING_DONE_STATE;
        CONSOLE << "Recognition done!";
        CONSOLE << "Id: " << names.at(0);
    }

    // Check faceId infor
    m_currentFace = findFaceInfor(names.at(0));

    QString slot = findSlot(m_currentFace.rfid());

    m_currentFace.setCurrentPosition(slot);

    CONSOLE << "Face slot: " << slot;
}

void AppModel::setState(APP_STATE state)
{
    m_state = state;
}

void AppModel::processImage(cv::Mat frame)
{
    if(m_state == CHECKING_STATE)
    {
        m_faceRecognition->recognition(frame);
    }
}

void AppModel::extractData(QString &data)
{
    // Extract data from Arduino
}
