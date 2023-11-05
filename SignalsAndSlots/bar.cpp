#include "bar.h"

Bar::Bar(QString dangerStyle, QString normalStyle, QProgressBar *parent)
    : QProgressBar(parent) {
  dangerStyle_ = dangerStyle;
  normalStyle_ = normalStyle;
}

void Bar::SetColor(int health, int percent, const QString danStyle,
                   const QString norStyle) {
  if (health < percent) {
    this->setStyleSheet(danStyle);
  } else {
    this->setStyleSheet(norStyle);
  }
}
