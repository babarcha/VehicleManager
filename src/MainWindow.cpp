#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include <QStyleFactory>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Make + Type to Model mapping
    modelMap["Toyota"]["Car"] = {"Corolla", "Camry", "Yaris"};
    modelMap["Toyota"]["SUV"] = {"RAV4", "Highlander"};
    modelMap["Ford"]["Car"] = {"Focus", "Fusion", "Mustang"};
    modelMap["Ford"]["Truck"] = {"F-150", "Ranger"};
    modelMap["Honda"]["Car"] = {"Civic", "Accord"};
    modelMap["Honda"]["SUV"] = {"CR-V", "Pilot"};

    // Setup Make dropdown
    popularMakes = modelMap.keys();
    ui->makeCombo->addItems(popularMakes);

    // Setup Year dropdown
    for (int year = 2025; year >= 1990; --year)
        ui->yearCombo->addItem(QString::number(year));

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Make", "Type", "Model", "Year"});

    proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(model);
    proxy->setFilterKeyColumn(0); // Make column
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);

    ui->vehicleTableView->setModel(proxy);
    ui->vehicleTableView->setSortingEnabled(true);
    ui->vehicleTableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->vehicleTableView->horizontalHeader()->setStretchLastSection(true);

    updateModelCombo();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addVehicleButton_clicked() {
    QString make = ui->makeCombo->currentText().trimmed();
    QString type = ui->vehicleTypeCombo->currentText().trimmed();
    QString modelTxt = ui->modelCombo->currentText().trimmed();
    QString year = ui->yearCombo->currentText().trimmed();

    if (make.isEmpty() || modelTxt.isEmpty() || year.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled in.");
        return;
    }

    QList<QStandardItem *> rowItems;
    rowItems << new QStandardItem(make);
    rowItems << new QStandardItem(type);
    rowItems << new QStandardItem(modelTxt);
    rowItems << new QStandardItem(year);
    model->appendRow(rowItems);
}

void MainWindow::on_deleteVehicleButton_clicked() {
    QModelIndex index = ui->vehicleTableView->currentIndex();
    if (index.isValid())
        model->removeRow(proxy->mapToSource(index).row());
}

void MainWindow::on_saveButton_clicked() {
    QJsonArray jsonArray;
    for (int row = 0; row < model->rowCount(); ++row) {
        QJsonObject obj;
        obj["Make"] = model->item(row, 0)->text();
        obj["Type"] = model->item(row, 1)->text();
        obj["Model"] = model->item(row, 2)->text();
        obj["Year"] = model->item(row, 3)->text();
        jsonArray.append(obj);
    }

    QFile file("vehicles.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(jsonArray).toJson());
        file.close();
        QMessageBox::information(this, "Saved", "Saved to vehicles.json");
    }
}

void MainWindow::on_loadButton_clicked() {
    QFile file("vehicles.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    file.close();

    model->removeRows(0, model->rowCount());
    for (const QJsonValue &val : doc.array()) {
        QJsonObject obj = val.toObject();
        QList<QStandardItem *> row;
        row << new QStandardItem(obj["Make"].toString());
        row << new QStandardItem(obj["Type"].toString());
        row << new QStandardItem(obj["Model"].toString());
        row << new QStandardItem(obj["Year"].toString());
        model->appendRow(row);
    }
}

void MainWindow::on_exportCSVButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Export to CSV", "", "*.csv");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file for writing.");
        return;
    }

    QTextStream stream(&file);
    stream << "Make,Type,Model,Year\n";

    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList rowText;
        for (int col = 0; col < model->columnCount(); ++col) {
            rowText << model->item(row, col)->text();
        }
        stream << rowText.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(this, "Exported", "CSV export successful.");
}

void MainWindow::on_importCSVButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Import from CSV", "", "CSV Files (*.csv)");
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Could not open file for reading.");
        return;
    }

    QTextStream stream(&file);
    QString headerLine = stream.readLine(); // skip header

    int imported = 0, skipped = 0;

    QStringList validMakes, validTypes, validYears;
    for (int i = 0; i < ui->makeCombo->count(); ++i) validMakes << ui->makeCombo->itemText(i);
    for (int i = 0; i < ui->vehicleTypeCombo->count(); ++i) validTypes << ui->vehicleTypeCombo->itemText(i);
    for (int i = 0; i < ui->yearCombo->count(); ++i) validYears << ui->yearCombo->itemText(i);

    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(",");
        if (parts.size() != 4) { skipped++; continue; }

        QString make = parts[0].trimmed();
        QString type = parts[1].trimmed();
        QString modelStr = parts[2].trimmed();  // ✅ FIXED: renamed from model
        QString year = parts[3].trimmed();

        if (!validMakes.contains(make) || !validTypes.contains(type) || !validYears.contains(year)) {
            skipped++;
            continue;
        }

        if (!modelMap[make][type].contains(modelStr)) {
            skipped++;
            continue;
        }

        QList<QStandardItem *> row;
        row << new QStandardItem(make)
            << new QStandardItem(type)
            << new QStandardItem(modelStr)
            << new QStandardItem(year);
        model->appendRow(row);
        imported++;
    }

    file.close();
    QMessageBox::information(this, "Import Summary",
                             QString("✅ Imported: %1\n❌ Skipped: %2").arg(imported).arg(skipped));
}

void MainWindow::on_filterEdit_textChanged(const QString &text) {
    proxy->setFilterRegularExpression(QRegularExpression("^" + QRegularExpression::escape(text), QRegularExpression::CaseInsensitiveOption));
}

void MainWindow::on_exitButton_clicked() {
    QApplication::quit();
}

void MainWindow::on_themeCheckBox_stateChanged(int state) {
    applyDarkTheme(state == Qt::Checked);
}

void MainWindow::applyDarkTheme(bool enable) {
    qApp->setStyle(QStyleFactory::create("Fusion"));
    QPalette palette;
    if (enable) {
        palette.setColor(QPalette::Window, QColor(53,53,53));
        palette.setColor(QPalette::WindowText, Qt::white);
        palette.setColor(QPalette::Base, QColor(25,25,25));
        palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
        palette.setColor(QPalette::ToolTipBase, Qt::white);
        palette.setColor(QPalette::ToolTipText, Qt::white);
        palette.setColor(QPalette::Text, Qt::white);
        palette.setColor(QPalette::Button, QColor(53,53,53));
        palette.setColor(QPalette::ButtonText, Qt::white);
        palette.setColor(QPalette::BrightText, Qt::red);
    }
    qApp->setPalette(palette);
}

void MainWindow::on_makeCombo_currentTextChanged(const QString &) {
    updateModelCombo();
}

void MainWindow::on_vehicleTypeCombo_currentTextChanged(const QString &) {
    updateModelCombo();
}

void MainWindow::updateModelCombo() {
    ui->modelCombo->clear();
    QString make = ui->makeCombo->currentText();
    QString type = ui->vehicleTypeCombo->currentText();
    if (modelMap.contains(make) && modelMap[make].contains(type)) {
        ui->modelCombo->addItems(modelMap[make][type]);
    }
}
