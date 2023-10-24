#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QProgressBar>

class ProgressBar : public QProgressBar{
    Q_OBJECT
public:
    explicit ProgressBar(int indicativeValue, QWidget *parent = nullptr)
        :QProgressBar(parent) { indicativeValue_ = indicativeValue; };
public slots:
    void SetIndicativeValue(int indicativeValue);
    void SetCurrentValue(int currentValue);
signals:
    void IndicativeValueChanged(int indicativeValue);
public:
    int indicativeValue_;
private slots:
    void ChangeColor(int health);
};


#endif // PROGRESSBAR_H
