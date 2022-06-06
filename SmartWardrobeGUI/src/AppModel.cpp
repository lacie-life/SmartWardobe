#include "AppModel.h"
#include "AppConstants.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QStringList>
#include <QImage>
#include <QPixmap>
#include <QStringList>

AppModel::AppModel(QObject *parent)
    : QObject{parent},
      m_database(WardrobeDB::getInstance()),
      m_state(NO_CHEKCING_STATE)
{
    // Serial config
    // Image processing algorithm setting
    m_faceRecognition = new QFaceRecognition(nullptr, 1);
    m_handler = new QDataHandler();
    m_handler->openSerialPort();

    connect(m_handler, &QDataHandler::dataReady, this, &AppModel::extractData);
    connect(m_faceRecognition, &QFaceRecognition::recognized, this, &AppModel::checkFace);
}

bool AppModel::addSlot(QString position, QString rfid)
{
    // TODO: update slot with rfid
    QSqlQuery query(m_database->getDBInstance());
    query.prepare("update wardrobe set available='N', rfid= :rfid where slot= '" + position +"'");
    query.bindValue(":rfid", rfid);

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
    // TODO: check and remove rfid
    QSqlQuery query(m_database->getDBInstance());
    query.prepare("update wardrobe set available='Y', rfid='' where slot= '" + position +"'");

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

void AppModel::writeRecord(QString &rfid, QString &position, int state)
{
    // TODO: write record of rfid to db/text/csv
}

void AppModel::findFaceInfor(QString faceId, QFaceInfor& faceInfor)
{
    QSqlQuery query(m_database->getDBInstance());
    query.prepare("SELECT * FROM face_db WHERE id = :id");
    query.bindValue(":id", faceId.toInt());

    query.exec();

    if(query.first()){
        CONSOLE << query.value("id").toInt();
        faceInfor.setId(query.value("id").toInt());
        faceInfor.setName(query.value("name").toString());
        faceInfor.setRFID(query.value("rfid").toString());
        faceInfor.setType(query.value("type").toString());
    }
}

QString AppModel::findSlot(QString rfid)
{
    QSqlQuery query(m_database->getDBInstance());
    query.prepare("SELECT * FROM wardrobe WHERE rfid = :rfid");
    query.bindValue(":rfid", rfid);

    query.exec();

    if(query.first())
    {
        return query.value("slot").toString();
    }
    return "";
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

        // Check faceId infor
        findFaceInfor(names.at(0), m_currentFace);

        QString slot = findSlot(m_currentFace.rfid());

        m_currentFace.setCurrentPosition(slot);

        CONSOLE << "Face slot: " << slot;
        CONSOLE << "Face name: " << m_currentFace.name();
        CONSOLE << "Face type: " << m_currentFace.type();
        CONSOLE << "Face slot: " << m_currentFace.currentPosition();

        emit recognitionDone();
    }
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
    CONSOLE << "Arduino sent: " << data;
    QStringList extract = data.split(":");
    CONSOLE << extract;

    if(extract.at(0) == "set"){
        CONSOLE << extract.at(1);
        bool result = addSlot(extract.at(1), extract.at(2));
        if (result){
            CONSOLE << "Add slot success";
        }
        else{
            CONSOLE << "Add slot fail";
        }
    }
    else if(extract.at(0) == "p") {
        CONSOLE << extract.at(1);
        if (extract.at(1) == "1"){
            CONSOLE << "Person checked";
            emit havePerson();
        }
        else{
            CONSOLE << "No person";
            emit noPerson();
        }
    }
}
