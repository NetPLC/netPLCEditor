#ifndef PAGEEDIT_H
#define PAGEEDIT_H

#include <QWidget>

namespace Ui {
class PageEdit;
}

class PageEdit : public QWidget
{
    Q_OBJECT

public:
    explicit PageEdit(QWidget *parent = nullptr);
    ~PageEdit();

private:
    Ui::PageEdit *ui;
};

#endif // PAGEEDIT_H
