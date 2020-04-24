#ifndef MNPATHES_H
#define MNPATHES_H

#include <QString>
#include <QDir>
#include <QStandardPaths>
class MNpathes
{
    static QString getAppDataDir();
    static bool createKotobDir();
public:
    MNpathes();
    static bool createAppDataDir();
    static QString getKotobDir();
    static bool createAppDataDirStructre();
};

#endif // MNPATHES_H
