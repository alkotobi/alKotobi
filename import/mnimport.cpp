#include "mnimport.h"




MNImport::MNImport(QString sourceDbPAth, QObject *parent) :QObject(parent)
{
 this->dbSource =new MNDb(sourceDbPAth,sourceDbPAth,this) ;
 this->kitabOrg = new MNKitabOrg(sourceDbPAth,this);
 QString destPath = MNpathes::getKotobDir()+MNpathes::getFileName(sourceDbPAth);
 this->dbDest = new MNDb(destPath,destPath,this);
 this->kitabDest = new MNKitab(destPath,this);

}

MNImport::~MNImport()
{
    delete kitabOrg;
    delete  kitabDest;
    delete dbSource;
    delete dbDest;


}


