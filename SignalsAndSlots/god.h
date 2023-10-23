#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>

class God : public QObject {
  Q_OBJECT
 public:
  explicit God(int damage,int restore, QObject *parent = nullptr);

 signals:
  void MakeDamage(int gamage);
  void MakeRestore(int restore);

 public slots:
  void OnDamageButtonClicked();
  void OnRestoreButtonClicked();

 private:
  int damage_;
  int restore_;
};

#endif
