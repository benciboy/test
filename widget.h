#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QPushButton>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QList< QPushButton *> gomblista;

protected:
    void changeEvent(QEvent *e);

public slots:
    void gombok();
    void gombokleszed();
    void indextocomb(int, int, int, int arg[]);
    int combtoindex(int arg[], int);

private:
            Ui::Widget *ui;

};

#endif // WIDGET_H
