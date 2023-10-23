#include "bar.h"

Bar::Bar( QString danStyle, QString norStyle,QProgressBar *parent): QProgressBar(parent) {
    danStyle_=danStyle;
    norStyle_=norStyle;
}

void Bar::SetColor(int health, int percent,const QString danStyle,const QString norStyle) {
    if (health < percent) {
         this->setStyleSheet(danStyle);
     } else {
         this->setStyleSheet(norStyle);
     }
}
