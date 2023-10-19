#include "healing.hpp"

Healing::Healing(int restored, QObject *parent)
: QObject(parent), restored_(restored) {}

void Healing::OnRestoreButtonClicked() {
    emit Restore(restored_);
}
