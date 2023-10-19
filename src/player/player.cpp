#include "player.hpp"

Player::Player(int health, QObject *parent)
: QObject{parent}, maxHealth_(health), currentHealth_(health) {}

void Player::TakeDamage(int damage) {
    currentHealth_ = std::max(0, currentHealth_ - damage);
    emit HealthChanged(currentHealth_);
}

void Player::RestoreHealth(int restored) {
    currentHealth_ = std::min(maxHealth_, currentHealth_ + restored);
    emit HealthChanged(currentHealth_);
}
