#include "mainwindow.h"

#include <QApplication>
#include "./HELPERS/log.h"
#include "./CORE/app.h"
#include <QDebug>

#define STD_OUT QTextStream(stdout)

int main(int argc, char *argv[])
{
    qWarning("hahahahah");
    //QMetaObject
    MNApp::init();
    MN_SUCCESS("I am sorry");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
