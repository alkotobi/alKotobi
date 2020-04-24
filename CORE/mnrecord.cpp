#include "mnrecord.h"

MNRecord::MNRecord(QObject *parent) : QObject(parent)
{
    ptrMNField ptrFld =new MNField("ID",-1,this);
    record.append(ptrFld);
}

void MNRecord::append(ptrMNField ptrFld)
{
    record.append(ptrFld);
}

ptrMNField MNRecord::getField(int ind)
{
    return record[ind];
}

QString MNRecord::createTableSql(QString tableName)
{
    QString str="CREATE TABLE IF NOT EXISTS '"+tableName+"' ("
               ,str3="";
       str=str+"'ID' INTEGER PRIMARY KEY AUTOINCREMENT,";


       for(int i=1;i<this->count();i++){
           if (this->getField(i)->isGenerated()){
               ptrMNField fld=this->getField(i);
               QString strType =(fld->getType()=="QString")? "TEXT":fld->getType();
               QString str1="'"+fld->getName()+"' "+
                       strType;
               if(!(i==count()-1)){
                   str1=str1+",";
                }
               str =str+str1;
           }
       }

       str=str+");";

       for(int i=0;i<count();i++){
           if (getField(i)->isIndexed())
          str3=str3+ createIndexSql(tableName,getField(i));
       }
       return str+str3;
}

QString MNRecord::createIndexSql(QString tableName, ptrMNField fld)
{
    /*
CREATE INDEX "txt" ON "kalimat" (
    "kalima"
);
    */
    return "CREATE INDEX '"+fld->getName()+"ind"+tableName+
            "' ON '"+tableName+"' ('"+fld->getName()+"');";
}

QString MNRecord::insertSql(QString tableName)
{
    /*
  INSERT INTO table_name (column1, column2, column3, ...)
  VALUES (value1, value2, value3, ...);
       */
      QString str1=0,str2 ="",str3="";

      for(int i=1;i<this->count();i++){
           ptrMNField fld= this->getField(i);
           QString strType = fld->getType();
           if(str1!="") str1=str1+",";//coma only if have items before
           str1 =str1+fld->getName();
           if(str2!="") str2=str2+",";//coma only if have items before
           if (strType == "QString"){
               str2=str2+"'"+fld->getValue().toString()+"'";// if String ,ust add ''
           }else str2=str2+fld->getValue().toString();

      }
      str1 ="INSERT INTO "+tableName+" ("+str1+") ";
      str2 =" VALUES ("+str2+");";



      return str1 + str2;

}

int MNRecord::count()
{
    return record.count();
}
