#include "mndb.h"

MNDb::MNDb(QString dbPath,QString dbName , QObject *parent) : QObject(parent)
{
    db=QSqlDatabase::addDatabase("QSQLITE",dbName);
    db.setDatabaseName(dbPath);
    db.open();
    this->name =dbName;

}

MNDb::~MNDb()
{
    close();
}

bool MNDb::open(){
    return db.open();
}

void MNDb::close(){

     db.close();
}
















bool MNDb::isTableExists(QString &tableName)
{
    QSqlQuery query(db);
    query.exec("SELECT name FROM sqlite_master WHERE type='table' AND name='"
               +tableName+"';");
    return (query.size()>0);
}

//MNRecord MNDb::getFirstRecord(QString sql)
//{
//    if (query.exec(sql)){
//        query.first();
//        return query.record();
//    }
//    return MNRecord();
//}

