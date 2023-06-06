#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMainWindow>
#include <QVBoxLayout>
#include "LoginPage/LoginPage.h"

namespace UI {
    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);

    private:
        QWidget *centralWidget;
        LoginPage *loginPage;
    };
}
