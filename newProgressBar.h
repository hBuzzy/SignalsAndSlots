#ifndef NEWPROGRESSBAR_H
#define NEWPROGRESSBAR_H

#include <QProgressBar>

class NewProgressBar : public QProgressBar{
    Q_OBJECT
public:
    explicit NewProgressBar(int triggerValue, QWidget *parent = nullptr)
        :QProgressBar(parent) { triggerValue_ = triggerValue; };
public slots:
   void SetTriggerValue(int triggerValue);
    void SetCurrentValue(int currentValue);
signals:
   void TriggerValueChanged(int triggerValue);
public:
   int triggerValue_;
private slots:
    void ChangeColor(int health);
};

#endif // NEWPROGRESSBAR_H
