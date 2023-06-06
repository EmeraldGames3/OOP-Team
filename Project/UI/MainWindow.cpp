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
}