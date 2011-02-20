#include <cmath>

#include "data_structures.hpp"

/**
 * Represents a color in RGBA format
 */
class Color{
    public:
        unsigned char alpha, red, green, blue;
};

Vector::Vector(float i_, float j_, float k_): i(i_), j(j_), k(k_) {
}

void Vector::normalize() {
    float length = sqrt(i*i + j*j + k*k);
    i = i/length;
    j = j/length;
    k = k/length;
}

float Vector::dotProduct(Vector v) const {
    return (i * v.i) + (j * v.j) + (k * v.k);
}

Point::Point(float x_, float y_, float z_): x(x_), y(y_), z(z_) {
}

Ray::Ray(Point origin_, Vector dir_): origin(origin_), dir(dir_) {
}

Point Ray::getOrigin() const {
    return origin;
}

Vector Ray::getDir() const {
    return dir;
}

void Ray::normalize() {
    float length = sqrt(dir.i*dir.i + dir.j*dir.j + dir.k*dir.k);
    dir.i = dir.i/length;
    dir.j = dir.j/length;
    dir.k = dir.k/length;
}
