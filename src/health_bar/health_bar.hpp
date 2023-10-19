#ifndef HEALTH_BAR_HPP
#define HEALTH_BAR_HPP

#include <QProgressBar>

class HealthBar: public QProgressBar {
public:
    explicit HealthBar(int threshold = 50, QWidget *parent = nullptr);
public slots:
    void setHealth(int health);
    void setThreshhold(int threshold);
private:
    int threshold_;
};

#endif
