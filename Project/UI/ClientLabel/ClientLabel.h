#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include "../../Controller/Controller.h"

using namespace Controller;

namespace UI {
    class ClientLabel : public QWidget {
    Q_OBJECT

    public:
        explicit ClientLabel(std::shared_ptr<ElectricScooterController> controller, const Client& user, QWidget *parent = nullptr);

    private slots:
        void viewAllScooters();
        void handleHeaderClicked(int index);
        void exitApplication();
        void cellDoubleClicked(int rowIndex, int columnIndex);
        void reserveScooter();
        void useScooter();
        void freeScooter();
        void seeMyReservedScooters();
        void seeAllFreeScooters();

    private:
        QPushButton *viewAllScootersButton;
        QTableWidget *table;
        QPushButton *exitButton;

        std::shared_ptr<QPushButton> reserveScooterButton;
        std::shared_ptr<QPushButton> useScooterButton;
        std::shared_ptr<QPushButton> freeScooterButton;
        std::shared_ptr<QPushButton> seeMyReservedScootersButton;
        std::shared_ptr<QPushButton> seeAllFreeScootersButton;

        std::shared_ptr<ElectricScooterController> scooterController;
        Client currentUser;

        void populateTable(std::vector<ElectricScooter>);
    };
}