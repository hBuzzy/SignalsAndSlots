#include "player.h"

Player::Player(int health, QObject *parent) : QObject{parent}
{
  maxHealth_ = health;
  currentHealth_ = maxHealth_;
}

void Player::TakeDamage(int damage)
{
  if (currentHealth_ == 0) return;

  currentHealth_ -= damage;

  if (currentHealth_ < 0) currentHealth_ = 0;

  emit HealthChanged(currentHealth_);
}

void Player::TakeHealth(int health)
{
    if (currentHealth_ == GetMaxHealth()) return;

    currentHealth_ += health;

    emit HealthChanged(currentHealth_);
}

int Player::GetCurrentHealth() { return currentHealth_; }
int Player::GetMaxHealth() const { return maxHealth_; }
