#include <iostream>


class Triangle {
public:
    Triangle(double side1, double side2, double side3) : side1_(side1), side2_(side2), side3_(side3) {}

    double getSide1() const {
        return side1_;
    }

    double getSide2() const {
        return side2_;
    }

    double getSide3() const {
        return side3_;
    }

private:
    double side1_;
    double side2_;
    double side3_;
};

int main() {
    Triangle t1(3.0, 4.0, 5.0);
    Triangle t2(5.0, 12.0, 13.0);

    std::cout << "Triangle 1: Side 1 = " << t1.getSide1() << ", Side 2 = " << t1.getSide2() << ", Side 3 = " << t1.getSide3() << std::endl;
    std::cout << "Triangle 2: Side 1 = " << t2.getSide1() << ", Side 2 = " << t2.getSide2() << ", Side 3 = " << t2.getSide3() << std::endl;

    return 0;
}
