#ifndef BAR_H
#define BAR_H

#include <QObject>
#include <QProgressBar>
#include <QWidget>

class Bar: public QProgressBar {
    Q_OBJECT
public:
    Bar();

public slots:
 void SetColor(int health, int percent);
};

#endif // BAR_H
