#include "customprogressbar.h"

CustomProgressBar::CustomProgressBar(QWidget *parent) : QProgressBar(parent), colorThreshold_(50) {

    setRange(0, 100);
    setValue(100);
    setFormat("%v%");
    setTextVisible(true);

    connect(this, &QProgressBar::valueChanged, this, &CustomProgressBar::UpdateColor);
}

void CustomProgressBar::UpdateColor(int currentValue) {
    if (currentValue <= colorThreshold_) {
        setStyleSheet("QProgressBar::chunk { background-color: red; }");
    } else {
        setStyleSheet("QProgressBar::chunk { background-color: green; }");
    }
}

void CustomProgressBar::SetColorThreshold(int threshold) {
    colorThreshold_ = threshold;
    UpdateColor(value());
}

void CustomProgressBar::SetColor(int currentValue) {
    if (currentValue <= 50) {
        setStyleSheet("QProgressBar::chunk { background-color: red; }");
    } else {
        setStyleSheet("QProgressBar::chunk { background-color: green; }");
    }
}
