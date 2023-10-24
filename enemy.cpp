#include "enemy.h"

Enemy::Enemy(int damage, int health, QObject *parent) : QObject(parent) {
  damage_ = damage;
  health_ = health;
}

void Enemy::OnDamageButtonClicked() { emit MakeDamage(damage_); }
void Enemy::OnHealthButtonClicked() { emit MakeHealth(health_); }
