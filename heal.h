#ifndef HEAL_H
#define HEAL_H

#include <QObject>

class Heal: public QObject {
    Q_OBJECT
   public:
    explicit Heal(int heal, QObject *parent = nullptr);

   signals:
    void MakeHealPoint(int healing);

   public slots:
    void OnHealButtonClicked();

   private:
    int heal_;
  };

#endif // HEAL_H
