#ifndef MNPATHES_H
#define MNPATHES_H

#include <QString>
#include <QDir>
#include <QStandardPaths>
#include <QFileDialog>

static const QString KotobDbName="kotob.db";
class MNpathes
{
    static QString getAppDataDir();
    static bool createKotobDir();
public:
    MNpathes();
    static bool createAppDataDir();
    static QString getKotobDir();
    static bool createAppDataDirStructre();
    static QStringList getFilesPathes();
    static QString getFileName(QString path);
    static QString getKotobDbPath();
};

#endif // MNPATHES_H
