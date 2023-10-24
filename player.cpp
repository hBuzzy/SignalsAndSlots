#include "player.h"

Player::Player(int health, int healing, QObject *parent) : QObject{parent} {
  maxHealth_ = health;
  currentHealth_ = maxHealth_;
  healing_ = healing;
}

void Player::TakeDamage(int damage) {
  if (currentHealth_ == 0) return;

  currentHealth_ -= damage;

  if (currentHealth_ < 0) currentHealth_ = 0;

  emit HealthChanged(currentHealth_);
}

void Player::TakeHeal() {
  if (currentHealth_ == maxHealth_) return;

  currentHealth_ += healing_;

  if (currentHealth_ > maxHealth_) currentHealth_ = maxHealth_;

  emit HealthChanged(currentHealth_);
}

void Player::UpgradeHealth(){
  emit HealthChanged(currentHealth_);
}
int Player::GetMaxHealth() const { return maxHealth_; }
int Player::GetCurrentHealth() { return currentHealth_; }
