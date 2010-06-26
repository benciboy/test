#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>
#include <math.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(nyomas()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::nyomas()
{

 //  ui->addButton->setText("fos e");
   int  maxnumber = 90;
for (int i=0; i< maxnumber ;  i++)
   {

    // normal button impl
    QPushButton *button = new QPushButton(QString::number(i+1), this);
    button->setCheckable(true);
   // ui->gridLayout->addWidget(button, i/((int) sqrt(maxnumber)) ,i%(int)(sqrt(maxnumber)));

    // radio button impl
    QRadioButton *radioButton = new QRadioButton(QString::number(i+1));
    radioButton->setAutoExclusive(false);
    ui->gridLayout->addWidget(radioButton, i/((int) sqrt(maxnumber)) ,i%(int)(sqrt(maxnumber)));

}
  //  ui->gridLayout->addItem(button);
}
