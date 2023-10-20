#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>

#include "bar.h"
#include "enemy.h"
#include "player.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  int maxHealth = 100;
  int damage = 10;
  int restore = 5;
  int criticalHealth = 50;

  Player *player = new Player(maxHealth);
  Enemy *enemy = new Enemy(damage, restore);

  QProgressBar *healthBar = new QProgressBar;
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  Bar *myHealthBar = new Bar;
  myHealthBar->setRange(minValue, player->GetMaxHealth());
  myHealthBar->setValue(player->GetMaxHealth());
  myHealthBar->setTextVisible(false);
  myHealthBar->SetCriticalHealth(criticalHealth);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QSlider *myHealthSlider = new QSlider(Qt::Horizontal);
  myHealthSlider->setValue(criticalHealth);

  QPointer<QLabel> myCriticalHealth = new QLabel;
  myCriticalHealth->setNum(criticalHealth);

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> restoreButton = new QPushButton;
  restoreButton->setText("Восстановление");

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(myCriticalHealth, 0, 0);
  widgetLayout->addWidget(myHealthSlider, 0, 1);
  widgetLayout->addWidget(healthBarCaption, 1, 0);
  widgetLayout->addWidget(myHealthBar, 1, 1);
  widgetLayout->addWidget(damageButton, 2, 0, 1, 2);
  widgetLayout->addWidget(restoreButton, 3, 0, 1, 2);
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

  connect(restoreButton, &QPushButton::clicked, enemy,
          &Enemy::OnRestoreButtonClicked);
  connect(enemy, &Enemy::MakeRestore, player, &Player::TakeRestore);

  connect(myHealthSlider, &QSlider::valueChanged, myHealthBar,
          &Bar::SetCriticalHealth);
  connect(myHealthSlider, &QSlider::valueChanged,
          [myCriticalHealth](int value) { myCriticalHealth->setNum(value); });
  connect(myHealthBar, &Bar::valueChanged, myHealthBar, &Bar::SetColor);
  connect(player, &Player::HealthChanged, myHealthBar, &QProgressBar::setValue);
}

Widget::~Widget() { delete ui; }
