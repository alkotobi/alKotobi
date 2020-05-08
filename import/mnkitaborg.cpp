#include "mnkitaborg.h"

MNKitabOrg::MNKitabOrg(MNDb &db,QObject *parent) : QObject(parent)
{
    QString tableName;
    queryKitab= QSharedPointer<MNQuery>(new MNQuery(db,this));
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


