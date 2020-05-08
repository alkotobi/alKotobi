#include "mnkitab.h"


MNKitab::MNKitab(MNDb *kitabDb,QObject *parent) : QObject(parent)
{
    this->dbKitab = kitabDb;
}
