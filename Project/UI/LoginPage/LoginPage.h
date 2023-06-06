#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace UI {
    class LoginPage : public QWidget {
    Q_OBJECT

    public:
        explicit LoginPage(QWidget *parent = nullptr);

    private:
        QLabel *usernameLabel;
        QLineEdit *usernameLineEdit;
        QLabel *passwordLabel;
        QLineEdit *passwordLineEdit;
        QPushButton *loginButton;
        QPushButton *registerButton;
    };
}
