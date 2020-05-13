#ifndef MNKITAB_H
#define MNKITAB_H

#include <QObject>
#include "./DB/mndb.h"

class MNKitab : public QObject
{
    Q_OBJECT
    QString dbName;
public:
    explicit MNKitab(QString dbName,QObject *parent = nullptr);


signals:

};

#endif // MNKITAB_H
