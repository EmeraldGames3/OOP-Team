#include "LoginPage.h"

UI::LoginPage::LoginPage(QWidget *parent) : QWidget(parent) {
    // Create the username label and text box
    usernameLabel = new QLabel("Username:");
    usernameLineEdit = new QLineEdit();

    // Create the fileName label and text box
    fileNameLabel = new QLabel("File Name:");
    fileNameLineEdit = new QLineEdit();
    fileNameLineEdit->setText("ScooterDatabase");

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
    fileNameLabel->setFixedSize(100, 30);
    fileNameLineEdit->setFixedSize(200, 30);
    loginButton->setFixedSize(100, 30);
    registerButton->setFixedSize(100, 30);

    // Create a layout for the login page
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setAlignment(Qt::AlignCenter);

    // Create the toggle buttons
    saveDataButton = new QCheckBox("Save Data");
    managerButton = new QCheckBox("Manager");

    // Create a layout for the username line
    auto *usernameLayout = new QHBoxLayout();
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameLineEdit);

    // Create a layout for the password line
    auto *passwordLayout = new QHBoxLayout();
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordLineEdit);

    // Create a fileName for the password line
    auto *fileNameLayout = new QHBoxLayout();
    fileNameLayout->addWidget(fileNameLabel);
    fileNameLayout->addWidget(fileNameLineEdit);

    // Create a layout for the buttons
    auto *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(registerButton);

    // Add the username line, password line, and buttons to the main layout
    mainLayout->addWidget(saveDataButton);
    mainLayout->addWidget(managerButton);
    mainLayout->addLayout(fileNameLayout);
    mainLayout->addLayout(usernameLayout);
    mainLayout->addLayout(passwordLayout);
    mainLayout->addLayout(buttonLayout);

    // Set the main layout for the login page widget
    setLayout(mainLayout);

    // Connect the login button signal to the appropriate slot
    connect(loginButton, &QPushButton::clicked, this, &LoginPage::handleLoginButtonClicked);

    // Connect the register button signal to the handleRegisterButtonClicked slot
    connect(registerButton, &QPushButton::clicked, this, &LoginPage::handleRegisterButtonClicked);
}

void UI::LoginPage::handleLoginButtonClicked() {
    // Get the entered username and password
    auto username = usernameLineEdit->text();
    auto password = passwordLineEdit->text();
    auto fileName = fileNameLineEdit->text();

    // Emit the loginClicked signal with the username and password
    emit loginClicked(username, password, saveDataButton->isChecked(), managerButton->isChecked(), fileName);
}

void UI::LoginPage::handleRegisterButtonClicked() {
    // Get the entered username and password
    auto username = usernameLineEdit->text();
    auto password = passwordLineEdit->text();
    auto fileName = fileNameLineEdit->text();

    // Emit the registerClicked signal with the username and password
    emit registerClicked(username, password, saveDataButton->isChecked(), managerButton->isChecked(), fileName);
}

UI::LoginPage::~LoginPage() {
    // Clean up the dynamically allocated memory
    delete usernameLabel;
    delete usernameLineEdit;
    delete passwordLabel;
    delete passwordLineEdit;
    delete loginButton;
    delete registerButton;
    delete saveDataButton;
}
