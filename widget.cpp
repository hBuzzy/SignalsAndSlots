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
  int demage = 10;
  int restore = 5;

  Player *player = new Player(maxHealth);
  Enemy *enemy = new Enemy(demage);
  Enemy *myenemy = new Enemy(restore);

  QProgressBar *healthBar = new QProgressBar;
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  Bar *myhealthBar = new Bar;
  myhealthBar->setRange(minValue, player->GetMaxHealth());
  myhealthBar->setValue(player->GetMaxHealth());
  myhealthBar->setTextVisible(false);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QSlider *myhealthSlider = new QSlider(Qt::Horizontal);
  myhealthSlider->setValue(player->GetMaxHealth());

  QPointer<QLabel> myhealthSliderCaption = new QLabel;
  myhealthSliderCaption->setNum(player->GetMaxHealth());

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> restoreButton = new QPushButton;
  restoreButton->setText("Восстановление");

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(myhealthSliderCaption, 0, 0);
  widgetLayout->addWidget(myhealthSlider, 0, 1);
  widgetLayout->addWidget(healthBarCaption, 1, 0);
  widgetLayout->addWidget(myhealthBar, 1, 1);
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

  connect(restoreButton, &QPushButton::clicked, myenemy,
          &Enemy::OnRestoreButtonClicked);
  connect(myenemy, &Enemy::MakeRestore, player, &Player::TakeRestore);

  connect(myhealthSlider, &QSlider::valueChanged, player, &Player::SetHealth);
  connect(myhealthSlider, &QSlider::valueChanged,
          [myhealthSliderCaption](int value) {
            myhealthSliderCaption->setNum(value);
          });
  connect(myhealthBar, &QProgressBar::valueChanged, player, &Player::SetHealth);
  connect(myhealthBar, &QProgressBar::valueChanged, myhealthBar,
          &Bar::SetColor);
  connect(player, &Player::HealthChanged, myhealthBar, &QProgressBar::setValue);
  connect(player, &Player::HealthChanged, myhealthSlider, &QSlider::setValue);
}

Widget::~Widget() { delete ui; }
