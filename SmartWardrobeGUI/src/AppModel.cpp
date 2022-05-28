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
      m_database(WardrobeDB::getInstance())
{
    // Serial config
    // Image processing algorithm setting
    m_faceRecognition = new QFaceRecognition();
    m_handler = new QDataHandler();

    connect(m_handler, &QDataHandler::dataReady, this, &AppModel::extractData);
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

void AppModel::addPerson(QString &name, QString &rfid)
{
    // Add person's name and rfid to db => create id for face_db
    // add person image to face_db => update model
}

void AppModel::checkSlot(QStringList &names)
{
    // Check position of people recognized
    // Read user_db => rfid
    // Check rfid in wardrobedb
    // send signal to arduino and notify in UI
    // QSqlQuery query(m_database->getDBInstance());
}

void AppModel::processImage(cv::Mat frame)
{
    QStringList names = m_faceRecognition->recognition(frame);

//    QPixmap img = QPixmap::fromImage(QImage((uchar*)frame.data,
//                                            frame.cols,
//                                            frame.rows,
//                                            static_cast<int>(frame.step),
//                                            QImage::Format_RGB888).rgbSwapped());

//    emit imageReady(img);
    if(names.size() > 0)
    {
        emit idRecognizedNotify(names.at(0));
        checkSlot(names);
    }
}

void AppModel::extractData(QString &data)
{
    // Extract data from Arduino
}
