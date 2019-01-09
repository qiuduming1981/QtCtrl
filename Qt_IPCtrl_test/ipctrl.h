#ifndef IPCTRL_H
#define IPCTRL_H

#include <QLabel>
//#include "ipedit.h"

#include <QLineEdit>

class IPEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit IPEdit(QWidget *parent = 0);
protected:


signals:

public slots:
    void OntextChanged(const QString &);

};

class IPCtrl : public QLabel
{
    Q_OBJECT
public:
    explicit IPCtrl(QWidget *parent = 0);
    bool getIPStr(QString&);
    bool isInPutComplete();
	bool setIP(QString ipstr);
protected:
    bool eventFilter(QObject *obj, QEvent *event);

signals:

public slots:
private:
    IPEdit* edit1;
    IPEdit* edit2;
    IPEdit* edit3;
    IPEdit* edit4;

};

#endif // IPCTRL_H
