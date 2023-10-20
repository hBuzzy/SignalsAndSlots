#include "bar.h"

Bar::Bar() { this->setStyleSheet(kNormalStyle_); }

void Bar::SetColor(int health) {
  if (health < criticalPercent_) {
    this->setStyleSheet(kDangerStyle_);
  } else {
    this->setStyleSheet(kNormalStyle_);
  }
}

void Bar::SetCriticalHealth(int health) {
  criticalPercent_ = health;
  emit CriticalHealthChanged(criticalPercent_);
}
