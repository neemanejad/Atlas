#include <qapplication.h>
#include "atlas.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Atlas window;

    /*QWidget window;
    QWidget window2;
    QWidget window3;
    auto layout = new QVBoxLayout();
    auto layout2 = new QHBoxLayout();
    auto layout3 = new QHBoxLayout();
    layout->addWidget(&window2);
    layout->addWidget(&window3);
    window.setLayout(layout);
    window.setStyleSheet("border-style: solid; border-width: 2px; border-color: black");

    window2.setLayout(layout2);
    window2.setStyleSheet("border-style: dashed; border-width: 5px; border-color: red");
    window3.setLayout(layout3);
    window3.setStyleSheet("border-style: dashed; border-width: 5px; border-color: blue");*/

    window.show();

    return app.exec();
}
