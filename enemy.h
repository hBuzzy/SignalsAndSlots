#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

class Enemy : public QObject {
  Q_OBJECT
 public:
  explicit Enemy(int damage, QObject *parent = nullptr);

 signals:
  void MakeDamage(int damage);

 public slots:
  void OnDamageButtonClicked();

 private:
  int damage_;
};

#endif  // ENEMY_H
