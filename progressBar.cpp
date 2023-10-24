#include "progressBar.h"

void ProgressBar::ChangeColor(int health) {
    if (health <= indicativeValue_) {
        QProgressBar::setStyleSheet("QProgressBar {background-color: #68140D; border: 1px solid #68140D; padding: 1px; border-radius:5px;}");
    } else {
        QProgressBar::setStyleSheet("QProgressBar {background-color: #92BD6C; border: 1px solid #92BD6C; padding: 1px; border-radius:5px;}");
    }
}

void ProgressBar::SetCurrentValue(int currentValue) {
    emit setValue(currentValue);
    emit ChangeColor(currentValue);
}

void ProgressBar::SetIndicativeValue(int indicativeValue) {
    indicativeValue_ = indicativeValue;
    emit IndicativeValueChanged(indicativeValue_);
}
