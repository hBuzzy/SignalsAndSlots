#include "custom_progress_bar.h"
#include <QDebug>
CustomProgressBar::CustomProgressBar(int lifeThreshold, int lifeCount, QWidget *parent) : QProgressBar(parent){
  lifeThreshold_ = lifeThreshold;
  lifeCount_ = lifeCount;
}

void CustomProgressBar::updateBarColor()
{
  if (lifeCount_ >= lifeThreshold_)
  {
    setStyleSheet(kNormalStyle);
  }
  else
  {
    setStyleSheet(kDangerStyle);
  }
}


void CustomProgressBar::setLifeThreshold(int threshold)
{
  qDebug() <<  threshold;
  lifeThreshold_ = threshold;
  updateBarColor();
}


void CustomProgressBar::setLifeCount(int count)
{
  lifeCount_ = count;
  updateBarColor();
}
