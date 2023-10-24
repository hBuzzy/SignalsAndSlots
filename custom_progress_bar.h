#ifndef CUSTOMPROGRESBAR_H
#define CUSTOMPROGRESBAR_H
#include <QProgressBar>

class CustomProgressBar : public QProgressBar
{
public:
   explicit CustomProgressBar(int lifeThreshold, int lifeCount, QWidget *parent = nullptr);

public slots:
   void setLifeThreshold(int threshold);
   void setLifeCount(int count);

private:
   int lifeThreshold_;
   int lifeCount_;
   void updateBarColor();

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
};


#endif // CUSTOMPROGRESBAR_H
