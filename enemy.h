#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

class Enemy : public QObject {
  Q_OBJECT
 public:
  explicit Enemy(int damage, int health, QObject *parent = nullptr);

 signals:
  void MakeDamage(int gamage);
  void MakeHealth(int health);
 public slots:
  void OnDamageButtonClicked();
  void OnHealthButtonClicked();
 private:
  int damage_;
  int health_;
};

#endif  // ENEMY_H
