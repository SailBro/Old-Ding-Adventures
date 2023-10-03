#include "dt.h"
#include <QApplication>
#include<QResource>
#include<QWidget>
#include<iostream>
#include"config.h"
#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     DT w;

    QResource::registerResource(":/im");

    w.show();
    return a.exec();
}
