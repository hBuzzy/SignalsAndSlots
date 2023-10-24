#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QProgressBar>

class CustomProgressBar : public QProgressBar {
    Q_OBJECT

public:
    CustomProgressBar(QWidget *parent = nullptr);
    void setColorThreshold(int threshold);

public slots:
    void updateColor(int currentValue);

private:
    void setColor(int currentValue);
    int colorThreshold_;
};

#endif // CUSTOMPROGRESSBAR_H
