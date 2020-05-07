#include "mnimport.h"



QPointer<MNKitabOrg> MNImport::getKitabOrg() const
{
    return kitabOrg;
}

MNImport::MNImport(MNDb db, QObject *parent) :QObject(parent)
{


}

MNImport::~MNImport()
{
    delete kitabOrg;


}


