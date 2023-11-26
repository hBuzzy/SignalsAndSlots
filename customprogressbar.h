#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QProgressBar>
#include <QSlider>

class CustomProgressBar : public QProgressBar{
    Q_OBJECT

    int currentThresh = 50;

public:
    CustomProgressBar();

public slots:
    void ChangeColor();
    void SetValue(int);

};

#endif // CUSTOMPROGRESSBAR_H
