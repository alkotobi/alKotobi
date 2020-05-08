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

class MNImport : public QObject
{
    Q_OBJECT
    QPointer<MNDb> dbSource;
    QPointer<MNKitabOrg> kitabOrg;

public:
    explicit MNImport(MNDb &db, QObject *parent = nullptr);
    ~MNImport();


    QPointer<MNKitabOrg> getKitabOrg() const;

signals:

};

#endif // MNIMPORT_H
