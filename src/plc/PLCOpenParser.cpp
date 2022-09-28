#include "PLCOpenParser.h"
#include "PLCOpenTypes.h"
#include <QUrl>
#include <QXmlStreamReader>
#include <QtXmlPatterns/QXmlSchema>
#include <QDomDocument>
#include <QFile>
#include <unistd.h>

static const PLCopen::DisplayVar plcOpenVarTypes[] =
{
    {"Local",    "localVars"},
    {"Temp",     "tempVars"},
    {"Input",    "inputVars"},
    {"Output",   "outputVars"},
    {"InOut",    "inOutVars"},
    {"External", "externalVars"},
    {"Global",   "globalVars"},
    {"Access",   "accessVars"},
    {NULL, NULL},
};

static const PLCopen::DisplayVar plcOpenSearchVarTypes[] =
{
    {"inputVars",    "var_input"},
    {"outputVars",   "var_output"},
    {"inOutVars",    "var_inout"},
    {NULL, NULL},
};

static const char* plcOpenVarOrder[] =
{
    "Local", "Temp", "Input", "Output", "InOut", "External", "Global", "Access",
    NULL,
};

static const char* plcOpenFilterAddressModel = "(%%[IQM](?:[XBWDL])?)(%s)((?:/\.[0-9]+)*)";

static const char* plcOpenPOUProjectTemplate = ":/data/POU_Project_Template.xml";


PLCOpenParser::PLCOpenParser()
{
    schema.setMessageHandler(&schemaHandler);
}

int PLCOpenParser::setSchemaFile(const QString &file)
{
    schemaFile = file;
    return 0;
}

int PLCOpenParser::loadFile(const QString &file)
{
    QDomDocument doc("mydocument");
    QFile proFile(file);
    if (!proFile.open(QIODevice::ReadOnly))
        return -1;

    schema.load()
    QByteArray data = proFile.readAll();
     qDebug() << data;

    if (!projectDom.setContent(data)) {
        proFile.close();
        return -1;
    }
    proFile.close();
}
