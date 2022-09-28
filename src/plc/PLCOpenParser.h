#ifndef PLCOPENPARSER_H
#define PLCOPENPARSER_H

#include <QXmlStreamReader>
#include <QtXmlPatterns/QXmlSchema>
#include <QDomDocument>
#include "PLCOpenParserHandler.h"

class PLCOpenParser
{
public:
    PLCOpenParser();

    int setSchemaFile(const QString& file);
    int loadFile(const QString& file);

private:
    QXmlSchema schema;
    PLCOpenParserHandler schemaHandler;
    QString schemaFile;
    QDomDocument projectDom;
};

#endif // PLCOPENPARSER_H
