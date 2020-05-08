#include "app.h"

MNApp::MNApp(QObject *parent) : QObject(parent)
{

}

void MNApp::init()
{
  MNpathes::createAppDataDirStructre();
}
