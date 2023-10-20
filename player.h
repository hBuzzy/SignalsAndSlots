#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject {
  Q_OBJECT

 public:
  explicit Player(int health, QObject *parent = nullptr);
  int GetMaxHealth() const;

 signals:
  void HealthChanged(int health);

 public slots:
  void TakeDamage(int damage);
  void TakeRestore(int restore);

 private:
  int maxHealth_;
  int currentHealth_;
};

#endif  // PLAYER_H
