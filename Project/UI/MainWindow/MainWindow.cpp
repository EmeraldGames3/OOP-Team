#include <QMessageBox>
#include "MainWindow.h"

UI::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create the central widget
    centralWidget = std::make_unique<QWidget>(this);
    setCentralWidget(centralWidget.get());

    // Create the login page widget
    loginPage = std::make_unique<LoginPage>(centralWidget.get());

    // Set the layout for the central widget
    auto *layout = new QVBoxLayout(centralWidget.get());
    layout->addWidget(loginPage.get());
    centralWidget->setLayout(layout);

    // Connect the loginClicked signal from the login page to a slot in MainWindow
    connect(loginPage.get(), &LoginPage::loginClicked, this, &MainWindow::handleLogin);

    // Connect the registerClicked signal from the login page to a slot in MainWindow
    connect(loginPage.get(), &LoginPage::registerClicked, this, &MainWindow::handleRegister);
}


void UI::MainWindow::handleLogin(const QString &username, const QString &password, bool saveData, bool isManager,
                                 const QString &fileName) {
    if(saveData){
        CSVFileRepository<Client> clientRepo("Data/ClientDatabase");
        CSVFileRepository<Manager> managerRepo("Data/ManagerDatabase");
        CSVFileRepository<ElectricScooter> scooterRepo("Data/" + fileName.toStdString());

        scooterController = make_shared<ElectricScooterController>(
                make_shared<CSVFileRepository<ElectricScooter>>(scooterRepo));
        userController = make_shared<UserController>(make_shared<CSVFileRepository<Client>>(clientRepo),
                                                     make_shared<CSVFileRepository<Manager>>(managerRepo));

    } else{
        InMemoryRepository<Client> clientRepo("Data/ClientDatabase");
        InMemoryRepository<Manager> managerRepo("Data/ManagerDatabase");
        InMemoryRepository<ElectricScooter> scooterRepo("Data/ScooterDatabase");

        scooterController = make_shared<ElectricScooterController>(
                make_shared<InMemoryRepository<ElectricScooter>>(scooterRepo));
        userController = make_shared<UserController>(make_shared<InMemoryRepository<Client>>(clientRepo),
                                                     make_shared<InMemoryRepository<Manager>>(managerRepo));
    }

    bool loginSuccess;
    if (isManager) {
        loginSuccess = userController->checkManagerAccount(username.toStdString(), password.toStdString());
    } else {
        loginSuccess = userController->checkClientAccount(username.toStdString(), password.toStdString());
    }

    if (!loginSuccess) {
        QMessageBox::critical(this, "Login Error", "Incorrect username or password.");
        return;
    }

    // Hide the login page
    loginPage->hide();

    // Create the manager and client labels
    managerLabel = std::make_unique<UI::ManagerLabel>(scooterController);
//    clientLabel = std::make_unique<UI::ClientLabel>(scooterController);
    clientLabel = std::make_unique<UI::ClientLabel>();

    // Clear the existing layout of the central widget
    auto *existingLayout = centralWidget->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    // Create a new layout for the central widget
    auto layout = std::make_unique<QVBoxLayout>(centralWidget.get());

    if (isManager) {
        // Show the manager label
        layout->addWidget(managerLabel.get());
    } else {
        // Show the client label
        layout->addWidget(clientLabel.get());
    }

    centralWidget->setLayout(layout.get());

    // Update the layout of the central widget
    centralWidget->layout()->update();
}

void UI::MainWindow::handleRegister(const QString &username, const QString &password, bool saveData, bool isManager,
                                    const QString &fileName) {
    if(saveData){
        CSVFileRepository<Client> clientRepo("Data/ClientDatabase");
        CSVFileRepository<Manager> managerRepo("Data/ManagerDatabase");
        CSVFileRepository<ElectricScooter> scooterRepo("Data/" + fileName.toStdString());

        scooterController = make_shared<ElectricScooterController>(
                make_shared<CSVFileRepository<ElectricScooter>>(scooterRepo));
        userController = make_shared<UserController>(make_shared<CSVFileRepository<Client>>(clientRepo),
                                                     make_shared<CSVFileRepository<Manager>>(managerRepo));

    } else{
        InMemoryRepository<Client> clientRepo("Data/ClientDatabase");
        InMemoryRepository<Manager> managerRepo("Data/ManagerDatabase");
        InMemoryRepository<ElectricScooter> scooterRepo("Data/" + fileName.toStdString());

        scooterController = make_shared<ElectricScooterController>(
                make_shared<InMemoryRepository<ElectricScooter>>(scooterRepo));
        userController = make_shared<UserController>(make_shared<InMemoryRepository<Client>>(clientRepo),
                                                     make_shared<InMemoryRepository<Manager>>(managerRepo));
    }

    bool registerSuccess;
    if (isManager) {
        registerSuccess = !userController->findManager(username.toStdString());
    } else {
        registerSuccess = !userController->findClient(username.toStdString());
    }

    if (!registerSuccess) {
        QMessageBox::critical(this, "Register Error", "Username is already taken");
        return;
    }

    if(isManager){
        userController->addManager(username.toStdString(), password.toStdString());
    } else{
        userController->addClient(username.toStdString(), password.toStdString());
    }

    // Hide the login page
    loginPage->hide();

    // Create the manager and client labels
    managerLabel = std::make_unique<UI::ManagerLabel>(scooterController);
//    clientLabel = std::make_unique<UI::ClientLabel>(scooterController);
    clientLabel = std::make_unique<UI::ClientLabel>();

    // Clear the existing layout of the central widget
    auto *existingLayout = centralWidget->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    // Create a new layout for the central widget
    auto layout = std::make_unique<QVBoxLayout>(centralWidget.get());

    if (isManager) {
        // Show the manager label
        layout->addWidget(managerLabel.get());
    } else {
        // Show the client label
        layout->addWidget(clientLabel.get());
    }

    centralWidget->setLayout(layout.get());

    // Update the layout of the central widget
    centralWidget->layout()->update();
}