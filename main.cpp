#include "mainwindow.h"

#include <QApplication>
#include "./HELPERS/log.h"
#include <QDebug>

#define STD_OUT QTextStream(stdout)

int main(int argc, char *argv[])
{

    MN_ERROR("I am sorry");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
