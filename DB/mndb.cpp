#include "mndb.h"

QSqlQuery MNDb::getQuery()
{
    return query;
}



MNDb::MNDb(QString dbPath,QString dbName , QObject *parent) : QObject(parent)
{
    db=QSqlDatabase::addDatabase("QSQLITE",dbName);
    db.setDatabaseName(dbPath);
    query = QSqlQuery(db);
    this->name =dbName;

}

MNDb::~MNDb()
{
    query.clear();
    db.close();
}


bool MNDb::open(){
    return db.open();
}

void MNDb::close(){
    query.clear();
     db.close();
}

bool MNDb::pragmaFast(){
    return     query.exec("PRAGMA synchronous = OFF;"
                          "PRAGMA journal_mode = OFF;"
                          "locking_mode = SHARED;"
                          "temp_store = DEFAULT;"
                          "foreign_keys = ON;");
}
bool MNDb::pragmaNormal(){
    return     query.exec("PRAGMA synchronous = ON;"
                          "PRAGMA journal_mode = ON;"
                          "locking_mode = EXCLUSIVE;"
                          "temp_store = MEMORY;"
                          "foreign_keys = OFF;");
}

void MNDb::startTrans(){
   QSqlDatabase::database(name).transaction();
}

bool MNDb::commitTrans(){
   return QSqlDatabase::database(name).commit();
}

bool  MNDb::rollbackTrans(){
   return QSqlDatabase::database(name).rollback();
}

bool MNDb::runSql(QString sql)
{
   return query.exec(sql);
}

bool MNDb::runSqlWithTran(QString sql)
{
    startTrans();
    query.exec(sql);
    if (commitTrans()) return true;
    else {
        rollbackTrans();
        return false;
    }
}

QSqlTableModel* MNDb::getTableModel(QString tableName,QString whereSql=""){

    QPointer<QSqlTableModel> model= new QSqlTableModel(this,db);
    model->setTable(tableName);
    if(whereSql !="")model->setFilter(whereSql);
    model->select();
    return model;
}

QSqlQueryModel* MNDb::getQueryModel(QString sql){

    QPointer<QSqlQueryModel> model= new QSqlQueryModel(this);
    model->setQuery(sql,db);
    return model;
}

bool MNDb::isTableExists(QString tableName)
{
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

