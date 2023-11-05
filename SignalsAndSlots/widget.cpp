#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>

#include "bar.h"
#include "god.h"
#include "player.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  int maxHealth = 100;
  int damage = 5;
  int restore = 5;

  QString kDangerStyle =
          "QProgressBar::chunk {background: #E6E6FA; Width: 20px; margin: 0.5px;"
          "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
          "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
          "color:black;}";
     QString kNormalStyle =
        "QProgressBar::chunk {background: #FFC0CB; Width: 20px; margin: 0.5px; "
        "border: 1px solid black; border-radius:8px; Border-Radius: 4px;} "
        "QProgressBar { text-align: center; font-size:14px; border-radius:8px; "
        "color:black;}";

  Player *player = new Player(maxHealth);
  God *enemy = new God(damage,restore);

  int minValue = 0;
  Bar *healthBar = new Bar(kDangerStyle,kNormalStyle);
  healthBar->setRange(minValue, player->GetMaxHealth());
  healthBar->setValue(player->GetMaxHealth());
  healthBar->setTextVisible(false);
  healthBar->setStyleSheet(kNormalStyle);
  QPointer<QLabel> indexHp = new QLabel;
  indexHp->setText("Уровень здоровья");

  myhealthSlider_ = new QSlider(Qt::Horizontal);
  myhealthSlider_->setValue(player->GetMaxHealth());
  QPointer<QLabel> myhealthSliderCaption = new QLabel;
  myhealthSliderCaption->setNum(player->GetMaxHealth());

  QPointer<QPushButton> damageButton = new QPushButton;
  damageButton->setText("Нанести урон");

  QPointer<QPushButton> restoreButton = new QPushButton;
  restoreButton->setText("Восстановить здоровье");

  QWidget *widget = new QWidget;
  QGridLayout *widgetLayout = new QGridLayout;

  widgetLayout->addWidget(myhealthSliderCaption, 0, 0);
  widgetLayout->addWidget(myhealthSlider_, 0, 1);
  widgetLayout->addWidget(indexHp, 1, 0);
  widgetLayout->addWidget(healthBar, 1, 1);
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

  connect(damageButton, &QPushButton::clicked, enemy,&God::OnDamageButtonClicked);
  connect(enemy, &God::MakeDamage, player, &Player::TakeDamage);
  connect(restoreButton, &QPushButton::clicked, enemy,&God::OnRestoreButtonClicked);
  connect(enemy, &God::MakeRestore, player, &Player::TakeRestore);
  connect(player, &Player::HealthChanged, healthBar, &QProgressBar::setValue);
  connect(  myhealthSlider_, &QSlider::valueChanged,
          [  myhealthSliderCaption](int value) {   myhealthSliderCaption->setText(QString("%1 HP ").arg(value)); }
  );

 connect(myhealthSlider_, &QSlider::valueChanged, healthBar, [=](int value) {
      healthBar->SetColor(healthBar->value(),value,kDangerStyle,kNormalStyle);
      myhealthSliderCaption->setNum(value);
  });

 connect(healthBar, &QProgressBar::valueChanged, myhealthSlider_,[=](int value){
 healthBar->SetColor(value,myhealthSlider_->value(),kDangerStyle,kNormalStyle);
  });
}

Widget::~Widget() { delete ui; }
