#include "mnkitaborg.h"

MNKitabOrg::MNKitabOrg(QString dbName, QObject *parent) : QObject(parent)
{
    QString tableName;
    queryKitab= QSharedPointer<MNQuery>(new MNQuery(dbName,this));
    if (queryKitab->first()){
         tableName = "b"+queryKitab->value(0).toString();
    }
    queryKitab->runSql("select * from "+tableName);
    queryKitab->first();

    //dont forget query.first;
}

QString MNKitabOrg::getNass()
{
    return queryKitab->value("nass").toString();
}

int MNKitabOrg::getID()
{
    return queryKitab->value("id").toInt();
}


