#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

class Enemy : public QObject {
  Q_OBJECT
 public:
  explicit Enemy(int damage, QObject *parent = nullptr);

 signals:
  void MakeDamage(int gamage);
  void LoseDamage(int gamage);

 public slots:
  void OnDamageButtonClicked();
  void OnHealthButtonClicked();

 private:
  int damage_;
};

#endif  // ENEMY_H
