#include "PageEdit.h"
#include "ui_PageEdit.h"

PageEdit::PageEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageEdit)
{
    ui->setupUi(this);
}

PageEdit::~PageEdit()
{
    delete ui;
}
