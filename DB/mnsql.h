#ifndef MNSQL_H
#define MNSQL_H

#include <QSqlRecord>
#include <QSqlField>

class MNSql
{
    QString m_Sql="";
    QString m_Where="";
    QString m_OrderBy="";
    QString m_Limit="";
    QString m_TableName="";
    QString m_FieldsNames="";
        void fillSQl();
public:
    MNSql(const QString &tableName);

    static QString createTableSql(QSqlRecord &rcd);
    QString recordCountSql();
    QString Sql() const;
    void setSql(const QString &Sql);
    QString Where() const;
    void setWhere(const QString &Where);

    QString OrderBy() const;
    void setOrderBy(const QString &OrderBy);
    QString Limit() const;
    void setLimit(const QString &Limit);
    QString TableName() const;
    void setTableName(const QString &TableName);
    QString FieldsNames() const;
    void setFieldsNames(const QString &FieldsNames);
};

#endif // MNSQL_H
