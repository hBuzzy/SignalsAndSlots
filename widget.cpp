#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPointer>
#include <QProgressBar>
#include <QPushButton>

#include "enemy.h"
#include "player.h"
#include "ui_widget.h"
#include "customprogressbar.h"


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    Player *player = new Player(100);
    Enemy *enemy = new Enemy(10);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    QLabel *label = new QLabel("Пороговое значение здоровья: " + QString::number(player->GetMaxHealth()/2));

    int minValue = 0;
    CustomProgressBar *healthBar = new CustomProgressBar;
    healthBar->setRange(0, 100);
    healthBar->setValue(100);
    healthBar->setValue(player->GetCurrentHealth());
    healthBar->setRange(minValue, player->GetMaxHealth());
    healthBar->setValue(player->GetMaxHealth());
    healthBar->setTextVisible(false);

    QPointer<QLabel> healthBarCaption = new QLabel;
    healthBarCaption->setText("Полоска здоровья");

    QPointer<QPushButton> damageButton = new QPushButton;
    damageButton->setText("Нанести урон");

    QPointer<QPushButton> healButton = new QPushButton;
    healButton->setText("Восстановить здоровье");

    QWidget *widget = new QWidget;
    QGridLayout *widgetLayout = new QGridLayout;

    widgetLayout->addWidget(healthBarCaption, 0, 0);
    widgetLayout->addWidget(healthBar, 0, 1);
    widgetLayout->addWidget(damageButton, 1, 0, 1, 2);
    widgetLayout->addWidget(healButton, 2, 0, 1, 2);
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
    connect(slider, &QSlider::valueChanged, this, [label](int value) {
        label->setText("Пороговое значение здоровья: " + QString::number(value));
    });
    connect(slider, &QSlider::valueChanged, healthBar, &CustomProgressBar::SetThreshold);
    connect(damageButton, &QPushButton::clicked, enemy, &Enemy::OnDamageButtonClicked);
    connect(enemy, &Enemy::MakeDamage, player, &Player::TakeDamage);
    connect(healButton, &QPushButton::clicked, player, &Player::Heal);
    connect(player, &Player::HealthChanged, healthBar, &CustomProgressBar::setValue);
}


Widget::~Widget() { delete ui; }
