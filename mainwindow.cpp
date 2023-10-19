#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    healfBar = new CustomProgressBar();
    ui->barParentLayout->addWidget(healfBar);

    QObject::connect(ui->limitSlider, &QSlider::valueChanged, healfBar, &CustomProgressBar::setLimit);
    QObject::connect(ui->limitSlider, &QSlider::valueChanged, this, &MainWindow::OnLimitChanged);
    QObject::connect(ui->hitButton, &QPushButton::clicked, this, &MainWindow::OnHitButtonClicked);
    QObject::connect(ui->healButton, &QPushButton::clicked, this, &MainWindow::OnHealButtonClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::OnLimitChanged(int value) const {
    ui->limitLabel->setText(QString::number(value));
    healfBar->update();
}

void MainWindow::OnHitButtonClicked() {
    healfBar->setState(-10);
    healfBar->update();
}

void MainWindow::OnHealButtonClicked() {
    healfBar->setState(10);
    healfBar->update();
}

