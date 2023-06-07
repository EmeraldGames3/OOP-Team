#include <memory>
#include "Tests/TestAll.h"
#include <QApplication>
#include "Domain/Domain.h"
#include "Repository/Repository.h"
#include "Controller/Controller.h"
#include "UI/UI.h"
#include "UI/MainWindow/MainWindow.h"

using namespace Repository;
using namespace Domain;
using namespace Controller;
using namespace UI;

int main(int argc, char *argv[]) {
    testAll();

    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return QApplication::exec();
}