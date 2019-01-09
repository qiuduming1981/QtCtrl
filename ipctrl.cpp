#include "ipctrl.h"
#include <QHBoxLayout>
#include <QDebug>

#include <QRegExpValidator>
#include <QKeyEvent>
IPEdit::IPEdit(QWidget *parent) :
    QLineEdit(parent)
{
    this->setAlignment(Qt::AlignCenter);
	QRegExp regexp1("[\\d]{3}");
    QRegExpValidator * vd = new QRegExpValidator(regexp1,this);
    this->setValidator(vd);
    connect(this,SIGNAL(textChanged(const QString &)),this,SLOT(OntextChanged(const QString &)));
}


void IPEdit::OntextChanged(const QString &str)
{
    if(str.toInt()>255)
    {
        this->setText("255");
    }
}


IPCtrl::IPCtrl(QWidget *parent) :
    QLabel(parent)
{
    this->setStyleSheet("QLabel{margin:0px;padding:0px;border:1px solid darkgray;}"
                        "QLineEdit{margin:0px;padding:0px;border:1px}");
    //border:1px solid darkgray;
    edit1 = new IPEdit;
    edit2 = new IPEdit;
    edit3 = new IPEdit;
    edit4 = new IPEdit;

	QLineEdit* ponitedit0 = new QLineEdit;
    QLineEdit* ponitedit1 = new QLineEdit;
    QLineEdit* ponitedit2 = new QLineEdit;
    QLineEdit* ponitedit3 = new QLineEdit;




    QSizePolicy ploicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    edit1->setSizePolicy(ploicy);
    edit2->setSizePolicy(ploicy);
    edit3->setSizePolicy(ploicy);
    edit4->setSizePolicy(ploicy);

    QSizePolicy pointPloicy(QSizePolicy::Fixed,QSizePolicy::Preferred);
	ponitedit0->setSizePolicy(pointPloicy);
    ponitedit1->setSizePolicy(pointPloicy);
    ponitedit2->setSizePolicy(pointPloicy);
    ponitedit3->setSizePolicy(pointPloicy);


	ponitedit0->setFixedWidth(8);
    ponitedit1->setFixedWidth(8);
    ponitedit2->setFixedWidth(8);
    ponitedit3->setFixedWidth(8);
	

	ponitedit0->setReadOnly(true);
    ponitedit1->setReadOnly(true);
    ponitedit1->setText(".");
    ponitedit2->setReadOnly(true);
    ponitedit2->setText(".");
    ponitedit3->setReadOnly(true);
    ponitedit3->setText(".");



    QHBoxLayout* lay = new QHBoxLayout;
	lay->addWidget(ponitedit0);
    lay->addWidget(edit1);
    lay->addWidget(ponitedit1);
    lay->addWidget(edit2);
    lay->addWidget(ponitedit2);
    lay->addWidget(edit3);
    lay->addWidget(ponitedit3);
    lay->addWidget(edit4);
    lay->setSpacing(0);
    lay->setMargin(1);


    this->setLayout(lay);

    ponitedit1->setFocusPolicy(Qt::NoFocus);
    ponitedit2->setFocusPolicy(Qt::NoFocus);
    ponitedit3->setFocusPolicy(Qt::NoFocus);
    edit1->installEventFilter(this);
    edit2->installEventFilter(this);
    edit3->installEventFilter(this);
    edit4->installEventFilter(this);

}

bool IPCtrl::getIPStr(QString& str)
{
    if(!isInPutComplete())
        return false;

    QString ipstr1 = edit1->text();
    QString ipstr2 = edit2->text();
    QString ipstr3 = edit3->text();
    QString ipstr4 = edit4->text();
    str.append(ipstr1);
    str.append(".");

    str.append(ipstr2);
    str.append(".");

    str.append(ipstr3);
    str.append(".");

    str.append(ipstr4);

    return true;
}
bool IPCtrl::setIP(QString ipstr)
{
	QStringList strlist = 	ipstr.split('.');
	if (strlist.size()==4)
	{
		edit1->setText(strlist.at(0));
		edit2->setText(strlist.at(1));
		edit3->setText(strlist.at(2));
		edit4->setText(strlist.at(3));
		return true;
	}
	return false;
}
bool IPCtrl::isInPutComplete()
{
    if(edit1->text().isEmpty())
        return false;
    if(edit2->text().isEmpty())
        return false;
    if(edit3->text().isEmpty())
        return false;
    if(edit4->text().isEmpty())
        return false;
    return true;
}

bool IPCtrl::eventFilter(QObject *obj, QEvent *event)
{

    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        int vk =  keyEvent->key();
        //qDebug()<<vk;
        if(vk==Qt::Key_Space)
        {
            if(obj == edit1)
            {
                edit2->setFocus();
                return true;
            }
            if(obj == edit2)
            {
                edit3->setFocus();
                return true;
            }
            if(obj == edit3)
            {
                edit4->setFocus();
                return true;
            }
        }
        else if(vk==Qt::Key_Left||vk==Qt::Key_Backspace||vk==Qt::Key_Up)
        {
            if(obj == edit2)
            {
                if(edit2->cursorPosition()==0)
                {
                    edit1->setFocus();
                    return true;
                }
            }

            if(obj == edit3)
            {
                if(edit3->cursorPosition()==0)
                {
                    edit2->setFocus();
                    return true;
                }
            }

            if(obj == edit4)
            {
                if(edit4->cursorPosition()==0)
                {
                    edit3->setFocus();
                    return true;
                }
            }
        }
        else if(vk==Qt::Key_Right||vk==Qt::Key_Down)
        {
            if(obj == edit1)
            {
                if(edit1->cursorPosition()==3||edit1->text().length()==edit1->cursorPosition())
                {
                    edit2->setFocus();
                    return true;
                }
            }

            if(obj == edit2)
            {
                if(edit2->cursorPosition()==0||edit2->text().length()==edit2->cursorPosition())
                {
                    edit3->setFocus();
                    return true;
                }
            }

            if(obj == edit3)
            {
                if(edit3->cursorPosition()==0||edit3->text().length()==edit3->cursorPosition())
                {
                    edit4->setFocus();
                    return true;
                }
            }
        }
        else if(vk>=Qt::Key_0&&vk<=Qt::Key_9)
        {

            if(obj == edit1)
            {
                if(edit1->cursorPosition()>=2&&!edit1->hasSelectedText())
                {
                    edit2->setFocus();
                    return false;
                }
            }
            if(obj == edit2)
            {
                if(edit2->cursorPosition()>=2&&!edit2->hasSelectedText())
                {
                    edit3->setFocus();
                    return false;
                }
            }
            if(obj == edit3)
            {
                if(edit3->cursorPosition()>=2&&!edit3->hasSelectedText())
                {
                    edit4->setFocus();
                    return false;
                }
            }


        }
    }
    return false;//QLabel::eventFilter(obj, event);
}
