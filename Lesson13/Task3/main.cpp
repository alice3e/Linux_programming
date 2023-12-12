#include <iostream>
#include <cmath>

class Triangle {
private:
    struct Point {
        double x, y, z;
    };

    Point vertex1;  // Первая вершина треугольника
    Point vertex2;  // Вторая вершина треугольника
    Point vertex3;  // Третья вершина треугольника

public:
    // Конструктор класса Triangle
    Triangle(double x1, double y1, double z1,
             double x2, double y2, double z2,
             double x3, double y3, double z3) {
        vertex1.x = x1;
        vertex1.y = y1;
        vertex1.z = z1;

        vertex2.x = x2;
        vertex2.y = y2;
        vertex2.z = z2;

        vertex3.x = x3;
        vertex3.y = y3;
        vertex3.z = z3;
    }

    // Метод для вычисления площади треугольника
    double getArea() const {
        // Используем формулу Герона для вычисления площади треугольника в трехмерном пространстве
        double side1 = std::sqrt(std::pow(vertex2.x - vertex1.x, 2) + std::pow(vertex2.y - vertex1.y, 2) + std::pow(vertex2.z - vertex1.z, 2));
        double side2 = std::sqrt(std::pow(vertex3.x - vertex2.x, 2) + std::pow(vertex3.y - vertex2.y, 2) + std::pow(vertex3.z - vertex2.z, 2));
        double side3 = std::sqrt(std::pow(vertex1.x - vertex3.x, 2) + std::pow(vertex1.y - vertex3.y, 2) + std::pow(vertex1.z - vertex3.z, 2));

        double s = 0.5 * (side1 + side2 + side3); // Полупериметр треугольника
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Метод для вывода координат и площади треугольника
    void display() const {
        std::cout << "Vertex 1: (" << vertex1.x << ", " << vertex1.y << ", " << vertex1.z << ")\n";
        std::cout << "Vertex 2: (" << vertex2.x << ", " << vertex2.y << ", " << vertex2.z << ")\n";
        std::cout << "Vertex 3: (" << vertex3.x << ", " << vertex3.y << ", " << vertex3.z << ")\n";
        std::cout << "Area: " << getArea() << "\n";
    }
};

int main() {
    // Создаем объект треугольника
    Triangle triangle(0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Выводим параметры треугольника
    std::cout << "Triangle:\n";
    triangle.display();

    return 0;
}

