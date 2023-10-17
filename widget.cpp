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
  int minHealth = 25;

//  создаем элементы виджета

  NewProgressBar *healthBar = new NewProgressBar(minHealth);
  healthBar->ChangeColor(player->GetCurrentHealth());
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QLabel> minHealthCaption = new QLabel;
  minHealthCaption->setText(QString::number(minHealth));

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> restoreButton = new QPushButton;
  restoreButton->setText("Лечиться");

  QPointer<QSlider> minHealthSlider = new QSlider(Qt::Horizontal);
  minHealthSlider->setRange(0, 100);
  minHealthSlider->setPageStep(5);
  minHealthSlider->setTickInterval(5);
  minHealthSlider->setValue(25);
  minHealthSlider->setTickPosition(QSlider::TicksBothSides);
  QObject::connect(minHealthSlider, SIGNAL(valueChanged(int)), minHealthCaption, SLOT(setNum(int)));

//  создаем виджет и крепим на него элементы

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthBarCaption, 0, 0);
  widgetLayout->addWidget(healthBar, 0, 1);
  widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
  widgetLayout->addWidget(restoreButton, 2, 0, 1, 2);
  widgetLayout->addWidget(minHealthCaption, 3, 0);
  widgetLayout->addWidget(minHealthSlider, 3, 1);

  widget->setLayout(widgetLayout);

//  красиво располагаем элементы н виджете

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

//  связываем действия между собой

  connect(damageButton, &QPushButton::clicked, enemy,
          &Enemy::OnDamageButtonClicked);
  connect(restoreButton, &QPushButton::clicked, player,
          &Player::OnRestoreButtonClicked);
  connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
  connect(player, &Player::HealthChanged, healthBar, &NewProgressBar::setValue);
  connect(player, &Player::HealthChanged, healthBar, &NewProgressBar::ChangeColor);
  connect(minHealthSlider, SIGNAL(valueChanged(int)), healthBar, SLOT(setMinHealth(int)));
}

Widget::~Widget() { delete ui; }
