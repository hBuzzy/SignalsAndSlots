#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QPushButton>

#include "enemy.h"
#include "heal.h"
#include "player.h"
#include "ui_widget.h"
#include "customprogressbar.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  Player *player = new Player(100);
  Enemy *enemy = new Enemy(10);
  Heal *heal = new Heal(5);

  CustomProgressBar *healthBar = new CustomProgressBar;
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  QSlider *healthSlider = new QSlider(Qt::Horizontal, this);
  healthSlider->setMinimum(25);
  healthSlider->setMaximum(75);

  QPointer<QLabel> changingColorLabel = new QLabel("25",healthSlider);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> healButton = new QPushButton;
  healButton->setText("Подлечить");

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(changingColorLabel, 0, 0);
  widgetLayout->addWidget(healthSlider, 0, 1);
  widgetLayout->addWidget(healthBarCaption, 1, 0);
  widgetLayout->addWidget(healthBar, 1, 1);
  widgetLayout->addWidget(damageButton, 2, 0, 1, 2);
  widgetLayout->addWidget(healButton, 3, 0, 1, 2);

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

  connect(healthSlider,  &QSlider::valueChanged, changingColorLabel,
          [changingColorLabel](int value){(changingColorLabel->setText(QString::number(value)));});
  connect(damageButton, &QPushButton::clicked, enemy,
          &Enemy::OnDamageButtonClicked);
  connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
  connect(healButton, &QPushButton::clicked, heal,
          &Heal::OnHealButtonClicked);
  connect(heal, &Heal::MakeHealPoint, player, &Player::TakeHeal);
  connect(player, &Player::HealthChanged, healthBar, &CustomProgressBar::setValue);
  connect(healthSlider, &QSlider::valueChanged, healthBar, &CustomProgressBar::ChangeCriticalValue);
  connect(healthBar, &CustomProgressBar::valueChanged, healthBar, &CustomProgressBar::ChangeColor);

}

Widget::~Widget() { delete ui; }
