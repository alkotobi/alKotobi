#include "mnquery.h"


MNQuery::MNQuery(MNDb *db, QObject *parent) : QObject(parent)
{
        this->query= QSharedPointer<QSqlQuery>(new QSqlQuery(db->db));
        this->dbName = db->name;

}

bool MNQuery::runSql(QString sql)
{
    return query->exec(sql);
}

bool MNQuery::pragmaFast()
{
    return     query->exec("PRAGMA synchronous = OFF;"
                          "PRAGMA journal_mode = OFF;"
                          "locking_mode = SHARED;"
                          "temp_store = DEFAULT;"
                          "foreign_keys = ON;");

}

bool MNQuery::pragmaNormal()
{
    return     query->exec("PRAGMA synchronous = ON;"
                          "PRAGMA journal_mode = ON;"
                          "locking_mode = EXCLUSIVE;"
                          "temp_store = MEMORY;"
                          "foreign_keys = OFF;");
}

void MNQuery::startTrans()
{
    QSqlDatabase::database(dbName).transaction();
}

bool MNQuery::commitTrans()
{
       return QSqlDatabase::database(dbName).commit();
}

bool MNQuery::rollbackTrans()
{
   return QSqlDatabase::database(dbName).rollback();
}

bool MNQuery::runSqlWithTran(QString &sql)
{
    startTrans();
    query->exec(sql);
    if (commitTrans()) return true;
    else {
        rollbackTrans();
        return false;
    }
}

bool MNQuery::first()
{
    return this->query->first();
}

bool MNQuery::next()
{
    return this->query->next();
}

bool MNQuery::last()
{
    return this->query->last();
}

bool MNQuery::previous()
{
    return this->query->previous();
}

QVariant MNQuery::value(int id)
{
    return query->value(id);
}

QVariant MNQuery::value(QString fieldName)
{
    return query->value(fieldName);
}


