#ifndef MNRECORD_H
#define MNRECORD_H

#include <QObject>
#include <QVector>
#include <QPointer>
#include "mnfield.h"


using  ptrMNField = QPointer<MNField>;

class MNRecord : public QObject
{
    Q_OBJECT
    QVector<ptrMNField> record;

public:
    explicit MNRecord(QObject *parent = nullptr);
    void append(ptrMNField ptrFld);
    ptrMNField getField(int ind);
    QString createTableSql(QString tableName);
    QString createIndexSql(QString tableName, ptrMNField fld);
    QString insertSql(QString tableName);
    int count();

signals:

};

#endif // MNRECORD_H
