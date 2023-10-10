#include "player.h"

Player::Player(int health, int recoverHealth, QObject *parent) : QObject{parent} {
  maxHealth_ = health;
  currentHealth_ = maxHealth_;
  recoverHealth_ = recoverHealth;
}

void Player::TakeDamage(int damage) {
  if (currentHealth_ == 0) return;

  currentHealth_ -= damage;

  if (currentHealth_ < 0) currentHealth_ = 0;

  emit HealthChanged(currentHealth_);
}

void Player::RecoverHealth() {
  currentHealth_ += recoverHealth_;

  if (currentHealth_ > maxHealth_) currentHealth_ = maxHealth_;

  emit HealthChanged(currentHealth_);
}

int Player::GetMaxHealth() const { return maxHealth_; }


void Player::OnRecoverButtonClicked() {
  RecoverHealth();
}
