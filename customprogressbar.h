#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QProgressBar>

class CustomProgressBar : public QProgressBar {
    Q_OBJECT

public:
    CustomProgressBar(QWidget *parent = nullptr);
    void SetColorThreshold(int threshold);

public slots:
    void UpdateColor(int currentValue);

private:
    void SetColor(int currentValue);
    int colorThreshold_;
};

#endif // CUSTOMPROGRESSBAR_H
