#ifndef PAGEMAIN_H
#define PAGEMAIN_H

#include <QWidget>

namespace Ui {
class PageMain;
}

class PageMain : public QWidget
{
    Q_OBJECT

public:
    explicit PageMain(QWidget *parent = nullptr);
    ~PageMain();

private:
    Ui::PageMain *ui;
};

#endif // PAGEMAIN_H
