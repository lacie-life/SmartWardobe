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
    // Mqtt config
    // Image processing algorithm setting
    m_faceRecognition = new QFaceRecognition();
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

void AppModel::processImage(cv::Mat frame)
{
    QStringList names = m_faceRecognition->recognition(frame);

    QPixmap img = QPixmap::fromImage(QImage((uchar*)frame.data,
                                            frame.cols,
                                            frame.rows,
                                            static_cast<int>(frame.step),
                                            QImage::Format_RGB888).rgbSwapped());

    emit imageReady(img);
}
