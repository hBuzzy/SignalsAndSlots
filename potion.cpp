#include "potion.h"

Potion::Potion(int heal, QObject *parent) : QObject(parent) {
  heal_ = heal;
}

void Potion::OnHealButtonClicked() { emit MakeHeal(heal_); }
