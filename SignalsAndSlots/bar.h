#ifndef BAR_H
#define BAR_H

#include <QObject>
#include <QProgressBar>
#include <QWidget>

class Bar : public QProgressBar {
  Q_OBJECT
 public:
  explicit Bar(QString danStyle, QString norStyle,
               QProgressBar *parent = nullptr);
 public slots:
  void SetColor(int health, int percent, const QString danStyle,
                const QString norStyle);

 private:
  QString dangerStyle_;
  QString normalStyle_;
};

#endif  // BAR_H
