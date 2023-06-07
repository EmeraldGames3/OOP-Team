#include "LoginPage.h"

UI::LoginPage::LoginPage(QWidget *parent)
        : QWidget(parent),
          usernameLabel(std::make_unique<QLabel>("Username:")),
          usernameLineEdit(std::make_unique<QLineEdit>()),
          fileNameLabel(std::make_unique<QLabel>("File Name:")),
          fileNameLineEdit(std::make_unique<QLineEdit>("ScooterDatabase")),
          passwordLabel(std::make_unique<QLabel>("Password:")),
          passwordLineEdit(std::make_unique<QLineEdit>()),
          loginButton(std::make_unique<QPushButton>("Login")),
          registerButton(std::make_unique<QPushButton>("Register")),
          saveDataButton(std::make_unique<QCheckBox>("Save Data")),
          managerButton(std::make_unique<QCheckBox>("Manager")) {
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

    // Create a layout for the username line
    auto *usernameLayout = new QHBoxLayout();
    usernameLayout->addWidget(usernameLabel.get());
    usernameLayout->addWidget(usernameLineEdit.get());

    // Create a layout for the password line
    auto *passwordLayout = new QHBoxLayout();
    passwordLayout->addWidget(passwordLabel.get());
    passwordLayout->addWidget(passwordLineEdit.get());
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    // Create a layout for the fileName line
    auto *fileNameLayout = new QHBoxLayout();
    fileNameLayout->addWidget(fileNameLabel.get());
    fileNameLayout->addWidget(fileNameLineEdit.get());

    // Create a layout for the buttons
    auto *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(loginButton.get());
    buttonLayout->addWidget(registerButton.get());

    // Add the username line, password line, and buttons to the main layout
    mainLayout->addWidget(saveDataButton.get());
    mainLayout->addWidget(managerButton.get());
    mainLayout->addLayout(fileNameLayout);
    mainLayout->addLayout(usernameLayout);
    mainLayout->addLayout(passwordLayout);
    mainLayout->addLayout(buttonLayout);

    // Set the main layout for the login page widget
    setLayout(mainLayout);

    // Connect the login button signal to the appropriate slot
    connect(loginButton.get(), &QPushButton::clicked, this,
            &LoginPage::handleLoginButtonClicked);

    // Connect the register button signal to the handleRegisterButtonClicked slot
    connect(registerButton.get(), &QPushButton::clicked, this,
            &LoginPage::handleRegisterButtonClicked);
}

void UI::LoginPage::handleLoginButtonClicked() {
    // Get the entered username and password
    auto username = usernameLineEdit->text();
    auto password = passwordLineEdit->text();
    auto fileName = fileNameLineEdit->text();

    // Emit the loginClicked signal with the username and password
    emit loginClicked(username, password, saveDataButton->isChecked(),
                      managerButton->isChecked(), fileName);
}

void UI::LoginPage::handleRegisterButtonClicked() {
    // Get the entered username and password
    auto username = usernameLineEdit->text();
    auto password = passwordLineEdit->text();
    auto fileName = fileNameLineEdit->text();

    // Emit the registerClicked signal with the username and password
    emit registerClicked(username, password, saveDataButton->isChecked(),
                         managerButton->isChecked(), fileName);
}