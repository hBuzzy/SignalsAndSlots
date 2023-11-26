#include "customprogressbar.h"

CustomProgressBar::CustomProgressBar() : QProgressBar(){}

void CustomProgressBar::ChangeColor(){

    if (value() < currentThresh and value() > currentThresh*0.4)
        this->setStyleSheet("QProgressBar::chunk {background-color: yellow;}");
    if (value() <= currentThresh*0.4)
        this->setStyleSheet("QProgressBar::chunk {background-color: red;}");
    if (value() >= currentThresh)
        this->setStyleSheet("QProgressBar::chunk {background-color: light green;}");
}

void CustomProgressBar::SetValue(int val){
    currentThresh = val;
}




