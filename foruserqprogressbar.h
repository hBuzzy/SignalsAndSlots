#ifndef FORUSERQPROGRESSBAR_H
#define FORUSERQPROGRESSBAR_H

#include <QProgressBar>
#include <QObject>

class forUserQProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit forUserQProgressBar(QProgressBar *parent = nullptr);

signals:

};

#endif // FORUSERQPROGRESSBAR_H
