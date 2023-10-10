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
#include "userprogressbar.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  Player *player = new Player(100, 10);
  Enemy *enemy = new Enemy(10);

  UserProgressBar *healthBar = new UserProgressBar(50);
  int minValue = 0;
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);

  QPointer<QLabel> healthBarCaption = new QLabel;
  healthBarCaption->setText("Полоска здоровья");

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> recoverButton = new QPushButton;
  recoverButton->setText("Восстановить здоровье");

  QPointer<QSlider> healthSlider = new QSlider(Qt::Horizontal);
  healthSlider->setPageStep(1);
  healthSlider->setValue(40);

  QPointer<QLabel> healthValueCaption = new QLabel;
  healthValueCaption->setText(QString::number(healthSlider->value()));

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(healthValueCaption, 0, 0, 1, 2);
  widgetLayout->addWidget(healthSlider, 0, 1, 1, 2);
  widgetLayout->addWidget(healthBarCaption, 1, 0);
  widgetLayout->addWidget(healthBar, 1, 1);
  widgetLayout->addWidget(damageButton, 2, 0, 1, 2);
  widgetLayout->addWidget(recoverButton, 3, 0, 1, 2);

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
  connect(recoverButton, &QPushButton::clicked, player,
          &Player::OnRecoverButtonClicked);
  connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
  connect(player, &Player::HealthChanged, healthBar, &QProgressBar::setValue);
  connect(healthSlider, &QSlider::valueChanged, [healthValueCaption](int value) {
      healthValueCaption->setText(QString::number(value));
  });
  connect(healthSlider, &QSlider::valueChanged, healthBar,
            &UserProgressBar::SetRequiredValue);
  connect(healthBar, &UserProgressBar::RequiredValueChanged, healthBar,
            &UserProgressBar::UpdateColor);
  connect(player, &Player::HealthChanged, healthBar,
            &UserProgressBar::UpdateColor);
}

Widget::~Widget() { delete ui; }
