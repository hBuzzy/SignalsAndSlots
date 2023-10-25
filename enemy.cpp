#include "enemy.h"

Enemy::Enemy(int damage, QObject *parent) : QObject(parent) {
    damage_ = damage;
}
void Enemy::OnDamageButtonClicked() { emit MakeDamage(damage_); }
void Enemy::OnHealButtonClicked() { emit MakeHeal(damage_); }
