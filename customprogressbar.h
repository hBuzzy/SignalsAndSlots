#ifndef CUSTOMPROGRESSBAR_H
#define CUSTOMPROGRESSBAR_H
#include <QProgressBar>
#include <QPainter>

class CustomProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    CustomProgressBar(QWidget *parent = nullptr);

private:
    int state;
    int limit;

public slots:
    void setState(int state);
    void setLimit(int limit);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CUSTOMPROGRESSBAR_H
