#include <iostream>
#include <sstream>

const int MIN_SPEED = 0;
const int MAX_SPEED = 150;
const float COMPARED_DELTA = 0.01f;

float checkSpeed (float currSpeed, float delta) {
	return (currSpeed + delta >= MAX_SPEED - COMPARED_DELTA) ? MAX_SPEED : (currSpeed + delta > MIN_SPEED + COMPARED_DELTA) ? (currSpeed + delta) : MIN_SPEED;
}

int main() {
  std::cout << "\t\tВводите числовое значение для увеличение скорости.\n\t\tДля уменьшения скорости число должно быть отрицательным.\n";
  std::stringstream currentSpeed;
  float speed = MIN_SPEED;
	float delta = 0.0f;
	do {
		std::cout << "Ввод дельты: "; 
    std::cin >> delta;
		currentSpeed << checkSpeed(speed, delta) << " км/ч";
		std::cout << "Текущая скорость: " << currentSpeed.str() << std::endl;
		currentSpeed >> speed;
		currentSpeed.str("");
	} while (speed > MIN_SPEED + COMPARED_DELTA);
	std::cout << "Остановка";
}

/*
Спидометр
Надо реализовать цифровой спидометр автомобиля. Сама модель автомобиля, которую нужно будет воссоздать весьма проста. Начальная скорость - 0 км/ч. Пользователь вводит в стандартный ввод разницу (дельту) в скорости и результирующая скорость показывается на спидометре в стандартный вывод. Так происходит до той поры, пока машина снова не остановится, т.е. пока скорость не станет меньше или равна нулю (сравнение должно происходить с дельтой в 0.01). Диапазон возможных значений скорости машины от 0 до 150 км/ч. Сам показатель спидометра, вместе с единицами измерения, требуется записывать в отдельную строку-буфер, которая потом и будет показываться на экране. Точность отображения скорость до 0.1 км/ч.
*/