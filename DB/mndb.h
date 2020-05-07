#ifndef MNDB_H
#define MNDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QPointer>


class MNDb : public QObject
{
    Q_OBJECT
    QSqlDatabase db;
    QSqlQuery query;
    QString name;

public:
    explicit MNDb(QString dbPath, QString dbName, QObject *parent = nullptr);
    ~MNDb() ;
    bool runSql(QString sql);
    bool runSqlTran(QString sql);
    bool open();
    void close();
    bool pragmaFast();
    bool pragmaNormal();
    void startTrans();
    bool commitTrans();
    bool rollbackTrans();
    bool runSqlWithTran(QString sql);
    QSqlTableModel *getTableModel(QString tableName, QString whereSql);
    QSqlQueryModel *getQueryModel(QString sql);
    bool isTableExists(QString tableName);
    QSqlQuery getQuery();
    QSqlQuery newQuery(QString sql);//use this to create new select query


signals:

};

#endif // MNDB_H
