#include "mnrecordset.h"

bool MNRecordSet::isOpen() const
{
    return m_isOpen;
}



bool MNRecordSet::isEmpty() const
{
    return m_isEmpty;
}

bool MNRecordSet::next()
{
    onBeforeScroll(this);
    if (query->next()){
        setRecordNo(recordNo()+1);
        onAfterScroll(this);
        return true;
    };
    return false;

}

bool MNRecordSet::previous()
{
    onBeforeScroll(this);
    if(query->previous()){
        setRecordNo(recordNo()-1);
        onAfterScroll(this);
        return true;
    }
    return false;
}

bool MNRecordSet::first()
{
    onBeforeScroll(this);
    if(query->first()){
        setRecordNo(0);
        onAfterScroll(this);
        return true;
    }

    return false;
}

bool MNRecordSet::last()
{
    onBeforeScroll(this);
     if(query->last()){
         setRecordNo(recordCount()-1);
         onAfterScroll(this);
         return true;
     }
     return false;
}


void MNRecordSet::setIsEmpty(bool isEmpty)
{
    m_isEmpty = isEmpty;
}

int MNRecordSet::recordNo() const
{
    return mRecordNo;
}

void MNRecordSet::setRecordNo(int recordNo)
{
    mRecordNo = recordNo;
}


int MNRecordSet::recordCount() const
{
    return m_recordCount;
}

void MNRecordSet::setRecordCount(int recordCount)
{
    m_recordCount = recordCount;
}

QString MNRecordSet::dbPath() const
{
    return m_dbPath;
}

void MNRecordSet::setDbPath(const QString &dbPath)
{
    m_dbPath = dbPath;
}

void MNRecordSet::setIsOpen(bool isOpen)
{
    m_isOpen = isOpen;
}

MNRecordSet::MNRecordSet(QString dbPath,QString tableName,QObject *parent)
    : QObject(parent),m_dbPath(dbPath),sql(MNSql(tableName))
{

    if(!QSqlDatabase::contains(dbPath)){
        QSqlDatabase::addDatabase("QSQLITE",dbPath).setDatabaseName(dbPath);
        QSqlDatabase::database(dbPath).open();
    }
    if(!QSqlDatabase::database(dbPath).isOpen()) QSqlDatabase::database(dbPath).open();
    this->query = new QSqlQuery(QSqlDatabase::database(dbPath));

}

void MNRecordSet::close()
{
    setRecordNo(-1);
    setRecordCount(0);
    setIsOpen(false);
}

bool MNRecordSet::open()
{
    setIsOpen(false);
    if(query->exec(sql.Sql())){
    setIsOpen(true);
    if(query->size() != 0) setIsEmpty(false);else setIsEmpty(true);
    QSqlQuery countQuery = QSqlQuery(QSqlDatabase::database(dbPath()));
    if(countQuery.exec(sql.recordCountSql())){
        countQuery.first();
        setRecordCount(countQuery.value(0).toInt());
    }
    return true;
    }
    return false;
}
