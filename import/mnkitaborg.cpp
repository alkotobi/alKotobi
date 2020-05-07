#include "mnkitaborg.h"

MNKitabOrg::MNKitabOrg(MNDb *db,QObject *parent) : QObject(parent)
{
    QString tableName;
    QSqlQuery query= db->newQuery("select Bkid from Main");
    if (query.first()){
         tableName = "b"+query.value(0).toString();
    }
    query.exec("select * from "+tableName);
    query.first();
    this->queryKitab =query;
    //dont forget query.first;
}

QString MNKitabOrg::getNass()
{
    return queryKitab.value("nass").toString();
}

int MNKitabOrg::getID()
{
    return queryKitab.value("id").toInt();
}


