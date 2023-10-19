#include "newProgressBar.h"

void NewProgressBar::ChangeColor(int health) {
    if (health <= triggerValue_) {
        QProgressBar::setStyleSheet("QProgressBar {background-color: #F44336; border: 1px solid #F44336; padding: 1px; border-radius:10px;}");
    } else {
        QProgressBar::setStyleSheet("QProgressBar {background-color: #009688; border: 1px solid #009688; padding: 1px; border-radius:10px;}");
    }
}

void NewProgressBar::SetCurrentValue(int currentValue) {
    emit setValue(currentValue);
    emit ChangeColor(currentValue);
}

void NewProgressBar::SetTriggerValue(int triggerValue) {
    triggerValue_ = triggerValue;
    emit TriggerValueChanged(triggerValue_);
}
