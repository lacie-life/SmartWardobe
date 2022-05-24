#include "AppModel.h"
#include "AppConstants.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

AppModel::AppModel(QObject *parent)
    : QObject{parent},
      m_database(WardrobeDB::getInstance())
{
    // Mqtt config

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
