#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H
#include <QProgressBar>
#include <QPainter>

class CustomProgressBar : public QProgressBar{
    Q_OBJECT
public:
    CustomProgressBar(QWidget *parent = nullptr);

private:
    int _state;
    int _limit;

public slots:
    void setState(int _state);
    void setLimit(int _limit);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CUSTOMPROGRESSBAR_H
