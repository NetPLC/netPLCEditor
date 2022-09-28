#include "PLCOpenParserHandler.h"
#include <QDebug>

PLCOpenParserHandler::PLCOpenParserHandler()
{

}

void PLCOpenParserHandler::handleMessage(QtMsgType type, const QString &description, const QUrl &identifier, const QSourceLocation &sourceLocation)
{
    qDebug() << description << " " << identifier.path() << endl;
}
