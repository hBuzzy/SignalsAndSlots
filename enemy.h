#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

class Enemy : public QObject {
  Q_OBJECT
 public:
  explicit Enemy(int damage, int restore, QObject *parent = nullptr);

 signals:
  void MakeDamage(int damage);
  void MakeRestore(int restore);

 public slots:
  void OnDamageButtonClicked();
  void OnRestoreButtonClicked();

 private:
  int damage_;
  int restore_;
};

#endif  // ENEMY_H
