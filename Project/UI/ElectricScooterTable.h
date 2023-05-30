#pragma once

#include <QApplication>
#include <QDebug>
#include <QVBoxLayout>
#include <QWidget>
#include <QHeaderView>
#include <QDate>
#include <QTableWidget>
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <utility>
#include <vector>
#include "../Repository/Repository.h"

namespace UI {
    class ElectricScooterTableWidget : public QWidget {
    private:
        QTableWidget *tableWidget_;

    public:
        explicit ElectricScooterTableWidget(vector<ElectricScooter> scooters, QWidget *parent = nullptr) : QWidget(
                parent) {
            tableWidget_ = new QTableWidget(this);
            setupUi();
            populateTable(std::move(scooters));
        }

    private:
        void setupUi();
        void populateTable(vector<ElectricScooter> scooters);

    private slots:
        void handleCellClicked(int row, int column);
    };
}