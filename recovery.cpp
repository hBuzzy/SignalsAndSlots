#include "recovery.h"

Recovery::Recovery(int heal, QObject *parent) : QObject(parent){
    heal_ = heal;
}

void Recovery::OnHealButtonClicked(){ emit HealDamage(heal_); }
