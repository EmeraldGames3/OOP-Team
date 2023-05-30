#include <QMessageBox>
#include "ElectricScooterTable.h"

using namespace UI;

void ElectricScooterTableWidget::populateTable(vector<ElectricScooter> scooters) {
    tableWidget_->setRowCount(scooters.size());

    for (int row = 0; row < scooters.size(); ++row) {
        const ElectricScooter &obj = scooters[row];

        auto *nameItem = new QTableWidgetItem(QString::fromStdString(obj.getId()));
        auto *modelItem = new QTableWidgetItem(QString::fromStdString(obj.getModel()));
        auto *dateItem = new QTableWidgetItem(QString::fromStdString(obj.getDateAsString()));
        auto *mileageItem = new QTableWidgetItem(QString::number(obj.getMileage(), 'f', 2));
        auto *locationItem = new QTableWidgetItem(QString::fromStdString(obj.getLocation()));
        auto *conditionItem = new QTableWidgetItem(QString::fromStdString(obj.getCondition()));

        tableWidget_->setItem(row, 0, nameItem);
        tableWidget_->setItem(row, 1, modelItem);
        tableWidget_->setItem(row, 2, dateItem);
        tableWidget_->setItem(row, 3, mileageItem);
        tableWidget_->setItem(row, 4, locationItem);
        tableWidget_->setItem(row, 5, conditionItem);
    }

    // Adjust column widths to fit content
    tableWidget_->resizeColumnsToContents();
}

void ElectricScooterTableWidget::setupUi() {
    auto *layout = new QVBoxLayout(this);

    tableWidget_->setColumnCount(6);
    tableWidget_->setHorizontalHeaderLabels(
            {"ID", "Model", "Commissioning Date", "Mileage", "Last Location", "Current Condition"});
    tableWidget_->horizontalHeader()->setStretchLastSection(true);
    tableWidget_->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    tableWidget_->verticalHeader()->setVisible(false);
    tableWidget_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget_->setSelectionMode(QAbstractItemView::NoSelection);
    tableWidget_->setStyleSheet("QTableView { border: none; background-color: #ffffff; }"
                                "QTableView::item { padding: 10px; }"
                                "QHeaderView::section { background-color: #f0f0f0; }");

    // Connect the cellClicked signal to the handleCellClicked slot
    connect(tableWidget_, &QTableWidget::cellClicked, this,
            &ElectricScooterTableWidget::handleCellClicked);

    layout->addWidget(tableWidget_);
    setLayout(layout);
    setStyleSheet("QWidget { background-color: #f5f5f5; }");
}

void ElectricScooterTableWidget::handleCellClicked(int row, int column) {
    // Sort the table based on the clicked column
    tableWidget_->sortByColumn(column, Qt::AscendingOrder);
}