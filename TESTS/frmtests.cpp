#include "frmtests.h"
#include "ui_frmtests.h"

frmTests::frmTests(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::frmTests)
{
    ui->setupUi(this);

}

frmTests::~frmTests()
{
    delete ui;
}

void frmTests::logTest(QString funcName, QString logMsg, bool testResult)
{
    QString str;
    if(testResult){
        str = "✅ PASSED: ";
        setTestLog(getTestLog()+"\n"+str +funcName+": "+logMsg);

    }else{
        str = "🚨 ERROR: ";
        setTestLog(getTestLog()+"\n"+str +funcName+": "+logMsg);
    }
    ui->txtLog->setPlainText((getTestLog()));
}

ptrMNField frmTests::createFld()
{
    return new MNField("ptr","I am created in a func",this);
}

QString frmTests::getTestLog() const
{
    return testLog;
}

void frmTests::setTestLog(const QString &value)
{
    testLog = value;
}

void frmTests::on_testLogg_clicked()
{
    logTest("tesTing"," Ok",true);
}

void frmTests::on_testCore_clicked()
{
    MNRecord rcd(this);
    ptrMNField fld= createFld();
    //this->fld = fld;
    //delete this->fld;
    logTest("from func :",fld->getName(),true);
    rcd.append(fld);
    fld->setName("ALI");
    logTest("from fld :",fld->getName(),true);

    logTest("from rcd :",rcd.getField(1)->getName(),true);
    rcd.getField(1)->setName("MOhamed");
        logTest("from rcd after change :",rcd.getField(1)->getName(),true);
    logTest("from fld after rcd change :",fld->getName(),true);
    fld->setName("name");
    fld->setValue("Mohamed");
    fld = new MNField("age",25,&rcd);
    rcd.append(fld);
    rcd.append(new MNField("wight",2.5,&rcd));
    fld->setIndexed(true);
    logTest(rcd.createTableSql("nono"),"  // with index",true);
    fld->setIndexed(false);
    logTest(rcd.createTableSql("nono")," ://no index",true);
    logTest(rcd.insertSql("nono"),"  // insert",true);

    delete fld;


}

void frmTests::on_testPointer_clicked()
{

}

#include "./import/mnimport.h"
void frmTests::on_testImport_clicked()
{
    //choose the dbOriginal
    QStringList filePathes= MNpathes::getFilesPathes();
    if(filePathes.isEmpty()) return;//if no file selcted exit
    foreach(QString filePath ,filePathes){
        //connect db to path
        MNDb dbSource(filePath,MNpathes::getFileName(filePath),this);

        //create destination dataBase












        //register the book in Books db

//        MNDb dbKotob(MNpathes::getKotobDbPath(),KotobDbName,this);

        //create book words table

        // register words in main words

        // create pages range table

        //create contnents table

        // create linked books ???
    }


}
