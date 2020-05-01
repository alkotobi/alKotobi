#ifndef FRMTESTS_H
#define FRMTESTS_H

#include <QMainWindow>
#include "./CORE/mnfield.h"
#include "./CORE/mnrecord.h"
#include "./HELPERS/mnpathes.h"
#include "./DB/mndb.h"

namespace Ui {
class frmTests;
}

class frmTests : public QMainWindow
{
    Q_OBJECT
    QString testLog;

public:
    explicit frmTests(QWidget *parent = nullptr);
    ~frmTests();

    QString getTestLog() const;
    void setTestLog(const QString &value);
    void logTest(QString funcName, QString logMsg, bool testResult);
    ptrMNField createFld();

private slots:
    void on_testLogg_clicked();

    void on_testCore_clicked();

    void on_testPointer_clicked();

    void on_testImport_clicked();

private:
    Ui::frmTests *ui;
};

#endif // FRMTESTS_H
