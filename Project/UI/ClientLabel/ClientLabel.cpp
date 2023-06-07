#include "ClientLabel.h"
#include <QHeaderView>
#include <QMenu>
#include <QApplication>
#include <QMessageBox>

UI::ClientLabel::ClientLabel(std::shared_ptr<ElectricScooterController> controller, const Client &user, QWidget *parent)
        : scooterController(std::move(controller)), currentUser(user), QWidget(parent) {
    // Create the buttons
    viewAllScootersButton = new QPushButton("View All Scooters");
    exitButton = new QPushButton("Exit", this);
    reserveScooterButton = std::make_shared<QPushButton>("Reserve Scooter");
    useScooterButton = std::make_shared<QPushButton>("Use Scooter");
    freeScooterButton = std::make_shared<QPushButton>("Free Scooter");
    seeMyReservedScootersButton = std::make_shared<QPushButton>("View my reserved scooters");;
    seeAllFreeScootersButton = std::make_shared<QPushButton>("View free scooters");;

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
    buttonLayout->addWidget(exitButton);
    buttonLayout->addWidget(viewAllScootersButton);
    buttonLayout->addWidget(reserveScooterButton.get());
    buttonLayout->addWidget(useScooterButton.get());
    buttonLayout->addWidget(freeScooterButton.get());
    buttonLayout->addWidget(seeMyReservedScootersButton.get());
    buttonLayout->addWidget(seeAllFreeScootersButton.get());

    // Create a layout for the table and buttons
    auto mainLayout = new QVBoxLayout();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(table);

    // Set the layout for the ManagerLabel widget
    setLayout(mainLayout);

    // Connect the button signals to their respective slots
    connect(viewAllScootersButton, &QPushButton::clicked, this, &ClientLabel::viewAllScooters);
    connect(reserveScooterButton.get(), &QPushButton::clicked, this, &ClientLabel::reserveScooter);
    connect(useScooterButton.get(), &QPushButton::clicked, this, &ClientLabel::useScooter);
    connect(freeScooterButton.get(), &QPushButton::clicked, this, &ClientLabel::freeScooter);
    connect(seeMyReservedScootersButton.get(), &QPushButton::clicked, this, &ClientLabel::seeMyReservedScooters);
    connect(seeAllFreeScootersButton.get(), &QPushButton::clicked, this, &ClientLabel::seeAllFreeScooters);

    // Connect the headerClicked signal to the handleHeaderClicked slot
    connect(table->horizontalHeader(), &QHeaderView::sectionClicked, this, &ClientLabel::handleHeaderClicked);

    // Connect button signals to slots
    connect(exitButton, &QPushButton::clicked, this, &ClientLabel::exitApplication);

    // Connect the cellDoubleClicked signal to a lambda function that emits the signal with the row and column index
    connect(table, &QTableWidget::cellDoubleClicked, this, [this](int row, int column) {
        emit cellDoubleClicked(row, column);
    });
}

void UI::ClientLabel::cellDoubleClicked(int row, int column) {
    // Get the number of columns in the table
    int numColumns = table->columnCount();

    // Create a QMenu for the popup menu
    QMenu popupMenu;

    // Loop through the columns and add actions for each column's data in the clicked row
    for (int col = 0; col < numColumns; ++col) {
        // Get the item text from the table's model
        QTableWidgetItem *item = table->item(row, col);
        if (item) {
            QString columnName = table->horizontalHeaderItem(col)->text();
            QString columnData = item->text();

            // Create a QAction for the column's data and add it to the popup menu
            QString actionText = QString("%1: %2").arg(columnName).arg(columnData);
            QAction *action = popupMenu.addAction(actionText);
            action->setEnabled(false); // Disable the action to make it non-clickable
        }
    }

    // Show the popup menu at the current cursor position
    popupMenu.exec(QCursor::pos());
}

