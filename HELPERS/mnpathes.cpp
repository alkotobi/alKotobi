#include "mnpathes.h"

MNpathes::MNpathes()
{

}

bool MNpathes::createAppDataDir()
{
    QStringList strs=  QStandardPaths::standardLocations(QStandardPaths::AppDataLocation);
    QDir dir;
    if( strs.count()!=0)
    if (!dir.exists(strs[0])){
        return  dir.mkpath(strs[0]);
    }

    return false;
}

QString MNpathes::getKotobDir()
{
    return getAppDataDir()+"/kotob/";
}

QString MNpathes::getAppDataDir()
{
    return  QStandardPaths::standardLocations(QStandardPaths::AppDataLocation)[0];

}

bool MNpathes::createKotobDir()
{
        QDir dir;
        return  dir.mkpath(getAppDataDir()+"/kotob/");
}

bool MNpathes::createAppDataDirStructre()
{
    createAppDataDir();
    return createKotobDir();

}

QStringList MNpathes::getFilesPathes()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    return  fileNames;
}

QString MNpathes::getFileName(QString path)
{
    QFileInfo fi(path);
    return  fi.fileName();
}

QString MNpathes::getKotobDbPath()
{
    return getKotobDir()+KotobDbName;
}
