#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>

#include "enemy.h"
#include "potion.h"
#include "player.h"
#include "ui_widget.h"

#include "customprogressbar.h"



Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

  Player *player = new Player(100);
  Enemy *enemy = new Enemy(10);
  Potion *potion = new Potion(10);

  healthBar_ = new CustomProgressBar;
  int minValue = 0;
  healthBar_->setRange(minValue, player->GetMaxHealth());
  healthBar_->setValue(player->GetMaxHealth());
  healthBar_->setTextVisible(false);

  thresholdLabel_ = new QLabel;
  thresholdLabel_->setText("Порог: 50");

  QPointer<QSlider> thresholdSlider = new QSlider;
  thresholdSlider->setRange(minValue, player->GetMaxHealth());

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> healButton = new QPushButton;
  healButton->setText("Восстановить здоровье");

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthBarCaption, 0, 0);
  widgetLayout->addWidget(healthBar_, 0, 1);
  widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
  widgetLayout->addWidget(healButton, 2, 0, 1, 2);

  widgetLayout->addWidget(thresholdSlider, 3, 0, 1, 2);
  widgetLayout->addWidget(thresholdLabel_, 4, 0, 1, 2);
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
  connect(player, &Player::HealthChanged, healthBar_,
          &CustomProgressBar::setValue);
  connect(healButton, &QPushButton::clicked, player, &Player::Heal);
  connect(healButton, &QPushButton::clicked, potion,
          &Potion::OnHealButtonClicked);
  connect(potion, &Potion::MakeHeal, player, &Player::Heal);
  connect(thresholdSlider, &QSlider::valueChanged, this,
          &Widget::UpdateThreshold);

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
}

void Widget::UpdateThreshold(int value) {
    customProgressBar_->SetColorThreshold(value);
    // thresholdLabel_->setText(QString::number(value)); Почему не работает?
}

Widget::~Widget() { delete ui; }
