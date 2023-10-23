#include "bar.h"

Bar::Bar( QString danStyle, QString norStyle,QProgressBar *parent): QProgressBar(parent) {
    danStyle_=danStyle;
    norStyle_=norStyle;
}

void Bar::SetColor(int health, int percent,const QString danStyle,const QString norStyle) {
  QString kDangerStyle =
          "QProgressBar::chunk {background: #E6E6FA; Width: 20px; margin: 0.5px;"
          "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
          "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
          "color:black;}";
     QString kNormalStyle =
        "QProgressBar::chunk {background: #FFC0CB; Width: 20px; margin: 0.5px; "
        "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    if (health < percent) {
         this->setStyleSheet(danStyle);
     } else {
         this->setStyleSheet(norStyle);
     }
}
