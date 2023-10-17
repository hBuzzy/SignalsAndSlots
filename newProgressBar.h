#ifndef NEWPROGRESSBAR_H
#define NEWPROGRESSBAR_H

#include <QProgressBar>

class NewProgressBar : public QProgressBar{
    Q_OBJECT
public:
    explicit NewProgressBar(int minHealth, QWidget *parent = nullptr)
        :QProgressBar(parent) { minHealth_ = minHealth; };
public slots:
   void ChangeColor(int health);
   void setMinHealth(int minHealth);
signals:
   void MinHealthChanged(int minHealth);
public:
   int minHealth_;
};

#endif // NEWPROGRESSBAR_H
