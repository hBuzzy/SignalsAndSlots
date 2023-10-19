#ifndef FORUSERQPROGRESSBAR_H
#define FORUSERQPROGRESSBAR_H

#include <QProgressBar>
#include <QObject>

class ForUserQProgressBar : public QProgressBar
{
    Q_OBJECT
public:
    explicit ForUserQProgressBar(QProgressBar *parent = nullptr);

signals:

};

#endif // FORUSERQPROGRESSBAR_H
