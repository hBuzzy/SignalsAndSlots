#include "health_bar.hpp"

HealthBar::HealthBar(int threshold, QWidget *parent)
: QProgressBar(parent), threshold_(threshold) {
    this->setStyleSheet("QProgressBar::chunk { background: green; }");
}

void HealthBar::setHealth(int health) {
    this->QProgressBar::setValue(health);
    this->setStyleSheet(health > threshold_ ?
        "QProgressBar::chunk { background: green; }" :
        "QProgressBar::chunk { background: red; }"
    );
}

void HealthBar::setThreshhold(int threshold) {
    threshold_ = threshold;
    setHealth(value());
}
