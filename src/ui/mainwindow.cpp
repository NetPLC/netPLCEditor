#include "mainwindow.h"
#include "ui_mainwindow.h"

static const char* spliter_sheet = "                        \
    QSplitter::handle:horizontal {                          \
        image: url(:/icons/icons/dottedline-vertical.png);  \
        width: 20px;                                         \
    }                                                       \
    QSplitter::handle:vertical {                            \
        image: url(:/icons/icons/dottedline-horizon.png);  \
        height: 20px;                                        \
    }                                                       \
    ";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
