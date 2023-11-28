#include "heal.h"

Heal::Heal(int heal, QObject *parent) : QObject(parent) {
  heal_ = heal;
}

void Heal::OnHealButtonClicked() { emit MakeHealPoint(heal_); }
