#include "bar.h"

Bar::Bar() {
    const QString normalStyle =
        "QProgressBar::chunk {background: #E6E6FA; Width: 20px; margin: 0.5px; "
        "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    this->setStyleSheet(normalStyle);
}

void Bar::SetColor(int health, int percent) {
    const QString kDangerStyle =
          "QProgressBar::chunk {background: #E6E6FA; Width: 20px; margin: 0.5px;"
          "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
          "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
          "color:black;}";
    const QString kNormalStyle =
        "QProgressBar::chunk {background: #FFC0CB; Width: 20px; margin: 0.5px; "
        "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    if (health < percent) {
         this->setStyleSheet(kDangerStyle);
     } else {
         this->setStyleSheet(kNormalStyle);
     }
}
