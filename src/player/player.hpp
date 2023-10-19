#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <QObject>

class Player : public QObject {
    Q_OBJECT
public:
    explicit Player(int health, QObject *parent = nullptr);
signals:
    void HealthChanged(int health);
public slots:
    void TakeDamage(int damage);
    void RestoreHealth(int restored);
public:
    const int maxHealth_;
private:
    int currentHealth_;
};

#endif
