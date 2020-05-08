#ifndef MNKITAB_H
#define MNKITAB_H

#include <QObject>
#include "./DB/mndb.h"

class MNKitab : public QObject
{
    Q_OBJECT
    QPointer<MNDb> dbKitab;
public:
    explicit MNKitab(MNDb *kitabDb,QObject *parent = nullptr);


signals:

};

#endif // MNKITAB_H
