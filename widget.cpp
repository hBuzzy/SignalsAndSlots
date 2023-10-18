#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>

#include "enemy.h"
#include "player.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  Player *player = new Player(100);
  Enemy *enemy = new Enemy(10);

  QProgressBar *healthBar = new QProgressBar;
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> healthButton = new QPushButton;
  healthButton->setText("Восстановить здоровье");


  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthBarCaption, 0, 0);
  widgetLayout->addWidget(healthBar, 0, 1);
  widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
  widgetLayout->addWidget(healthButton, 4, 0, 4, 2);



  widget->setLayout(widgetLayout);

  int spacerWidth = 1;
  int spacerHeight = 1;
  QSpacerItem *topSpacer = new QSpacerItem(
      spacerWidth, spacerHeight, QSizePolicy::Minimum, QSizePolicy::Expanding);
  QSpacerItem *bottomSpacer = new QSpacerItem(
      spacerWidth, spacerHeight, QSizePolicy::Minimum, QSizePolicy::Expanding);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  setLayout(mainLayout);

  mainLayout->addItem(topSpacer);
  mainLayout->addWidget(widget);
  mainLayout->addItem(bottomSpacer);


  connect(damageButton, &QPushButton::clicked, enemy,
          &Enemy::OnDamageButtonClicked);
  connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
  connect(player, &Player::HealthChanged, healthBar, &QProgressBar::setValue);

  connect(healthButton, &QPushButton::clicked, enemy,
            &Enemy::OnHealthButtonClicked);

  const QString dangerStyle =
      "QProgressBar::chunk {background: #F44336; Width: 20px; margin: 0.5px;"
      "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
      "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
      "color:black;}";

  const QString normalStyle =
      "QProgressBar::chunk {background: #009688; Width: 20px; margin: 0.5px; "
      "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
      "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
      "color:black;}";
  healthBar ->setStyleSheet(normalStyle);

}

Widget::~Widget() { delete ui; }
