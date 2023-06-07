#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "../../Domain/Date/Date.h"
#include <memory>
#include <QTableWidget>
#include "../../Controller/Controller.h"
#include <QHeaderView>

using namespace Controller;

namespace UI {
    class ManagerLabel : public QWidget {
    Q_OBJECT

    public:
        explicit ManagerLabel(std::shared_ptr<ElectricScooterController> controller, QWidget *parent = nullptr);

    private slots:
        void viewAllScooters();
        void modifyScooter();
        void addScooter();
        void removeScooter();
        void handleAgeFilteredClicked();
        void handleMileageFilteredClicked();
        void handleLastLocationSearchClicked();
        void handleHeaderClicked(int index);
        void exitApplication();
        void cellDoubleClicked(int rowIndex, int columnIndex);

    private:
        QPushButton *viewAllScootersButton;
        QPushButton *modifyScooterButton;
        QPushButton *addScooterButton;
        QPushButton *removeScooterButton;
        QPushButton *ageFilteredButton;
        QPushButton *mileageFilteredButton;
        QPushButton *lastLocationSearchButton;
        QTableWidget *table;
        QPushButton *exitButton;

        std::shared_ptr<ElectricScooterController> scooterController;

        void populateTable(std::vector<ElectricScooter>);
    };
}