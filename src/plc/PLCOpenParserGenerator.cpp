#include "PLCOpenParserGenerator.h"
#include <QDebug>
#include <QUrl>
#include <QXmlStreamReader>
#include <QtXmlPatterns/QXmlSchema>
#include <QDomDocument>
#include <QFile>

PLCOpenParserGenerator::PLCOpenParserGenerator()
{

}

void PLCOpenParserGenerator::handleMessage(QtMsgType type, const QString &description,
                                           const QUrl &identifier, const QSourceLocation &sourceLocation)
{
    qDebug() << description << " " << identifier.path() << endl;
}

void PLCOpenParserGenerator::test()
{
    PLCOpenParserGenerator plcgen;
    QUrl languageFile = QUrl::fromLocalFile("tc6_xml_v201.xsd");
    QXmlSchema languageSchema;
    languageSchema.setMessageHandler(&plcgen);
    languageSchema.load(languageFile);
    bool valid = languageSchema.isValid();

    QDomDocument doc("mydocument");
    QFile file("./Hello/plc.xml");
    if (!file.open(QIODevice::ReadOnly))
        return;

    QByteArray data = file.readAll();

     qDebug() << data;

    if (!doc.setContent(data)) {
        file.close();
        return;
    }
    file.close();

    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            qDebug() << qPrintable(e.tagName()) << endl; // the node really is an element.
        }
        n = n.nextSibling();
    }

    if(valid)
    {
        qDebug() << "valid" << endl;
    }
}
