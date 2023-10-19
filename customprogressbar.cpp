#include "customprogressbar.h"

CustomProgressBar::CustomProgressBar(QWidget *parent) : QProgressBar(parent) {
    this->_state = 100;
    this->_limit = 50;
    setTextVisible(false);
}

void CustomProgressBar::paintEvent(QPaintEvent *event) {
    QProgressBar::paintEvent(event);
    setValue(_state);

    QString badStyle = "::chunk{background-color: red;}";
    QString goodStyle = "::chunk{background-color: green;}";

    if (_state < _limit) {
        this->setStyleSheet(badStyle);
    } else{
        this->setStyleSheet(goodStyle);
    }
}

void CustomProgressBar::setState(int _state) {
    if (_state > 0){
        this->_state = qMin(this->_state + _state, maximum());
    } else{
        this->_state = qMax(this->_state + _state, minimum());
    }
};

void CustomProgressBar::setLimit(int _limit) {
    this->_limit = _limit;
};

