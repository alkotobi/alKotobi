#ifndef MNQUERY_H
#define MNQUERY_H

#include <QObject>
#include "mndb.h"


class MNQuery : public QObject
{
    Q_OBJECT

    QString dbName;
public:
    QSharedPointer<QSqlQuery> query;
    explicit MNQuery(MNDb &db, QObject *parent = nullptr);
    bool runSql(QString sql);
    bool pragmaFast();
    bool pragmaNormal();
    void startTrans();
    bool commitTrans();
    bool rollbackTrans();
    bool runSqlWithTran(QString &sql);
    bool first();
    bool next();
    bool last();
    bool previous();
    QVariant value(int id);
    QVariant value(QString fieldName);
signals:

};

#endif // MNQUERY_H
