/**
 * @file main.cpp
 * @brief main
 * @author Han Pengfei <penpghei@qq.com>
 */

#include <QApplication>
#include <QTextCodec>
#include <QDesktopWidget>
#include <QDir>
#include <QFontDatabase>
#include <QSplashScreen>
#include <QPixmap>
#include "mainwindow.h"
#include "PLCOpenParserGenerator.h"

#include <stdint.h>
#include "ConfigVersion.h"


static int mainShowInfo()
{
    printf("\n############################################ \n");
    printf("%s Info: \n", AP_BUILD_NAME);
    printf("Version: %s \n", AP_REPO_VERSION);
    printf("FullVersion: %s \n", AP_VERSION);
    printf("ReleaseTime: %s \n", AP_REPO_DATE);
    printf("ReleaseHash: %s \n", AP_REPO_HASH);
    printf("BuildTime: %s \n", AP_BUILD_TIMESTAMP);
    return 0;
}

int main(int argc, char **argv)
{
#ifdef __WINNT__
    if(AttachConsole(ATTACH_PARENT_PROCESS)) {
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
#endif

    mainShowInfo();

    PLCOpenParserGenerator::test();

    QApplication a(argc, argv);
    QPixmap pixmap(":/icons/icons/autobio_logo.jpg");
    QSplashScreen splash(pixmap);

    splash.show();
    a.processEvents();

    MainWindow mainWin;
    mainWin.showMaximized();

    return a.exec();
}
