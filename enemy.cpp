#include "enemy.h"

Enemy::Enemy(int damage, int restore, QObject *parent) : QObject(parent) {
  damage_ = damage;
  restore_ = restore;
}

void Enemy::OnDamageButtonClicked() { emit MakeDamage(damage_); }
void Enemy::OnRestoreButtonClicked() { emit MakeRestore(restore_); }
