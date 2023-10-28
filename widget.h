#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include "customprogressbar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

 private:
  Ui::Widget *ui;
  CustomProgressBar *customProgressBar_;
  QLabel *thresholdLabel_;
  CustomProgressBar *healthBar_;

 private slots:
    void UpdateThreshold(int value);

};

#endif // WIDGET_H
