#include <QtWidgets/QApplication>
#include "UI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    repo Repo("melodii.txt");
    service srv(Repo);
    GUI ui(srv);

    ui.show();

    return a.exec();
}
