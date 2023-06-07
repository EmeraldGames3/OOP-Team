#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>
#include "../LoginPage/LoginPage.h"
#include <memory>
#include "../../Controller/Controller.h"
#include "../../Repository/Repository.h"
#include "../ClientLabel/ClientLabel.h"
#include "../ManagerLabel/ManagerLabel.h"

using namespace Repository;
using namespace Controller;

namespace UI {
    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);

    private:
        std::unique_ptr<QWidget> centralWidget;
        std::unique_ptr<QLabel> welcomeLabel;
        std::unique_ptr<LoginPage> loginPage;

        std::unique_ptr<ManagerLabel> managerLabel;
        std::unique_ptr<ClientLabel> clientLabel;

        shared_ptr<UserController> userController;
        shared_ptr<ElectricScooterController> scooterController;

    private slots:
        void handleLogin(const QString &username, const QString &password, bool saveData, bool isManager,
                         const QString &fileName);
        void handleRegister(const QString &username, const QString &password, bool saveData, bool isManager,
                            const QString &fileName);
    };
}