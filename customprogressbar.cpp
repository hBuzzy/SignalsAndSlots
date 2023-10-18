#include "customprogressbar.h"

CustomProgressBar::CustomProgressBar(QWidget *parent) : QProgressBar(parent) {
    this->state = 100;
    this->limit = 50;
    setTextVisible(false);
}

void CustomProgressBar::paintEvent(QPaintEvent *event) {
    QProgressBar::paintEvent(event);
    setValue(state);

    QString badStyle = "::chunk{background-color: red;}";
    QString goodStyle = "::chunk{background-color: green;}";

    if(state < limit){
        this->setStyleSheet(badStyle);
    } else{
        this->setStyleSheet(goodStyle);
    }
}

void CustomProgressBar::setState(int state) {
    if(state > 0){
        this->state = qMin(this->state + state, maximum());
    }else{
        this->state = qMax(this->state + state, minimum());
    }
};

void CustomProgressBar::setLimit(int limit) {
    this->limit = limit;
};

