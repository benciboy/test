#include "widget.h"
#include "ui_widget.h"
#include <stdio.h>
#include <math.h>
#include <boost/math/special_functions.hpp>

using namespace boost::math;
using namespace std;

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(gombok()));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(gombokleszed()));
    connect(ui->csuszka, SIGNAL(valueChanged(int)),this, SLOT(gombokleszed()));
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

void Widget::gombokleszed()
{
    for (int i=0; i< gomblista.size() ;  ++i)
    {
       gomblista.at(i)->setChecked(false);
    }
//     gomblista.clear();

    int komb[]={0,0,0,0,0,0};
    int index = ui->csuszka->value();
    indextocomb(index,6,48, komb);

    for (int var = 0; var < 6; ++var) {
            cout << "[" << komb[var] << "] " ;
            gomblista.at( komb[var]-1)->click();
    }

   cout << "teszt kiir " << endl;


}

void Widget::gombok()
{

    //  ui->addButton->setText("fos e");
    int maxnumber;
    if(  ui->comboBox->currentText()== "6/49" )
    {
        maxnumber = 49;
        ui->csuszka->setMaximum(13983815);
        ui->kombinacio->setMaximum(13983815);
    }
    else
    {
        maxnumber = 90;
    }
    if (gomblista.empty())
    {
        for (int i=0; i< maxnumber ;  ++i)
        {

            // normal button impl
            QPushButton *button = new QPushButton(QString::number(i+1), this);
            button->setCheckable(true);
            button->setStyleSheet(QString("QPushButton:checked{background-color: lightskyblue;}"));
            gomblista<< button;
            ui->gridLayout->addWidget(button, i/((int) sqrt(maxnumber)) ,i%(int)(sqrt(maxnumber)));

        }
    }
    else

    {
        for (int i=0; i< gomblista.size() ;  ++i)
        {
         gomblista.at(i)->~QPushButton();
        }
        gomblista.clear();
    }
}



/*
 * @arg novekvo sorrend
 * @k   hanyad rendu
 */
int Widget::combtoindex(int arg[], int k)
{
        int result = 0;
        for (int var = 0; var < k; var++) {
                if (arg[var]-1<k-var)
                        result += 0;
                else
                    result += (long int) binomial_coefficient<float>(arg[var]-1,k-var);
        }
        return result;

}

/*
 * @ind a kombinacio indexe
 * @k   hanyad rendu
 */
void Widget::indextocomb(int ind, int k, int n,  int komb[])
{

//	int orig = n;
        int subs = k;
        for (int var = 0; var < k; var++)
        {

                while ( n>=subs &&  ind < (int)binomial_coefficient<float>(n,subs) ){
                        n--;
                }
                if (n>=subs) {
                        komb[var]=n+1;
                        ind = ind - (int)binomial_coefficient<float>(n,subs);
//			cout << "ind ami maradt " << ind << endl;
                }
                else
                {
                        komb[var]=subs;
                }
                subs--;
        }
}
/*
 * fos dolgok
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
*/
