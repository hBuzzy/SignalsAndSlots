#ifndef HEALING_HPP
#define HEALING_HPP

#include <QObject>

class Healing : public QObject {
    Q_OBJECT
public:
    explicit Healing(int restored, QObject *parent = nullptr);
signals:
    void Restore(int restored);
public slots:
    void OnRestoreButtonClicked();
private:
    int restored_;
};

#endif
