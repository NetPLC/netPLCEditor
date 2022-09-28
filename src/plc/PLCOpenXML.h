#ifndef PLCOPENXML_H
#define PLCOPENXML_H

#include <QObject>

class PLCOpenXML : public QObject
{
    Q_OBJECT

public:
    explicit PLCOpenXML(QObject *parent = nullptr);
};

#endif // PLCOPENXML_H
