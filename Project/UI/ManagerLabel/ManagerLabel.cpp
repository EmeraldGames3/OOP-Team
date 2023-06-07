#include <QMainWindow>
#include "ManagerLabel.h"
#include <QDialog>
#include <QLineEdit>
#include <utility>
#include <QMessageBox>

UI::ManagerLabel::ManagerLabel(std::shared_ptr<ElectricScooterController> controller, QWidget *parent)
        : scooterController(std::move(controller)), QWidget(parent) {
    // Create the buttons
    viewAllScootersButton = new QPushButton("View All Scooters");
    modifyScooterButton = new QPushButton("Modify Scooter");
    addScooterButton = new QPushButton("Add Scooter");
    removeScooterButton = new QPushButton("Remove Scooter");
    ageFilteredButton = new QPushButton("Age Filtered");
    mileageFilteredButton = new QPushButton("Mileage Filtered");
    lastLocationSearchButton = new QPushButton("Last Location Search");

    // Create the table widget
    table = new QTableWidget();
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels(
            {"ID", "Model", "Commissioning Date", "Mileage", "Last Location", "Current Condition"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Set stretch mode
    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    table->setStyleSheet("QTableView { border: none; background-color: #ffffff; }"
                         "QTableView::item { padding: 10px; }"
                         "QHeaderView::section { background-color: #f0f0f0; }");

    // Create a layout for the buttons
    auto buttonLayout = new QVBoxLayout();
    buttonLayout->addWidget(viewAllScootersButton);
    buttonLayout->addWidget(modifyScooterButton);
    buttonLayout->addWidget(addScooterButton);
    buttonLayout->addWidget(removeScooterButton);
    buttonLayout->addWidget(ageFilteredButton);
    buttonLayout->addWidget(mileageFilteredButton);
    buttonLayout->addWidget(lastLocationSearchButton);

    // Create a layout for the table and buttons
    auto mainLayout = new QVBoxLayout();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(table);

    // Set the layout for the ManagerLabel widget
    setLayout(mainLayout);

    // Connect the button signals to their respective slots
    connect(viewAllScootersButton, &QPushButton::clicked, this, &ManagerLabel::viewAllScooters);
    connect(modifyScooterButton, &QPushButton::clicked, this, &ManagerLabel::modifyScooter);
    connect(addScooterButton, &QPushButton::clicked, this, &ManagerLabel::addScooter);
    connect(removeScooterButton, &QPushButton::clicked, this, &ManagerLabel::removeScooter);
    connect(ageFilteredButton, &QPushButton::clicked, this, &ManagerLabel::handleAgeFilteredClicked);
    connect(mileageFilteredButton, &QPushButton::clicked, this, &ManagerLabel::handleMileageFilteredClicked);
    connect(lastLocationSearchButton, &QPushButton::clicked, this, &ManagerLabel::handleLastLocationSearchClicked);

    // Connect the headerClicked signal to the handleHeaderClicked slot
    connect(table->horizontalHeader(), &QHeaderView::sectionClicked, this, &ManagerLabel::handleHeaderClicked);
}

void UI::ManagerLabel::handleHeaderClicked(int index) {
    // Sort the table based on the clicked column
    switch (index) {
        case 0: // Sort by ID using default string comparison
            table->sortItems(index, Qt::AscendingOrder);
            break;
        case 1: { // Sort by Model
            std::vector<ElectricScooter> sortedScooters = scooterController->modelSorted();
            populateTable(sortedScooters);
            break;
        }
        case 2: { // Sort by Commissioning Date
            std::vector<ElectricScooter> sortedScooters = scooterController->ageSorted();
            populateTable(sortedScooters);
            break;
        }
        case 3: { // Sort by Mileage
            std::vector<ElectricScooter> sortedScooters = scooterController->mileageSorted();
            populateTable(sortedScooters);
            break;
        }
        case 4: { // Sort by Last Location
            std::vector<ElectricScooter> sortedScooters = scooterController->lastLocationSorted();
            populateTable(sortedScooters);
            break;
        }
        case 5: { // Sort by Current Condition
            std::vector<ElectricScooter> sortedScooters = scooterController->currentConditionSorted();
            populateTable(sortedScooters);
            break;
        }
        default: // Sort by other columns using default string comparison
            table->sortItems(index, Qt::AscendingOrder);
            break;
    }
}

void UI::ManagerLabel::viewAllScooters() {
    // Get all scooters from the controller
    std::vector<ElectricScooter> allScooters = scooterController->getAll();

    // Populate the table with the scooters
    populateTable(allScooters);

    // Show the table
    table->show();
}

void UI::ManagerLabel::populateTable(vector<ElectricScooter> scooters) {
    // Clear the existing table data
    table->clearContents();
    table->setRowCount(0);

    // Set the number of rows in the table
    int rowCount = static_cast<int>(scooters.size());
    table->setRowCount(rowCount);

    // Populate the table with scooter data
    for (int row = 0; row < rowCount; ++row) {
        const ElectricScooter &scooter = scooters[row];

        // Set the data for each column
        table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(scooter.getId())));
        table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(scooter.getModel())));
        table->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(scooter.getDateAsString())));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(scooter.getMileage())));
        table->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(scooter.getLocation())));
        table->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(scooter.getCondition())));
    }
}

