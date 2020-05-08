#ifndef MNDB_H
#define MNDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QPointer>
#include <QSharedPointer>


class MNDb : public QObject
{
    Q_OBJECT

public:
    QSqlDatabase db;
    QString name;
    explicit MNDb(QString dbPath, QString dbName, QObject *parent = nullptr);
    ~MNDb() ;

    bool open();
    void close();
    bool isTableExists(QString &tableName);



signals:

};

#endif // MNDB_H
