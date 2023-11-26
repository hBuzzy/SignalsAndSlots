#ifndef RECOVERY_H
#define RECOVERY_H
#include <QObject>

class Recovery : public QObject
{
    Q_OBJECT
public:
    explicit Recovery(int heal, QObject *parent = nullptr);

signals:
 void HealDamage(int heal);

public slots:
 void OnHealButtonClicked();

private:
 int heal_;
};

#endif // RECOVERY_H
