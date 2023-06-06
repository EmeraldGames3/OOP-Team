#include <QMessageBox>
#include "MainWindow.h"

UI::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Create the central widget
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create the login page widget
    loginPage = new LoginPage(centralWidget);

    // Set the layout for the central widget
    auto *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(loginPage);
    centralWidget->setLayout(layout);

    // Connect the loginClicked signal from the login page to a slot in MainWindow
    connect(loginPage, &LoginPage::loginClicked, this, &MainWindow::handleLogin);

    // Connect the registerClicked signal from the login page to a slot in MainWindow
    connect(loginPage, &LoginPage::registerClicked, this, &MainWindow::handleRegister);
}

void UI::MainWindow::handleLogin(const QString &username, const QString &password, bool saveData, bool isManager) {
    if(saveData){
        CSVFileRepository<Client> clientRepo("Data/ClientDatabase");
        CSVFileRepository<Manager> managerRepo("Data/ManagerDatabase");
        CSVFileRepository<ElectricScooter> scooterRepo("Data/ScooterDatabase");

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

    bool loginSuccess = false;
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

    // Create and show the welcome message
    welcomeLabel = new QLabel("Welcome, " + username + "!");

    // Clear the existing layout of the central widget
    QLayout *existingLayout = centralWidget->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    // Create a new layout for the central widget
    auto *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(welcomeLabel);
    centralWidget->setLayout(layout);

    // Update the layout of the central widget
    centralWidget->layout()->update();
}

void UI::MainWindow::handleRegister(const QString &username, const QString &password, bool saveData, bool manager) {
    // Hide the login page
    loginPage->hide();

    // Create and show the welcome message
    welcomeLabel = new QLabel("Welcome, " + username + "!");

    // Clear the existing layout of the central widget
    QLayout *existingLayout = centralWidget->layout();
    if (existingLayout) {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    // Create a new layout for the central widget
    auto *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(welcomeLabel);
    centralWidget->setLayout(layout);

    // Update the layout of the central widget
    centralWidget->layout()->update();
}

UI::MainWindow::~MainWindow() {
    // Clean up the dynamically allocated memory
    delete loginPage;
    delete centralWidget;
}