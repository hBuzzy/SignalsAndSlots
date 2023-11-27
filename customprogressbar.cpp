#include "customprogressbar.h"

CustomProgressBar::CustomProgressBar() : QProgressBar() {}

void CustomProgressBar::ChangeColor() {
    int dangerousValue = currentThreshold * 0.4;

    if (value() < currentThreshold and value() > dangerousValue)
        this->setStyleSheet("QProgressBar::chunk {background-color: yellow;}");
    if (value() <= dangerousValue)
        this->setStyleSheet("QProgressBar::chunk {background-color: red;}");
    if (value() >= currentThreshold)
        this->setStyleSheet("QProgressBar::chunk {background-color: light green;}");
}

void CustomProgressBar::SetValue(int value) {
    currentThreshold = value;
}




