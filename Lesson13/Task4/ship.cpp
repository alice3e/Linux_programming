
#include "ship.h"

//
// Created by alicee on 08.12.2023.
//
void Ship::rotate(double angle, char axis) {
    if (axis == 'x') {
        angleX += angle;
    } else if (axis == 'y') {
        angleY += angle;
    } else if (axis == 'z') {
        angleZ += angle;
    }
}

double Ship::getAngleX() {
    return angleX;
}

double Ship::getAngleY() {
    return angleY;
}

double Ship::getAngleZ() {
    return angleZ;
}


