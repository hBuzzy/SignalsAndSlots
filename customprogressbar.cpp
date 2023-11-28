#include "customprogressbar.h"

#include <QProgressBar>

CustomProgressBar::CustomProgressBar() : QProgressBar() {}

void CustomProgressBar::ChangeColor(int health) {
    setValue(health);
    if (health > criticalValue) {
        QProgressBar::setStyleSheet("QProgressBar::chunk {background: #009688;");
    }
    else {
        QProgressBar::setStyleSheet("QProgressBar::chunk {background: #F44336;}");
    }
}

void CustomProgressBar::ChangeCriticalValue(int value) {
    criticalValue = value;
}
