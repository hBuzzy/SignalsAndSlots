#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H

#include <QProgressBar>

class CustomProgressBar : public QProgressBar
{
    Q_OBJECT

public:
    CustomProgressBar(QWidget *parent = nullptr);

public slots:
    void UpdateColor(int value);
    void SetThreshold(int value);

private:
    int threshold_;
};

#endif // CUSTOMPROGRESSBAR_H
