#include <memory>
#include "Tests/TestAll.h"
#include <QApplication>
#include "Domain/Domain.h"
#include "Repository/Repository.h"
#include "Controller/Controller.h"
#include "UI/UI.h"

using namespace Repository;
using namespace Domain;
using namespace Controller;
using namespace UI;

int main(int argc, char *argv[]) {
    testAll();

    QApplication app(argc, argv);

    CSVFileRepository<Client> clientRepo("Data/ClientDatabase");
    CSVFileRepository<Manager> managerRepo("Data/ManagerDatabase");
    CSVFileRepository<ElectricScooter> scooterRepo("Data/ScooterDatabase");

    ElectricScooterController electricScooterController(
            make_shared<CSVFileRepository<ElectricScooter>>(scooterRepo));
    UserController userController(make_shared<CSVFileRepository<Client>>(clientRepo),
                                  make_shared<CSVFileRepository<Manager>>(managerRepo));

    ElectricScooterTableWidget objectTableWidget(electricScooterController.getAll());
    objectTableWidget.setGeometry(100, 100, 650, 600);
    objectTableWidget.show();

    return QApplication::exec();
}