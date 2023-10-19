#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>

#include "enemy.h"
#include "player.h"
#include "ui_widget.h"
#include "newProgressBar.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  Player *player = new Player(100, 25);
  Enemy *enemy = new Enemy(10);
  int triggerValue_ = 25;

  NewProgressBar *healthBar = new NewProgressBar(triggerValue_);
  healthBar->SetCurrentValue(player->GetCurrentHealth());
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QLabel> triggerValueCaption = new QLabel;
  triggerValueCaption->setText(QString::number(triggerValue_));

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> restoreButton = new QPushButton;
  restoreButton->setText("Лечиться");

  QPointer<QSlider> triggerValueSlider = new QSlider(Qt::Horizontal);
  triggerValueSlider->setRange(0, 100);
  triggerValueSlider->setPageStep(5);
  triggerValueSlider->setTickInterval(5);
  triggerValueSlider->setValue(25);
  triggerValueSlider->setTickPosition(QSlider::TicksBothSides);
  connect(triggerValueSlider, SIGNAL(valueChanged(int)), triggerValueCaption, SLOT(setNum(int)));

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthBarCaption, 0, 0);
  widgetLayout->addWidget(healthBar, 0, 1);
  widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
  widgetLayout->addWidget(restoreButton, 2, 0, 1, 2);
  widgetLayout->addWidget(triggerValueCaption, 3, 0);
  widgetLayout->addWidget(triggerValueSlider, 3, 1);

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
  connect(restoreButton, &QPushButton::clicked, player,
          &Player::TakeRestore);
  connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
  connect(player, &Player::HealthChanged, healthBar, &NewProgressBar::SetCurrentValue);
  connect(triggerValueSlider, &QSlider::valueChanged, healthBar, &NewProgressBar::SetTriggerValue);
}

Widget::~Widget() { delete ui; }
