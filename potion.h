#ifndef POTION_H
#define POTION_H


#include <QObject>

class Potion : public QObject {
  Q_OBJECT
 public:
  explicit Potion(int heal, QObject *parent = nullptr);

 signals:
  void MakeHeal(int heal);

 public slots:
  void OnHealButtonClicked();

 private:
  int heal_;
};



#endif // POTION_H
