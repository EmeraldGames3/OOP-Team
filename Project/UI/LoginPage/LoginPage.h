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

    signals:
        void loginClicked(const QString &username, const QString &password, bool saveData, bool manager,
                          const QString &fileName);
        void registerClicked(const QString &username, const QString &password, bool saveData, bool manager,
                             const QString &fileName);

    private slots:
        void handleLoginButtonClicked();
        void handleRegisterButtonClicked();

    private:
        std::unique_ptr<QLabel> usernameLabel;
        std::unique_ptr<QLineEdit> usernameLineEdit;
        std::unique_ptr<QLabel> passwordLabel;
        std::unique_ptr<QLineEdit> passwordLineEdit;
        std::unique_ptr<QLabel> fileNameLabel;
        std::unique_ptr<QLineEdit> fileNameLineEdit;
        std::unique_ptr<QPushButton> loginButton;
        std::unique_ptr<QPushButton> registerButton;
        std::unique_ptr<QCheckBox> saveDataButton;
        std::unique_ptr<QCheckBox> managerButton;
    };
}
