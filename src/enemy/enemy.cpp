#include "enemy.hpp"

Enemy::Enemy(int damage, QObject *parent)
: QObject(parent), damage_(damage) {}

void Enemy::OnDamageButtonClicked() {
    emit MakeDamage(damage_);
}
