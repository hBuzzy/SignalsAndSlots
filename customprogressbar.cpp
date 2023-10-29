#include "customprogressbar.h"
#include <QPalette>

CustomProgressBar::CustomProgressBar(QWidget *parent)
    : QProgressBar(parent) {
    threshold_ = 50;
    UpdateColorAndValue(value());
    connect(this, &CustomProgressBar::valueChanged, this, &CustomProgressBar::UpdateColorAndValue);
}

void CustomProgressBar::UpdateColorAndValue(int health) {
    setValue(health);
    if (health <= threshold_) {
        QProgressBar::setStyleSheet("QProgressBar {background-color: #ed4111; border: 1px solid #ed4111;}");
    }
    else {
        QProgressBar::setStyleSheet("QProgressBar {background-color: #1fed11; border: 1px solid #1fed11;}");
    }
}

void CustomProgressBar::Heal(int amount) {
    int currentHealth = value();
    int newHealth = currentHealth + amount;
    setValue(newHealth);
    emit valueChanged(newHealth);
}

void CustomProgressBar::SetThreshold(int value) {
    threshold_ = value;
    UpdateColorAndValue(this->value());
}


