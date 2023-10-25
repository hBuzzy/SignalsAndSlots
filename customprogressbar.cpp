#include "customprogressbar.h"

CustomProgressBar::CustomProgressBar(QWidget *parent) : QProgressBar(parent) {
    connect(this, &QProgressBar::valueChanged, this, &CustomProgressBar::UpdateColor);
}

void CustomProgressBar::SetThreshold(int value) {
    threshold_ = value;
    UpdateColor(threshold_);
}

void CustomProgressBar::UpdateColor(int value) {
    if (value < threshold_)
        setStyleSheet("QProgressBar::chunk { background: red; }");
    else
        setStyleSheet("QProgressBar::chunk { background: green; }");
}
