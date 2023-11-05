#include "god.h"

God::God(int damage, int restore, QObject *parent) : QObject(parent) {
  damage_ = damage;
  restore_ = restore;
}

void God::OnDamageButtonClicked() { emit MakeDamage(damage_); }
void God::OnRestoreButtonClicked() { emit MakeRestore(restore_); }
