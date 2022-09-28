#include "PageMain.h"
#include "ui_PageMain.h"

PageMain::PageMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMain)
{
    ui->setupUi(this);
}

PageMain::~PageMain()
{
    delete ui;
}
