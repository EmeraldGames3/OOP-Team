#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

namespace UI {
    class ClientLabel : public QWidget {
    Q_OBJECT

    public:
        explicit ClientLabel(QWidget *parent = nullptr);

    signals:
        void clientActionClicked();

    private:
        QLabel *label;
    };
}
