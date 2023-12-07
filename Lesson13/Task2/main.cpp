#include <iostream>

class Rectangle {
public:
    Rectangle(double length, double width) : length_(length), width_(width) {}

    double getLength() const {
        return length_;
    }

    double getWidth() const {
        return width_;
    }

private:
    double length_;
    double width_;
};

int main() {
    Rectangle r1(5.0, 3.0);
    Rectangle r2(4.0, 6.0);

    std::cout << "Rectangle 1: Length = " << r1.getLength() << ", Width = " << r1.getWidth() << std::endl;
    std::cout << "Rectangle 2: Length = " << r2.getLength() << ", Width = " << r2.getWidth() << std::endl;

    return 0;
}
