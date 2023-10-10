#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject {
  Q_OBJECT
 public:
  explicit Player(int health, int recoverHealth, QObject *parent = nullptr);
  int GetMaxHealth() const;

 signals:
  void HealthChanged(int health);

 public slots:
  void TakeDamage(int damage);
  void RecoverHealth();
  void OnRecoverButtonClicked();

 private:
  int maxHealth_;
  int currentHealth_;
  int recoverHealth_;
};

#endif  // PLAYER_H
