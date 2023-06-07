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

    private:
        QPushButton *viewAllScootersButton;
        QTableWidget *table;
        QPushButton *exitButton;

        std::shared_ptr<ElectricScooterController> scooterController;
        Client currentUser;

        void populateTable(std::vector<ElectricScooter>);
    };
}