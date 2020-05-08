#ifndef APP_H
#define APP_H

#include <QObject>
#include "HELPERS/mnpathes.h"

class MNApp : public QObject
{
    Q_OBJECT
public:
    explicit MNApp(QObject *parent = nullptr);
    static void init();

signals:

};

#endif // APP_H
