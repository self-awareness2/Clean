#include <QApplication>
#include "UI/MainWidget.h"
#include <Windows.h>
int main(int argc, char *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}
