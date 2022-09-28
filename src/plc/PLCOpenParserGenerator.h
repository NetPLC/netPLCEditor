#ifndef PLCOPENPARSERGENERATOR_H
#define PLCOPENPARSERGENERATOR_H

#include <QtXmlPatterns/QAbstractMessageHandler>

class PLCOpenParserGenerator : public QAbstractMessageHandler
{
    Q_OBJECT

public:
    PLCOpenParserGenerator();

    void handleMessage(QtMsgType type,
                               const QString &description,
                               const QUrl &identifier,
                               const QSourceLocation &sourceLocation);

    static void test();
};

#endif // PLCOPENPARSERGENERATOR_H
