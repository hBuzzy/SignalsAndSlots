#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>

#include "custom_progress_bar.h"
#include "enemy.h"
#include "player.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  Player *player = new Player(100);
  Enemy *enemy = new Enemy(10, 5);

  CustomProgressBar *healthBar = new CustomProgressBar(20, 100);
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QSlider *healthSlider = new QSlider(Qt::Horizontal);
  healthSlider->setRange(minValue, player->GetMaxHealth());
  healthSlider->setValue(player->GetMaxHealth());

  QPointer<QLabel> healthSliderCaption = new QLabel;
  healthSliderCaption->setText(QString::number(healthSlider->value()));

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");
  QPointer<QPushButton> healButton = new QPushButton;
  healButton->setText("Восстановить");


  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthBarCaption, 0, 0);
  widgetLayout->addWidget(healthBar, 0, 1);
  widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
  widgetLayout->addWidget(healButton, 2, 0, 1, 2);
  widgetLayout->addWidget(healthSliderCaption, 3, 0);
  widgetLayout->addWidget(healthSlider, 3, 1);
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
  connect(healButton, &QPushButton::clicked, enemy,
          &Enemy::OnHealthButtonClicked);
  connect(enemy, &Enemy::MakeDamage, [player, healthBar](int damage) {player->TakeDamage(damage); healthBar->setLifeCount(player->GetCurrentHealth());});
  connect(enemy, &Enemy::MakeHealth, [player, healthBar](int health) {player->TakeHealth(health); healthBar->setLifeCount(player->GetCurrentHealth());});
  connect(player, &Player::HealthChanged, healthBar, &QProgressBar::setValue);
  connect(healthSlider, &QSlider::valueChanged, healthBar, &CustomProgressBar::setLifeThreshold);
}

Widget::~Widget() { delete ui; }
