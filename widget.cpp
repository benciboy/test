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
 //   connect(ui->csuszka, SIGNAL(valueChanged(int)),this, SLOT(kombi()));
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
    int  maxnumber = 49;
    for (int i=0; i< maxnumber ;  i++)
    {

        // normal button impl
        QPushButton *button = new QPushButton(QString::number(i+1), this);
        button->setCheckable(true);
        button->setStyleSheet(QString("QPushButton:checked{background-color: lightskyblue;}"));
        ui->gridLayout->addWidget(button, i/((int) sqrt(maxnumber)) ,i%(int)(sqrt(maxnumber)));

    }

}

/*
 * fos dolgok
 */

//QPushButton* button = new QPushButton(tr("Red Button"), this);
//button->setCheckable(true);
//button->setStyleSheet(QString("QPushButton:checked{background-color: lightskyblue;}"));
//  ui->gridLayout->addWidget(button);
// radio button impl
//    QRadioButton *radiogomb = new QRadioButton(QString::number(i+1));
//    radiogomb->setAutoExclusive(false);
//    radiogomb->setAutoFillBackground(true);
//    radiogomb->setLayoutDirection(Qt::RightToLeft);
//    ui->gridLayout->addWidget(radiogomb, i/((int) sqrt(maxnumber)) ,i%(int)(sqrt(maxnumber)));
