#include "player.h"

Player::Player(int health, QObject *parent) : QObject{parent} {
  maxHealth_ = health;
  currentHealth_ = maxHealth_;
}

void Player::TakeDamage(int damage) {
  if (currentHealth_ == 0) return;

  currentHealth_ -= damage;

  if (currentHealth_ < 0) currentHealth_ = 0;

  emit HealthChanged(currentHealth_);
}

void Player::RecoveryHealth(int heal)
{
    if (currentHealth_ == 100) return;

    currentHealth_ += heal;

    if (currentHealth_ > 100) currentHealth_ = 100;

    emit HealthChanged(currentHealth_);
}

int Player::GetMaxHealth() const { return maxHealth_; }
