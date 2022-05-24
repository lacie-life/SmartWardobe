#ifndef APPCONSTANTS_H
#define APPCONSTANTS_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QColor>
#include <QMutex>
#include <QCoreApplication>

#ifndef MACRO_DEFINE
#define MACRO_DEFINE

#define CONSOLE qDebug() << "[" << __FUNCTION__ << "] "

#endif

#ifndef BUILD_DIR

#define BUILD_DIR QCoreApplication::applicationDirPath()

#endif

#define DB_PATH "./data/wardrobedb.db"

#define AVAILABLE_SLOT "./data/res/available.jpg"
#define UNAVAILABLE_SLOT "./data/res/unavailable.jpg"

#endif // APPCONSTANTS_H
