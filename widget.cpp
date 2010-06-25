#include "widget.h"
#include "ui_widget.h"

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

   ui->addButton->setText("fos e");
for (int i=0; i< 1 ;  i++)
   {
    // egy uj komnet
 QPushButton *button = new QPushButton("D&ownload" , this);
 ui->gridLayout->addWidget(button);
}
  //  ui->gridLayout->addItem(button);
}
