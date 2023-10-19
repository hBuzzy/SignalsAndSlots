#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customprogressbar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void OnHitButtonClicked();
    void OnHealButtonClicked();
    void OnLimitChanged(int value) const;

private:
    Ui::MainWindow *ui;
    CustomProgressBar *healfBar;
};
#endif // MAINWINDOW_H
