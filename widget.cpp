#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QSlider>
#include <QPushButton>

#include "customprogressbar.h"
#include "enemy.h"
#include "player.h"
#include "ui_widget.h"
#include "recovery.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  Player *player = new Player(100);
  Enemy *enemy = new Enemy(5);
  Recovery *recovery = new Recovery(5);

  CustomProgressBar *healthBar = new CustomProgressBar;
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);


  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QSlider> slider = new QSlider(Qt::Horizontal, this);

  QPointer<QLabel> currentThresh = new QLabel("0", slider);

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> recoveryButton = new QPushButton;
  recoveryButton->setText("Восстановить здоровье");

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthBarCaption, 0, 0);
  widgetLayout->addWidget(currentThresh, 3, 1, 1, 2);
  widgetLayout->addWidget(slider, 3, 2, 1, 2);
  widgetLayout->addWidget(healthBar, 0, 1);
  widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
  widgetLayout->addWidget(recoveryButton, 2, 0, 1, 2);

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

  connect(slider, &QSlider::valueChanged, currentThresh, qOverload<int>(&QLabel::setNum));
  connect(slider, &QSlider::valueChanged, healthBar, &CustomProgressBar::SetValue);
  connect(damageButton, &QPushButton::clicked, enemy, &Enemy::OnDamageButtonClicked);
  connect(recoveryButton, &QPushButton::clicked, recovery, &Recovery::OnHealButtonClicked);
  connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
  connect(recovery, &Recovery::HealDamage, player, &Player::RecoveryHealth);
  connect(player, &Player::HealthChanged, healthBar, &CustomProgressBar::setValue);
  connect(healthBar,&CustomProgressBar::valueChanged, healthBar, &CustomProgressBar::ChangeColor);
}

Widget::~Widget() { delete ui; }
