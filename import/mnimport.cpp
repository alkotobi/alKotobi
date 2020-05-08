#include "mnimport.h"



QPointer<MNKitabOrg> MNImport::getKitabOrg() const
{
    return kitabOrg;
}

MNImport::MNImport(MNDb &db, QObject *parent) :QObject(parent)
{
 this->dbSource = &db;

}

MNImport::~MNImport()
{
    delete kitabOrg;


}


