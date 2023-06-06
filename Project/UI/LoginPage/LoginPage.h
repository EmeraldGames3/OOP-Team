#pragma once

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>

namespace UI {
    class LoginPage : public QWidget {
    Q_OBJECT

    public:
        explicit LoginPage(QWidget *parent = nullptr);

        ~LoginPage() override;

    signals:
        void loginClicked(const QString &username, const QString &password, bool saveData, bool manager);
        void registerClicked(const QString &username, const QString &password, bool saveData, bool manager);

    private slots:
        void handleLoginButtonClicked();
        void handleRegisterButtonClicked();

    private:
        QLabel *usernameLabel;
        QLineEdit *usernameLineEdit;
        QLabel *passwordLabel;
        QLineEdit *passwordLineEdit;
        QPushButton *loginButton;
        QPushButton *registerButton;
        QCheckBox *saveDataButton;
        QCheckBox *managerButton;
    };
}
