#include "UI/UserInterface.h"
#include <memory>
#include "Tests/TestAll.h"
#include <fstream>
#include <QApplication>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
    testAll();
    return 0;

//    QApplication app(argc, argv);
//
//    QWidget window;
//    QLabel label("Hello World!");
//    QVBoxLayout layout(&window);
//    layout.addWidget(&label);
//
//    window.setWindowTitle("Hello World");
//    window.show();
//
//    return app.exec();
}