#include <iostream>
#include <cmath>

class Rectangle {
private:
    struct Point {
        double x, y;
    };

    Point topLeft;     // Левая верхняя точка (вершина) прямоугольника
    Point bottomRight; // Правая нижняя точка (основание) прямоугольника

public:
    // Конструктор класса Rectangle
    Rectangle(double x1, double y1, double x2, double y2) {
        topLeft.x = x1;
        topLeft.y = y1;
        bottomRight.x = x2;
        bottomRight.y = y2;
    }

    // Метод для вычисления площади прямоугольника
    double getArea() const {
        return std::abs((topLeft.x - bottomRight.x) * (topLeft.y - bottomRight.y));
    }

    // Метод для вывода координат и площади прямоугольника
    void display() const {
        std::cout << "Top Left: (" << topLeft.x << ", " << topLeft.y << ")\n";
        std::cout << "Bottom Right: (" << bottomRight.x << ", " << bottomRight.y << ")\n";
        std::cout << "Area: " << getArea() << "\n";
    }
};

int main() {
    // Создаем объекты прямоугольников
    Rectangle rect1(0.0, 0.0, 4.0, 3.0);
    Rectangle rect2(-1.0, -2.0, 3.0, 1.0);

    // Выводим параметры прямоугольников
    std::cout << "Rectangle 1:\n";
    rect1.display();
    std::cout << "\n";

    std::cout << "Rectangle 2:\n";
    rect2.display();

    return 0;
}

