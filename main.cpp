#include <qapplication.h>
#include "atlas.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Atlas window;

    window.AddLibraryOption("Option 1");
    window.AddLibraryOption("Option 2");
    window.AddLibraryOption("Option 3");
    window.AddLibraryOption("Option 4");
    window.AddLibraryOption("Option 5");
    window.AddLibraryOption("Option 6");
    window.AddLibraryOption("Option 7");
    window.AddLibraryOption("Option 8");
    window.AddLibraryOption("Option 9");
    window.AddLibraryOption("Option 10");
    window.AddLibraryOption("Option 11");
    window.AddLibraryOption("Option 12");
    window.AddLibraryOption("Option 13");
    window.AddLibraryOption("Option 14");
    window.AddLibraryOption("Option 15");
    window.AddLibraryOption("Option 16");
    window.AddLibraryOption("Option 17");
    window.AddLibraryOption("Option 18");
    window.AddLibraryOption("Option 19");
    window.AddLibraryOption("Option 20");

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
