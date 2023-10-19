#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <QObject>

class Enemy : public QObject {
    Q_OBJECT
public:
    explicit Enemy(int damage, QObject *parent = nullptr);
signals:
    void MakeDamage(int gamage);
public slots:
    void OnDamageButtonClicked();
private:
    int damage_;
};

#endif