void UI::ClientLabel::exitApplication() {
    // Implement the exit functionality here
    QApplication::quit();
}

void UI::ClientLabel::handleHeaderClicked(int index) {
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

void UI::ClientLabel::viewAllScooters() {
    // Get all scooters from the controller
    std::vector<ElectricScooter> allScooters = scooterController->getAll();

    // Populate the table with the scooters
    populateTable(allScooters);

    // Show the table
    table->show();
}

void UI::ClientLabel::populateTable(vector<ElectricScooter> scooters) {
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

void UI::ClientLabel::reserveScooter() {
    // Get the selected row from the table
    int selectedRow = table->currentRow();
    if (selectedRow >= 0 && selectedRow < table->rowCount()) {
        // Get the ID of the selected scooter
        QString id = table->item(selectedRow, 0)->text();

        // Convert the ID to std::string
        std::string scooterId = id.toStdString();

        // Call the reserveScooter function
        bool success = scooterController->reserveScooter(scooterId, currentUser);

        // Show a message based on the result
        if (success) {
            QMessageBox::information(this, "Reservation Successful", "Scooter reserved successfully.");
        } else {
            QMessageBox::warning(this, "Reservation Failed", "Failed to reserve the scooter. Please try again.");
        }
    } else {
        QMessageBox::warning(this, "No Scooter Selected", "Please select a scooter from the table.");
    }

    populateTable(scooterController->getAll());
}

void UI::ClientLabel::useScooter() {
    // Get the selected row from the table
    int selectedRow = table->currentRow();
    if (selectedRow >= 0 && selectedRow < table->rowCount()) {
        // Get the ID of the selected scooter
        QString id = table->item(selectedRow, 0)->text();

        // Convert the ID to std::string
        std::string scooterId = id.toStdString();

        // Call the useScooter function
        bool success = scooterController->useScooter(scooterId, currentUser);

        // Show a message based on the result
        if (success) {
            QMessageBox::information(this, "Scooter Usage Successful", "You are now using the scooter.");
        } else {
            QMessageBox::warning(this, "Scooter Usage Failed", "Failed to use the scooter. Please try again.");
        }
    } else {
        QMessageBox::warning(this, "No Scooter Selected", "Please select a scooter from the table.");
    }

    populateTable(scooterController->getAll());
}

void UI::ClientLabel::freeScooter() {
    // Get the selected row from the table
    int selectedRow = table->currentRow();
    if (selectedRow >= 0 && selectedRow < table->rowCount()) {
        // Get the ID of the selected scooter
        QString id = table->item(selectedRow, 0)->text();

        // Convert the ID to std::string
        std::string scooterId = id.toStdString();

        // Call the freeScooter function
        bool success = scooterController->freeScooter(scooterId, currentUser);

        // Show a message based on the result
        if (success) {
            QMessageBox::information(this, "Scooter Freed", "You have successfully freed the scooter.");
        } else {
            QMessageBox::warning(this, "Scooter Freeing Failed", "Failed to free the scooter. Please try again.");
        }
    } else {
        QMessageBox::warning(this, "No Scooter Selected", "Please select a scooter from the table.");
    }

    populateTable(scooterController->getAll());
}

void UI::ClientLabel::seeMyReservedScooters() {
    // Get the reserved scooters of the current user
    std::vector<ElectricScooter> reservedScooters = currentUser.getReservedScooters();

    if (reservedScooters.empty()) {
        QMessageBox::information(this, "No Reserved Scooters", "You have not reserved any scooters.");
        return;
    }

    populateTable(reservedScooters);
}

void UI::ClientLabel::seeAllFreeScooters() {
    // Retrieve the parked scooters from the controller
    std::vector<ElectricScooter> parkedScooters = scooterController->getParkedScooters();

    if (parkedScooters.empty()) {
        QMessageBox::information(this, "No free Scooters", "There are no available scooters at the moment");
        return;
    }

    populateTable(parkedScooters);
}