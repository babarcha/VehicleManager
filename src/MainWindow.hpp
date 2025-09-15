#pragma once
#include <QMainWindow>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addVehicleButton_clicked();
    void on_deleteVehicleButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
    void on_exportCSVButton_clicked();
    void on_importCSVButton_clicked();
    void on_exitButton_clicked();
    void on_filterEdit_textChanged(const QString &text);
    void on_themeCheckBox_stateChanged(int state);
    void on_makeCombo_currentTextChanged(const QString &text);
    void on_vehicleTypeCombo_currentTextChanged(const QString &text);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QSortFilterProxyModel *proxy;
    QStringList popularMakes;
    QMap<QString, QMap<QString, QStringList>> modelMap;

    void setupModelDropdown();
    void updateModelCombo();
    void applyDarkTheme(bool enable);
};
