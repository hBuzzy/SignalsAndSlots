#include "customprogressbar.h"

CustomProgressBar::CustomProgressBar(QWidget *parent) : QProgressBar(parent), colorThreshold_(50) {
    // Настройка начальных параметров бара
    setRange(0, 100); // Измените диапазон, если необходимо
    setValue(100);   // Установите начальное значение (полное здоровье)
    setFormat("%v%"); // Отображение текущего значения в процентах
    setTextVisible(true);

    // Соединение собственного слота updateColor с сигналом valueChanged
    connect(this, &QProgressBar::valueChanged, this, &CustomProgressBar::updateColor);
}

void CustomProgressBar::updateColor(int currentValue) {
    if (currentValue <= colorThreshold_) {
        // Меньше или равно порогу - красный
        setStyleSheet("QProgressBar::chunk { background-color: red; }");
    } else {
        // Больше порога - зеленый
        setStyleSheet("QProgressBar::chunk { background-color: green; }");
    }
}

void CustomProgressBar::setColorThreshold(int threshold) {
    colorThreshold_ = threshold;
    updateColor(value()); // Обновляем цвет на основе текущего значения бара
}

void CustomProgressBar::setColor(int currentValue) {
    if (currentValue <= 50) {
        // Меньше или равно 50% - красный
        setStyleSheet("QProgressBar::chunk { background-color: red; }");
    } else {
        // Больше 50% - зеленый
        setStyleSheet("QProgressBar::chunk { background-color: green; }");
    }
}
