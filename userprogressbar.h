#ifndef USERPROGRESSBAR_H
#define USERPROGRESSBAR_H

#include <QProgressBar>

class UserProgressBar : public QProgressBar {
  Q_OBJECT
 public:
  explicit UserProgressBar(int requiredValue, QProgressBar* parent = nullptr);

 signals:
  void RequiredValueChanged(int requiredValue);

 public slots:
  void UpdateColor();
  void SetRequiredValue(int requiredValue);

 private:
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

  int requiredValue_;
  int currentValue_;
};

#endif  // USERPROGRESSBAR_H
