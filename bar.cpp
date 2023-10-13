#include "bar.h"

Bar::Bar() {
    const QString normalStyle =
        "QProgressBar::chunk {background: #009688; Width: 20px; margin: 0.5px; "
        "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    this->setStyleSheet(normalStyle);
}

void Bar::SetColor(int health) {
    const QString kDangerStyle =
          "QProgressBar::chunk {background: #F44336; Width: 20px; margin: 0.5px;"
          "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
          "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
          "color:black;}";
    const QString kNormalStyle =
        "QProgressBar::chunk {background: #009688; Width: 20px; margin: 0.5px; "
        "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

    int fiftyPercent = (this->maximum())/2;

    if (health < fiftyPercent) {
         this->setStyleSheet(kDangerStyle);
     } else {
         this->setStyleSheet(kNormalStyle);
     }
}
