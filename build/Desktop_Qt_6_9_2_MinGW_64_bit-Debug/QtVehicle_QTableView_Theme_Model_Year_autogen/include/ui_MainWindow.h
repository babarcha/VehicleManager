/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *filterEdit;
    QComboBox *makeCombo;
    QComboBox *vehicleTypeCombo;
    QComboBox *modelCombo;
    QComboBox *yearCombo;
    QCheckBox *themeCheckBox;
    QPushButton *addVehicleButton;
    QPushButton *deleteVehicleButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *exportCSVButton;
    QPushButton *exitButton;
    QTableView *vehicleTableView;
    QPushButton *importCSVButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(750, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        filterEdit = new QLineEdit(centralwidget);
        filterEdit->setObjectName("filterEdit");
        filterEdit->setGeometry(QRect(20, 10, 200, 25));
        makeCombo = new QComboBox(centralwidget);
        makeCombo->setObjectName("makeCombo");
        makeCombo->setGeometry(QRect(230, 10, 120, 25));
        vehicleTypeCombo = new QComboBox(centralwidget);
        vehicleTypeCombo->addItem(QString());
        vehicleTypeCombo->addItem(QString());
        vehicleTypeCombo->addItem(QString());
        vehicleTypeCombo->addItem(QString());
        vehicleTypeCombo->setObjectName("vehicleTypeCombo");
        vehicleTypeCombo->setGeometry(QRect(360, 10, 100, 25));
        modelCombo = new QComboBox(centralwidget);
        modelCombo->setObjectName("modelCombo");
        modelCombo->setGeometry(QRect(470, 10, 120, 25));
        yearCombo = new QComboBox(centralwidget);
        yearCombo->setObjectName("yearCombo");
        yearCombo->setGeometry(QRect(600, 10, 70, 25));
        themeCheckBox = new QCheckBox(centralwidget);
        themeCheckBox->setObjectName("themeCheckBox");
        themeCheckBox->setGeometry(QRect(680, 10, 70, 25));
        addVehicleButton = new QPushButton(centralwidget);
        addVehicleButton->setObjectName("addVehicleButton");
        addVehicleButton->setGeometry(QRect(20, 45, 80, 25));
        deleteVehicleButton = new QPushButton(centralwidget);
        deleteVehicleButton->setObjectName("deleteVehicleButton");
        deleteVehicleButton->setGeometry(QRect(110, 45, 80, 25));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(200, 45, 80, 25));
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        loadButton->setGeometry(QRect(290, 45, 80, 25));
        exportCSVButton = new QPushButton(centralwidget);
        exportCSVButton->setObjectName("exportCSVButton");
        exportCSVButton->setGeometry(QRect(380, 45, 100, 25));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(620, 45, 80, 25));
        vehicleTableView = new QTableView(centralwidget);
        vehicleTableView->setObjectName("vehicleTableView");
        vehicleTableView->setGeometry(QRect(20, 80, 700, 360));
        importCSVButton = new QPushButton(centralwidget);
        importCSVButton->setObjectName("importCSVButton");
        importCSVButton->setGeometry(QRect(490, 45, 100, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Vehicle Manager", nullptr));
        filterEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Make...", nullptr));
        vehicleTypeCombo->setItemText(0, QCoreApplication::translate("MainWindow", "Car", nullptr));
        vehicleTypeCombo->setItemText(1, QCoreApplication::translate("MainWindow", "Jeep", nullptr));
        vehicleTypeCombo->setItemText(2, QCoreApplication::translate("MainWindow", "SUV", nullptr));
        vehicleTypeCombo->setItemText(3, QCoreApplication::translate("MainWindow", "Truck", nullptr));

        themeCheckBox->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        addVehicleButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        deleteVehicleButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        exportCSVButton->setText(QCoreApplication::translate("MainWindow", "Export CSV", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        importCSVButton->setText(QCoreApplication::translate("MainWindow", "Import CSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
