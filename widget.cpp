#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>

#include "enemy.h"
#include "player.h"
#include "customprogressbar.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    Player *player = new Player(200);
    Enemy *enemy = new Enemy(10);

    CustomProgressBar *healthBar = new CustomProgressBar;
    int minValue = 0;
    int numbMiddle = 2;

    healthBar->setRange(minValue, player->GetMaxHealth());
    healthBar->setValue(player->GetMaxHealth());
    healthBar->setTextVisible(false);
    healthBar->SetThreshold(player->GetMaxHealth() / numbMiddle);

    QPointer<QLabel> healthBarCaption = new QLabel;
    healthBarCaption->setText("Полоска здоровья");

    QPointer<QPushButton> damageButton = new QPushButton;
    damageButton->setText("Нанести урон");

    QPointer<QPushButton> healButton = new QPushButton;
    healButton->setText("Восстановить здоровье");

    QWidget *widget = new QWidget;
    QGridLayout *widgetLayout = new QGridLayout;

    QLabel *labelHealth = new QLabel("Максимальное здоровье: " + QString::number(player->GetMaxHealth()));
    QSlider *slider = new QSlider;
    slider->setValue(player->GetMaxHealth() / numbMiddle);
    slider->setRange(0, player->GetMaxHealth());
    QLabel *label = new QLabel("Порог здоровья: " + QString::number(player->GetMaxHealth()/2));

    widgetLayout->addWidget(labelHealth);
    widgetLayout->addWidget(healthBarCaption, 1, 0);
    widgetLayout->addWidget(healthBar, 1, 1);
    widgetLayout->addWidget(damageButton, 2, 0, 1, 2);
    widgetLayout->addWidget(healButton, 3, 0, 1, 2);
    widgetLayout->addWidget(slider);
    widgetLayout->addWidget(label);

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

    connect(player, &Player::HealthChanged, healthBar, &CustomProgressBar::setValue);

    connect(slider, &QSlider::valueChanged, this, [label](int value) {
        label->setText("Порог здоровья: " + QString::number(value));
    });

    connect(slider, &QSlider::valueChanged, healthBar, &CustomProgressBar::SetThreshold);

    connect(damageButton, &QPushButton::clicked, enemy,&Enemy::OnDamageButtonClicked);
    connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);

    connect(healButton, &QPushButton::clicked, enemy,&Enemy::OnHealButtonClicked);
    connect(enemy, &Enemy::MakeHeal, player, &Player::TakeHealth);

    connect(player, &Player::HealthChanged, healthBar, &CustomProgressBar::setValue);
}

Widget::~Widget() { delete ui; }
