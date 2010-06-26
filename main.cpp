#include <QtGui/QApplication>
#include "widget.h"


int main(int argc, char *argv[])
{
    // extra comment
    QApplication a(argc, argv);
    Widget w;
#if defined(Q_WS_S60) || defined(Q_WS_MAEMO_5)
    w.showMaximized();
#else
    w.show();
#endif
    return a.exec();
}
