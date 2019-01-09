#include "widget.h"
#include "ipctrl.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    this->setFixedSize(300,200);
    IPCtrl *ipctrl = new IPCtrl(this);

    ipctrl->setGeometry(30,30,150,20);
    ipctrl->show();
}
