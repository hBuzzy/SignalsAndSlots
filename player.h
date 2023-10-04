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

 private:
  int maxHealth_;
  int currentHealth_;
  // Добавлена новая строка комментария и пустая строка
  // Добавлена новая строка комментария и пустая строка 2
};

#endif  // PLAYER_H
