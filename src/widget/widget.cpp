#include "widget.hpp"
#include "ui_Widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPointer>
#include <QPushButton>
#include <QSlider>

#include "player/player.hpp"
#include "enemy/enemy.hpp"
#include "healing/healing.hpp"
#include "health_bar/health_bar.hpp"

Widget::Widget(QWidget *parent)
: QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    //
    auto* player = new Player(100);
    auto* enemy = new Enemy(10);
    auto* healing = new Healing(10);
    //
    QPointer healthBar = new HealthBar(50);
    healthBar->setRange(0, player->maxHealth_);
    healthBar->setValue(player->maxHealth_);
    healthBar->setTextVisible(false);
    //
    QPointer healthBarCaption = new QLabel;
    healthBarCaption->setText("Health bar");
    //
    QPointer damageButton = new QPushButton;
    damageButton->setText("Deal damage");
    //
    QPointer restoreButton = new QPushButton;
    restoreButton->setText("Restore health");
    //
    QPointer thresholdSlider = new QSlider;
    thresholdSlider->setRange(10, player->maxHealth_ - 10);
    thresholdSlider->setValue(50);
    //
    QPointer thresholdLabel = new QLabel;
    thresholdLabel->setNum(50);
    //
    auto* widgetLayout = new QGridLayout;
    widgetLayout->addWidget(healthBarCaption, 0, 0);
    widgetLayout->addWidget(healthBar, 0, 1);
    widgetLayout->addWidget(damageButton, 1, 0, 1, 1);
    widgetLayout->addWidget(restoreButton, 1, 1, 1, 1);
    widgetLayout->addWidget(thresholdSlider, 0, 2, 2, 1);
    widgetLayout->addWidget(thresholdLabel, 0, 3, 2, 1);
    auto* widget = new QWidget;
    widget->setLayout(widgetLayout);
    // Spacing
    auto* topSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    auto* bottomSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    //
    auto* mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    mainLayout->addItem(topSpacer);
    mainLayout->addWidget(widget);
    mainLayout->addItem(bottomSpacer);
    // Damage dealing
    connect(damageButton, &QPushButton::clicked, enemy, &Enemy::OnDamageButtonClicked);
    connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
    // Health restoration
    connect(restoreButton, &QPushButton::clicked, healing, &Healing::OnRestoreButtonClicked);
    connect(healing, &Healing::Restore, player, &Player::RestoreHealth);
    // Health bar changes
    connect(player, &Player::HealthChanged, healthBar, &HealthBar::setHealth);
    // Threshold
    connect(thresholdSlider, &QSlider::valueChanged, thresholdLabel,
            static_cast<void (QLabel::*)(int)>(&QLabel::setNum)); // Manual overload resolution
    connect(thresholdSlider, &QSlider::valueChanged, healthBar, &HealthBar::setThreshhold);
}

Widget::~Widget() { delete ui; }
