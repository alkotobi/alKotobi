#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./TESTS/frmtests.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    frmTests tst;

private slots:
    void on_testing_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
