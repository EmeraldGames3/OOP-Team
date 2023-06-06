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

void UI::MainWindow::handleLogin(const QString &username, const QString &password, bool saveData, bool manager) {
    // Hide the login page
    loginPage->hide();

    // Create and show the welcome message
    welcomeLabel = new QLabel("Welcome, " + username + "!");

    // Clear the existing layout of the central widget
    QLayout* existingLayout = centralWidget->layout();
    if (existingLayout) {
        QLayoutItem* item;
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
    QLayout* existingLayout = centralWidget->layout();
    if (existingLayout) {
        QLayoutItem* item;
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