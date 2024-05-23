#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Базовый класс "Транспортное средство".
 */
class Transport {
public:
    /**
     * @brief Виртуальный метод для получения информации о транспортном средстве.
     *
     * @return Строка с информацией о транспортном средстве.
     */
    virtual string getInfo() = 0;

    /**
     * @brief Виртуальный метод для движения транспортного средства.
     */
    virtual void move() = 0;
};

/**
 * @brief Класс "Мотоцикл".
 *
 * @image html motorbike.png width=500cm
 */
class motorbike : public Transport {
public:
    /**
     * @brief Конструктор класса motorbike.
     *
     * @param brand Марка мотоцикла.
     * @param model Модель мотоцикла.
     */
    motorbike(string brand, string model);

    /**
     * @brief Метод для получения информации о мотоцикле.
     *
     * @return Строка с информацией о мотоцикле.
     */
    string getInfo() override;

    /**
     * @brief Метод для движения мотоцикла.
     */
    void move() override;

private:
    string brand; /**< Марка мотоцикла. */
    string model; /**< Модель мотоцикла. */
};

motorbike::motorbike(string brand, string model) : brand(brand), model(model) {}

string motorbike::getInfo() {
    return "Мотоцикл: " + brand + " " + model;
}

void motorbike::move() {
    cout << "Мотоцикл едет." << endl;
}

/**
 * @brief Класс "Самокат".
 *
 * @dot
 * digraph inheritance {
 *     node [shape=record, fontname=Helvetica, fontsize=10];
 *     Transport [label="{Transport|+ getInfo() : string\l+ move() : void\l}"];
 *     Scooter [label="{Scooter|+ Scooter(brand : string, electric : bool)\l+ getInfo() : string\l+ move() : void\l}"];
 *     Transport -> Scooter;
 * }
 * @enddot
 */
class Scooter : public Transport {
public:
    /**
     * @brief Конструктор класса Scooter.
     *
     * @param brand Марка самоката.
     * @param electric Электрический самокат или нет.
     */
    Scooter(string brand, bool electric);

    /**
     * @brief Метод для получения информации о самокате.
     *
     * @return Строка с информацией о самокате.
     */
    string getInfo() override;

    /**
     * @brief Метод для движения самоката.
     */
    void move() override;

private:
    string brand; /**< Марка самоката. */
    bool electric; /**< Электрический самокат или нет. */
};

Scooter::Scooter(string brand, bool electric) : brand(brand), electric(electric) {}

string Scooter::getInfo() {
    return "Самокат: " + brand + (electric ? " (электрический)" : " (неэлектрический)");
}

void Scooter::move() {
    cout << "Самокат едет." << endl;
}

/**
 * @brief Функция для вычисления средней скорости.
 *
 * Формула для вычисления средней скорости:
 * \f$ V = \frac{S}{T} \f$
 * где:
 * - \( V \) - средняя скорость,
 * - \( S \) - пройденное расстояние,
 * - \( T \) - время.
 *
 * @param distance Пройденное расстояние.
 * @param time Время.
 * @return Средняя скорость.
 */
double calculateAverageSpeed(double distance, double time) {
    return distance / time; // Функция для вычисления средней скорости
}

int main() {
    setlocale(LC_ALL, "Russian");
    motorbike motobike("Vaz", "Hendai");
    Scooter scooter("Xiaomi", true);

    cout << motobike.getInfo() << endl;
    motobike.move();

    cout << scooter.getInfo() << endl;
    scooter.move();

    // Пример использования функции для вычисления средней скорости
    double distance = 50; // Пройденное расстояние, км
    double time = 2; // Время, ч
    double averageSpeed = calculateAverageSpeed(distance, time);
    cout << "Средняя скорость: " << averageSpeed << " км/ч" << endl;

    return 0;
}
