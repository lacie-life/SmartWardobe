#include "QFaceInfor.h"

QFaceInfor::QFaceInfor(QObject *parent)
    : QObject{parent}
{

}

QFaceInfor::QFaceInfor(QString name, QString rfid, QString type)
    : m_name(name),
      m_rfid(rfid),
      m_type(type)
{

}

int QFaceInfor::id() const
{
    return m_id;
}

QString QFaceInfor::rfid() const
{
    return m_rfid;
}

QString QFaceInfor::type() const
{
    return m_type;
}

QString QFaceInfor::currentPosition() const
{
    return m_currentWardrobePosition;
}

void QFaceInfor::setId(int id)
{
    m_id = id;
}

void QFaceInfor::setRFID(QString rfid)
{
    m_rfid = rfid;
}

void QFaceInfor::setType(QString type)
{
    m_type = type;
}

void QFaceInfor::setCurrentPosition(QString position)
{
    m_currentWardrobePosition = position;
}
