#ifndef QDATAHANDLER_H
#define QDATAHANDLER_H

#include <QObject>

// Connect with Arduino, read and extract information
class QDataHandler : public QObject
{
    Q_OBJECT
public:
    QDataHandler();
    ~QDataHandler();

signals:

};

#endif // QDATAHANDLER_H
