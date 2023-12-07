#include <iostream>

class Point {
public:
    Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}

    double getX() const {
        return x_;
    }

    double getY() const {
        return y_;
    }

    double getZ() const {
        return z_;
    }

private:
    double x_;
    double y_;
    double z_;
};

int main() {
    Point p1(1.0, 2.0, 3.0);
    Point p2(4.0, 5.0, 6.0);

    std::cout << "Point 1: (" << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")" << std::endl;
    std::cout << "Point 2: (" << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << ")" << std::endl;

    return 0;
}
