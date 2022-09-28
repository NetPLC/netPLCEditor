#ifndef PLCOPENPARSERHANDLER_H
#define PLCOPENPARSERHANDLER_H

#include <QtXmlPatterns/QAbstractMessageHandler>

class PLCOpenParserHandler : public QAbstractMessageHandler
{
    Q_OBJECT

public:
    PLCOpenParserHandler();

    void handleMessage(QtMsgType type,
                               const QString &description,
                               const QUrl &identifier,
                               const QSourceLocation &sourceLocation);
};

#endif // PLCOPENPARSERHANDLER_H
