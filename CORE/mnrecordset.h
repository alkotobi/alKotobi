#ifndef MNRECORDSET_H
#define MNRECORDSET_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "./DB/mnsql.h"

typedef void (*rdsEvent)(QObject *sender);
class MNRecordSet : public QObject
{

    Q_OBJECT
    QSqlQuery *query;

    bool m_isOpen=false;
    bool m_isEmpty=true;
    int mRecordNo=-1;
    int m_recordCount=0;
    QString m_dbPath;
    void setIsOpen(bool isOpen);
    void setIsEmpty(bool isEmpty);
    void setRecordNo(int recordNo);
    void setRecordCount(int recordCount);

public:


    MNSql sql;
    explicit MNRecordSet(QString dbPath, QString tableName, QObject *parent = nullptr);
    void close();
    bool open();
    bool isOpen() const;
    bool isEmpty() const;
    bool next();
    bool previous();
    bool first();
    bool last();
    int recordNo() const;
    rdsEvent onBeforeScroll=[](QObject *sender) {

    };
    rdsEvent onAfterScroll=[](QObject *sender) {

    };
    int recordCount() const;


    QString dbPath() const;
    void setDbPath(const QString &dbPath);

signals:

};



#endif // MNRECORDSET_H
