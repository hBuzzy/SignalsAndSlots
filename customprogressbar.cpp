#include "customprogressbar.h"
#include <QPalette>

CustomProgressBar::CustomProgressBar(QWidget *parent)
    : QProgressBar(parent)
{
    connect(this, &CustomProgressBar::valueChanged, this, &CustomProgressBar::updateColorAndValue);
}

void CustomProgressBar::updateColorAndValue(int health)
{
    int colorValue=50;
    setValue(health);
    if (health <= colorValue){
        QProgressBar::setStyleSheet("QProgressBar {background-color: #ed4111; border: 1px solid #ed4111;}");
    }
    else {
        QProgressBar::setStyleSheet("QProgressBar {background-color: #1fed11; border: 1px solid #1fed11;}");
    }

}

void CustomProgressBar::heal(int amount)
{
    int currentHealth = value();
    int newHealth = currentHealth + amount;
    setValue(newHealth);
    emit valueChanged(newHealth);
}
