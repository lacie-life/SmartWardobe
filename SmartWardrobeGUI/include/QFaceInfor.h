#ifndef QFACEINFOR_H
#define QFACEINFOR_H

#include <QObject>
#include <QString>

class QFaceInfor : public QObject
{
    Q_OBJECT
public:
    explicit QFaceInfor(QObject *parent = nullptr);

    QFaceInfor(QString name, QString rfid, QString type);

    int id() const;
    QString name() const;
    QString rfid() const;
    QString type() const;
    QString currentPosition() const;

    void setId(int id);
    void setName(QString name);
    void setRFID(QString rfid);
    void setType(QString type);
    void setCurrentPosition(QString position);

signals:

private:
    int m_id;
    QString m_name;
    QString m_rfid;
    QString m_type;
    QString m_currentWardrobePosition;
};

#endif // QFACEINFOR_H
