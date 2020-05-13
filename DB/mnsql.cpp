#include "mnsql.h"


void MNSql::fillSQl()
{
    QString str="";
    if(this->FieldsNames() =="") str="SELECT * FROM "+this->TableName();
    else str = "SELECT "+FieldsNames()+" FROM "+TableName();
    if(Where()!="") str = str+" WHERE "+Where();
    if(OrderBy()!="") str = str+ " ORDER BY "+OrderBy();
    if(Limit()!="") str = str + " LIMIT "+Limit();
    setSql(str);
}

MNSql::MNSql(const QString &tableName)
{
    this->setTableName(tableName);
    this->setSql("select * from "+tableName);
}

QString MNSql::recordCountSql()
{
    QString str;
    str="SELECT COUNT() FROM "+this->TableName();
    if(Where()!="") str = str+" WHERE "+Where();
    return str;
}

QString MNSql::Sql() const
{
    return m_Sql;
}

void MNSql::setSql(const QString &Sql)
{
    m_Sql = Sql;
}

QString MNSql::Where() const
{
    return m_Where;
}

void MNSql::setWhere(const QString &Where)
{
    m_Where = Where;
    fillSQl();
}


QString MNSql::OrderBy() const
{
    return m_OrderBy;
}

void MNSql::setOrderBy(const QString &OrderBy)
{
    m_OrderBy = OrderBy;
    fillSQl();
}

QString MNSql::Limit() const
{
    return m_Limit;
}

void MNSql::setLimit(const QString &Limit)
{
    m_Limit = Limit;
    fillSQl();
}

QString MNSql::TableName() const
{
    return m_TableName;
}

void MNSql::setTableName(const QString &TableName)
{
    m_TableName = TableName;
    fillSQl();
}

QString MNSql::FieldsNames() const
{
    return m_FieldsNames;
}

void MNSql::setFieldsNames(const QString &FieldsNames)
{
    m_FieldsNames = FieldsNames;
    fillSQl();
}

