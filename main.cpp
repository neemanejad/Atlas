#include <qapplication.h>
#include "atlas.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Atlas window;

    window.AddLibraryOption("Option 1");
    window.AddLibraryOption("Option 2");

    window.show();

    return app.exec();
}