void UI::ManagerLabel::handleLastLocationSearchClicked() {
    // Create a dialog for entering the location search query
    QDialog dialog(this);
    QVBoxLayout dialogLayout(&dialog);
    QLabel searchLabel("Enter Location Search Query:");
    QLineEdit searchLineEdit;
    QPushButton cancelButton("Cancel");
    QPushButton searchButton("Search");

    // Add widgets to the dialog layout
    dialogLayout.addWidget(&searchLabel);
    dialogLayout.addWidget(&searchLineEdit);
    dialogLayout.addWidget(&cancelButton);
    dialogLayout.addWidget(&searchButton);

    // Connect the button signals to their respective slots
    connect(&cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(&searchButton, &QPushButton::clicked, [&]() {
        // Retrieve the search query from the line edit
        QString searchQuery = searchLineEdit.text();

        // Search for scooters based on the location query
        std::vector<ElectricScooter> searchResults = scooterController->lastLocationSearch(searchQuery.toStdString());

        // Populate the table with the search results
        populateTable(searchResults);

        // Close the dialog
        dialog.accept();
    });

    // Open the dialog
    dialog.exec();
}

void UI::ManagerLabel::handleMileageFilteredClicked() {
    // Create a dialog for entering the mileage filter value
    QDialog dialog(this);
    QVBoxLayout dialogLayout(&dialog);
    QLabel filterLabel("Enter Mileage Filter:");
    QLineEdit filterLineEdit;
    QPushButton cancelButton("Cancel");
    QPushButton filterButton("Filter");

    // Add widgets to the dialog layout
    dialogLayout.addWidget(&filterLabel);
    dialogLayout.addWidget(&filterLineEdit);
    dialogLayout.addWidget(&cancelButton);
    dialogLayout.addWidget(&filterButton);

    // Connect the button signals to their respective slots
    connect(&cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(&filterButton, &QPushButton::clicked, [&]() {
        // Retrieve the filter value from the line edit
        QString filterText = filterLineEdit.text();
        bool conversionOk = false;
        float filterValue = filterText.toFloat(&conversionOk);

        // Check if the filter value is a valid float
        if (conversionOk) {
            // Filter the scooters based on the mileage filter
            std::vector<ElectricScooter> filteredScooters = scooterController->mileageFiltered(filterValue);

            // Populate the table with the filtered scooters
            populateTable(filteredScooters);

            // Close the dialog
            dialog.accept();
        } else {
            // Show an error message for invalid filter value
            QMessageBox::critical(this, "Invalid Filter Value", "Please enter a valid mileage value");
        }
    });

    // Open the dialog
    dialog.exec();
}

void UI::ManagerLabel::modifyScooter() {
    // Get the selected row in the table
    int selectedRow = table->currentRow();

    // Ensure a row is selected
    if (selectedRow >= 0) {
        // Get the ID of the selected scooter
        QTableWidgetItem *idItem = table->item(selectedRow, 0);
        QString id = idItem->text();

        // Search for the scooter with the corresponding ID
        ElectricScooter *scooter = nullptr;
        std::vector<ElectricScooter> allScooters = scooterController->getAll();
        for (auto &s: allScooters) {
            if (s.getId() == id.toStdString()) {
                scooter = &s;
                break;
            }
        }

        // Open a dialog for modifying the scooter
        QDialog dialog(this);
        QVBoxLayout dialogLayout(&dialog);
        QLabel idLabel("ID:");
        QLineEdit idLineEdit(id);
        QLabel modelLabel("Model:");
        QLineEdit modelLineEdit;
        QLabel dateLabel("Commissioning Date:");
        QLineEdit dateLineEdit;
        QLabel mileageLabel("Mileage:");
        QLineEdit mileageLineEdit;
        QLabel locationLabel("Last Location:");
        QLineEdit locationLineEdit;
        QLabel conditionLabel("Current Condition:");
        QLineEdit conditionLineEdit;
        QPushButton cancelButton("Cancel");
        QPushButton saveButton("Save");

        // Set the initial values in the dialog
        idLineEdit.setReadOnly(true);

        // Retrieve the current values for the selected scooter
        if (scooter != nullptr) {
            modelLineEdit.setText(QString::fromStdString(scooter->getModel()));
            dateLineEdit.setText(QString::fromStdString(scooter->getDateAsString()));
            mileageLineEdit.setText(QString::number(scooter->getMileage()));
            locationLineEdit.setText(QString::fromStdString(scooter->getLocation()));
            conditionLineEdit.setText(QString::fromStdString(scooter->getCondition()));
        }

        // Add widgets to the dialog layout
        dialogLayout.addWidget(&idLabel);
        dialogLayout.addWidget(&idLineEdit);
        dialogLayout.addWidget(&modelLabel);
        dialogLayout.addWidget(&modelLineEdit);
        dialogLayout.addWidget(&dateLabel);
        dialogLayout.addWidget(&dateLineEdit);
        dialogLayout.addWidget(&mileageLabel);
        dialogLayout.addWidget(&mileageLineEdit);
        dialogLayout.addWidget(&locationLabel);
        dialogLayout.addWidget(&locationLineEdit);
        dialogLayout.addWidget(&conditionLabel);
        dialogLayout.addWidget(&conditionLineEdit);
        dialogLayout.addWidget(&cancelButton);
        dialogLayout.addWidget(&saveButton);

        // Connect the button signals to their respective slots
        connect(&cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);
        connect(&saveButton, &QPushButton::clicked, [&]() {
            // Update the scooter with the modified values
            if (scooter != nullptr) {
                scooterController->updateModel(modelLineEdit.text().toStdString(), scooter->getId());
                scooterController->updateDate(dateLineEdit.text().toStdString(), scooter->getId());
                scooterController->updateMileage(mileageLineEdit.text().toFloat(), scooter->getId());
                scooterController->updateLocation(locationLineEdit.text().toStdString(), scooter->getId());
                scooterController->updateCondition(conditionLineEdit.text().toStdString(), scooter->getId());
            }

            // Refresh the table
            std::vector<ElectricScooter> sortedScooters = scooterController->modelSorted();
            populateTable(sortedScooters);

            // Close the dialog
            dialog.accept();
        });

        // Open the dialog
        dialog.exec();
    }
}

void UI::ManagerLabel::addScooter() {
    // Create a dialog for adding a new scooter
    QDialog dialog(this);
    QVBoxLayout dialogLayout(&dialog);
    QLabel idLabel("ID:");
    QLineEdit idLineEdit;
    QLabel modelLabel("Model:");
    QLineEdit modelLineEdit;
    QLabel dateLabel("Commissioning Date:");
    QLineEdit dateLineEdit;
    QLabel mileageLabel("Mileage:");
    QLineEdit mileageLineEdit;
    QLabel locationLabel("Last Location:");
    QLineEdit locationLineEdit;
    QLabel conditionLabel("Current Condition:");
    QLineEdit conditionLineEdit;
    QPushButton cancelButton("Cancel");
    QPushButton saveButton("Save");

    // Add widgets to the dialog layout
    dialogLayout.addWidget(&idLabel);
    dialogLayout.addWidget(&idLineEdit);
    dialogLayout.addWidget(&modelLabel);
    dialogLayout.addWidget(&modelLineEdit);
    dialogLayout.addWidget(&dateLabel);
    dialogLayout.addWidget(&dateLineEdit);
    dialogLayout.addWidget(&mileageLabel);
    dialogLayout.addWidget(&mileageLineEdit);
    dialogLayout.addWidget(&locationLabel);
    dialogLayout.addWidget(&locationLineEdit);
    dialogLayout.addWidget(&conditionLabel);
    dialogLayout.addWidget(&conditionLineEdit);
    dialogLayout.addWidget(&cancelButton);
    dialogLayout.addWidget(&saveButton);

    // Connect the button signals to their respective slots
    connect(&cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(&saveButton, &QPushButton::clicked, [&]() {
        // Create a new scooter with the entered details
        ElectricScooter newScooter;
        newScooter.setId(idLineEdit.text().toStdString());
        newScooter.setModel(modelLineEdit.text().toStdString());
        newScooter.setDate(dateLineEdit.text().toStdString());
        newScooter.setMileage(mileageLineEdit.text().toFloat());
        newScooter.setLocation(locationLineEdit.text().toStdString());
        newScooter.setCondition(conditionLineEdit.text().toStdString());

        // Add the new scooter to the controller
        try {
            scooterController->add(newScooter.getId(), newScooter.getModel(), newScooter.getDateAsString(),
                                   newScooter.getMileage(), newScooter.getLocation(), newScooter.getCondition());
        } catch (const std::exception &ex) {
            QMessageBox::critical(this, "Invalid Arguments", ex.what());
            return;
        }

        // Refresh the table
        populateTable(scooterController->getAll());

        // Close the dialog
        dialog.accept();
    });

    // Open the dialog
    dialog.exec();
}

void UI::ManagerLabel::removeScooter() {
    // Get the selected row in the table
    int selectedRow = table->currentRow();

    // Ensure a row is selected
    if (selectedRow >= 0) {
        // Get the ID of the selected scooter
        QTableWidgetItem *idItem = table->item(selectedRow, 0);
        QString id = idItem->text();

        // Confirm the removal with a message box
        QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Confirm Removal", "Are you sure you want to remove this scooter?",
                                                                         QMessageBox::Yes | QMessageBox::No);
        if (confirmation == QMessageBox::Yes) {
            try {
                // Remove the scooter from the controller
                scooterController->remove(id.toStdString());

                // Refresh the table
                populateTable(scooterController->getAll());

                // Show a success message
                QMessageBox::information(this, "Removal Successful", "Scooter removed successfully.");
            } catch (const std::exception &ex) {
                // Show an error message if removal fails
                QMessageBox::critical(this, "Removal Error", ex.what());
            }
        }
    }
}

void UI::ManagerLabel::handleAgeFilteredClicked() {
    // Create a dialog for entering the age filter value
    QDialog dialog(this);
    QVBoxLayout dialogLayout(&dialog);
    QLabel filterLabel("Enter Age Filter (yyyy-mm-dd):");
    QLineEdit filterLineEdit;
    QPushButton cancelButton("Cancel");
    QPushButton filterButton("Filter");

    // Add widgets to the dialog layout
    dialogLayout.addWidget(&filterLabel);
    dialogLayout.addWidget(&filterLineEdit);
    dialogLayout.addWidget(&cancelButton);
    dialogLayout.addWidget(&filterButton);

    // Connect the button signals to their respective slots
    connect(&cancelButton, &QPushButton::clicked, &dialog, &QDialog::reject);
    connect(&filterButton, &QPushButton::clicked, [&]() {
        // Retrieve the filter value from the line edit
        QString filterText = filterLineEdit.text();

        // Check if the filter value is in the correct format
        QRegularExpression regex(R"(\d{4}-\d{2}-\d{2})");
        QRegularExpressionMatch match = regex.match(filterText);

        if (match.hasMatch()) {
            // Extract the year, month, and day from the filter value
            QString year = filterText.mid(0, 4);
            QString month = filterText.mid(5, 2);
            QString day = filterText.mid(8, 2);

            // Convert the filter values to integers
            int filterYear = year.toInt();
            int filterMonth = month.toInt();
            int filterDay = day.toInt();

            // Check if the filter values are valid
            if (filterYear >= 1900 && filterYear <= 9999 &&
                filterMonth >= 1 && filterMonth <= 12 &&
                filterDay >= 1 && filterDay <= 31) {
                // Create a custom Date object with the filter values
                Date value(filterYear, filterMonth, filterDay);

                // Filter the scooters based on the age filter
                std::vector<ElectricScooter> filteredScooters = scooterController->ageFiltered(value);

                // Populate the table with the filtered scooters
                populateTable(filteredScooters);

                // Close the dialog
                dialog.accept();
            } else {
                // Show an error message for invalid filter values
                QMessageBox::critical(this, "Invalid Filter Value", "Please enter a valid date in the format: yyyy-mm-dd");
            }
        } else {
            // Show an error message for invalid filter format
            QMessageBox::critical(this, "Invalid Filter Format", "Please enter the filter value in the format: yyyy-mm-dd");
        }
    });

    // Open the dialog
    dialog.exec();
}