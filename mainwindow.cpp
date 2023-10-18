#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    healfBar = new CustomProgressBar();
    ui->barParentLayout->addWidget(healfBar);

    QObject::connect(ui->limitSlider, &QSlider::valueChanged, healfBar, &CustomProgressBar::setLimit);
    QObject::connect(ui->limitSlider, &QSlider::valueChanged, this, &MainWindow::onLimitChanged);
    QObject::connect(ui->hitButton, &QPushButton::clicked, this, &MainWindow::onHitButtonClicked);
    QObject::connect(ui->healButton, &QPushButton::clicked, this, &MainWindow::onHealButtonClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onLimitChanged(int value) const {
    ui->limitLabel->setText(QString::number(value));
    healfBar->update();
}

void MainWindow::onHitButtonClicked() {
    healfBar->setState(-10);
    healfBar->update();
}

void MainWindow::onHealButtonClicked() {
    healfBar->setState(10);
    healfBar->update();
}

