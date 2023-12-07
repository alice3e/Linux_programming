#include <iostream>

#include "ship.h"

int main() {
    Ship myShip(1000, 45, 30, 60);

    std::cout << "Initial angles: X=" << myShip.getAngleX() << ", Y=" << myShip.getAngleY() << ", Z=" << myShip.getAngleZ() << std::endl;

    myShip.rotate(15, 'x');
    myShip.rotate(10, 'y');

    std::cout << "Final angles after rotation: X=" << myShip.getAngleX() << ", Y=" << myShip.getAngleY() << ", Z=" << myShip.getAngleZ() << std::endl;

    return 0;
}

