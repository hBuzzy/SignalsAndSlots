#ifndef BAR_H
#define BAR_H

#include <QObject>
#include <QProgressBar>
#include <QWidget>

class Bar : public QProgressBar {
  Q_OBJECT
 public:
  Bar();

 signals:
  void CriticalHealthChanged(int health);

 public slots:
  void SetColor(int health);
  void SetCriticalHealth(int health);

 private:
  const QString kDangerStyle_ =
      "QProgressBar::chunk {background: #F44336; Width: 20px; margin: 0.5px;"
      "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
      "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
      "color:black;}";
  const QString kNormalStyle_ =
      "QProgressBar::chunk {background: #009688; Width: 20px; margin: 0.5px; "
      "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
      "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
      "color:black;}";
  int criticalPercent_ = (this->maximum());
};

#endif  // BAR_H
