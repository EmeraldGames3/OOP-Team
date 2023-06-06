#include "LoginPage.h"

UI::LoginPage::LoginPage(QWidget *parent) : QWidget(parent) {
    // Create the username label and text box
    usernameLabel = new QLabel("Username:");
    usernameLineEdit = new QLineEdit();

    // Create the password label and text box
    passwordLabel = new QLabel("Password:");
    passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password); // Mask the entered password

    // Create the login and register buttons
    loginButton = new QPushButton("Login");
    registerButton = new QPushButton("Register");

    // Set fixed sizes for the UI elements
    usernameLabel->setFixedSize(100, 30);
    usernameLineEdit->setFixedSize(200, 30);
    passwordLabel->setFixedSize(100, 30);
    passwordLineEdit->setFixedSize(200, 30);
    loginButton->setFixedSize(100, 30);
    registerButton->setFixedSize(100, 30);

    // Create a layout for the login page
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter); // Set alignment to center

    // Create a layout for the username line
    auto *usernameLayout = new QHBoxLayout();
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameLineEdit);

    // Create a layout for the password line
    auto *passwordLayout = new QHBoxLayout();
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordLineEdit);

    // Create a layout for the buttons
    auto *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(registerButton);

    // Add the username line, password line, and buttons to the main layout
    mainLayout->addLayout(usernameLayout);
    mainLayout->addLayout(passwordLayout);
    mainLayout->addLayout(buttonLayout);

    // Set the main layout for the login page widget
    setLayout(mainLayout);
}