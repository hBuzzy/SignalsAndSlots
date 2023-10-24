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
#include "progressBar.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    Player *player = new Player(100, 20);
    Enemy *enemy = new Enemy(10);
    int indicativeValue_ = 20;

    ProgressBar *healthBar = new ProgressBar(indicativeValue_);
    healthBar->SetCurrentValue(player->GetCurrentHealth());
    int minValue = 0;
    healthBar->setRange(minValue, player->GetMaxHealth());
    healthBar->setValue(player->GetMaxHealth());
    healthBar->setTextVisible(false);

    QPointer<QLabel> healthBarCaption = new QLabel;
    healthBarCaption->setText("Полоска здоровья");

    QPointer<QLabel> indicativeValueCaption = new QLabel;
    indicativeValueCaption->setText(QString::number(indicativeValue_));

    QPointer<QPushButton> damageButton = new QPushButton;
    damageButton->setText("Нанести урон");

    QPointer<QPushButton> restoreButton = new QPushButton;
    restoreButton->setText("Восстановить здоровье");

    QPointer<QSlider> indicativeValueSlider = new QSlider(Qt::Horizontal);
    indicativeValueSlider->setRange(0, 100);
    indicativeValueSlider->setPageStep(5);
    indicativeValueSlider->setTickInterval(5);
    indicativeValueSlider->setValue(20);
    indicativeValueSlider->setTickPosition(QSlider::TicksBothSides);
    connect(indicativeValueSlider, SIGNAL(valueChanged(int)), indicativeValueCaption, SLOT(setNum(int)));

    QWidget *widget = new QWidget;
    QGridLayout *widgetLayout = new QGridLayout;

    widgetLayout->addWidget(healthBarCaption, 0, 0);
    widgetLayout->addWidget(healthBar, 0, 1);
    widgetLayout->addWidget(damageButton, 1, 0);
    widgetLayout->addWidget(restoreButton, 1, 1);
    widgetLayout->addWidget(indicativeValueCaption, 3, 0);
    widgetLayout->addWidget(indicativeValueSlider, 3, 1);

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

    connect(damageButton, SIGNAL(clicked(void)), enemy, SLOT(OnDamageButtonClicked(void)));
    connect(restoreButton, SIGNAL(clicked(void)), player, SLOT(TakeHeal(void)));
    connect(enemy, SIGNAL(MakeDamage(int)), player, SLOT(TakeDamage(int)));
    connect(player, SIGNAL(HealthChanged(int)), healthBar, SLOT(SetCurrentValue(int)));
    connect(indicativeValueSlider, SIGNAL(valueChanged(int)), healthBar, SLOT(SetIndicativeValue(int)));
    connect(indicativeValueSlider, &QSlider::valueChanged, player, &Player::UpgradeHealth);
    //строчка ниже - почему-то не срабатывает переключение цвета при движении ползунка, в актуальной на момент написания комментария версии
    // за переключение отвечает строка перед комментарием
//    connect(indicativeValueSlider, SIGNAL(valueChanged()), player, SLOT(UpgradeHealth()));

}

Widget::~Widget() { delete ui; }
