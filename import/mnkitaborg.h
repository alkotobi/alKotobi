#ifndef MNKITABORG_H
#define MNKITABORG_H

#include <QObject>
#include "./DB/mndb.h"
#include "./DB/mnquery.h"

class MNKitabOrg : public QObject
{
    Q_OBJECT
   QSharedPointer<MNQuery>  queryKitab;
public:
    explicit MNKitabOrg(MNDb* db, QObject *parent = nullptr);
    QString getNass();
    int getID();


signals:

};

#endif // MNKITABORG_H
