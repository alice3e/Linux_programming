#pragma once
class Ship {
private:
    double mass;
    double angleX;
    double angleY;
    double angleZ;

public:
    Ship(double m, double ax, double ay, double az) : mass(m), angleX(ax), angleY(ay), angleZ(az) {}

    void rotate(double angle, char axis);
    double getAngleX();
    double getAngleY();
    double getAngleZ();
};

