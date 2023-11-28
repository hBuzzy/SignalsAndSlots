#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QProgressBar>

class CustomProgressBar : public QProgressBar {
    Q_OBJECT

    int criticalValue = 25;

public:
    CustomProgressBar();

public slots:

    void ChangeColor(int value);
    void ChangeCriticalValue(int value);

};

#endif // CUSTOMPROGRESSBAR_H
