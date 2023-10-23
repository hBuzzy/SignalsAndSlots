#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QProgressBar>

class CustomProgressBar : public QProgressBar
{
    Q_OBJECT

public:
    CustomProgressBar(QWidget *parent = nullptr);

public slots:
    void updateColorAndValue(int health);
    void heal(int amount);

signals:
    void thresholdChanged(int threshold);

private:
    int threshold;
};

#endif
