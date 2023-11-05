#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QSlider>
#include <QWidget>

#include "bar.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);

  ~Widget();

 private:
  Ui::Widget *ui;
  Bar *healthBar_;
  QSlider *myhealthSlider_;
};
#endif  // WIDGET_H
