#ifndef MNIMPORT_H
#define MNIMPORT_H

#include <QObject>
#include "./HELPERS/mnpathes.h"
#include "./import/mnindexorg.h"
#include "./import/mnkitaborg.h"
#include "./import/mnothororg.h"
#include "./kitab/mnkitab.h"
#include "./DB/mndb.h"
#include <QPointer>
#include "HELPERS/mnpathes.h"

class MNImport : public QObject
{
    Q_OBJECT


public:
    explicit MNImport(QString sourceDbPAth, QObject *parent = nullptr);
    ~MNImport();
    QPointer<MNDb> dbSource;
    QPointer<MNDb> dbDest;
    QPointer<MNKitabOrg> kitabOrg;
    QPointer<MNKitab> kitabDest;



signals:

};

#endif // MNIMPORT_H
