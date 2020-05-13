#include "mnkitab.h"


MNKitab::MNKitab(QString dbName, QObject *parent) : QObject(parent)
{
    this->dbName = dbName;
}
