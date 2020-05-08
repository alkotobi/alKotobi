#ifndef MNFIELD_H
#define MNFIELD_H

#include <QObject>
#include <QVariant>

static QString STRING ="QString";
static QString INT ="int";
static QString DOUBLE ="double";

class MNField : public QObject
{
    Q_OBJECT
    QString name;
    QString type;
    QVariant value;
    bool indexed=false;
    bool visible =true;
    bool readOnly =false;
    bool generated =true; // indecate if will appear in select SQL
    QString caption ="";
    int width =50;
public:
    explicit MNField(QString name,QVariant val,QObject *parent = nullptr);

    QString getName() const;
    void setName(const QString value);

    QString getType() const;
    void setType(const QString value);

    QVariant getValue() const;
    void setValue(const QVariant &value);

    bool isIndexed() const;
    void setIndexed(bool value);

    bool isVisible() const;
    void setVisible(bool value);

    bool isReadOnly() const;
    void setReadOnly(bool value);

    QString getCaption() const;
    void setCaption(const QString value);

    int getWidth() const;
    void setWidth(int value);

    bool isGenerated() const;
    void setGenerated(bool value);

signals:

};

#endif // MNFIELD_H
