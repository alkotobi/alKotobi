#include "mnfield.h"

QString MNField::getName() const
{
    return name;
}

void MNField::setName(const QString value)
{
    name = value;
}

QString MNField::getType() const
{
    return type;
}

void MNField::setType(const QString value)
{
    type = value;
}

QVariant MNField::getValue() const
{
    return value;
}

void MNField::setValue(const QVariant &value)
{
    this->value = value;
}

bool MNField::isIndexed() const
{
    return indexed;
}

void MNField::setIndexed(bool value)
{
    indexed = value;
}

bool MNField::isVisible() const
{
    return visible;
}

void MNField::setVisible(bool value)
{
    visible = value;
}

bool MNField::isReadOnly() const
{
    return readOnly;
}

void MNField::setReadOnly(bool value)
{
    readOnly = value;
}

QString MNField::getCaption() const
{
    return caption;
}

void MNField::setCaption(const QString value)
{
    caption = value;
}

int MNField::getWidth() const
{
    return width;
}

void MNField::setWidth(int value)
{
    width = value;
}

bool MNField::isGenerated() const
{
    return generated;
}

void MNField::setGenerated(bool value)
{
    generated = value;
}

MNField::MNField(QString name, QVariant val, QObject *parent) : QObject(parent)
{
    this->name =name;
    this->value =val;
    this->type =val.typeToName(val.type());
}
