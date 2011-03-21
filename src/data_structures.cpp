#include <cmath>

#include "data_structures.hpp"
Color::Color(float r, float g, float b):red(r),green(g),blue(b){
}
Color Color::operator* (const int scalar) {
    return Color(red * scalar, green * scalar, blue * scalar);
}

Color operator*(int scalar, Color c){
    return Color(c.red * scalar, c.green * scalar, c.blue * scalar);
}

Color Color::operator* (const Color& c) {
    Color(red * c.red, green * c.green, blue * c.blue);
}

Color::~Color(){
}

Vector::Vector(float i_, float j_, float k_): i(i_), j(j_), k(k_) {
}

Vector& Vector::operator+=(const Vector& rhs) {
    i += rhs.i;
    j += rhs.j;
    k += rhs.k;
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    i -= rhs.i;
    j -= rhs.j;
    k -= rhs.k;
    return *this;
}

Vector Vector::operator+(const Vector& other) {
    return Vector(*this) += other;
}

Vector Vector::operator-(const Vector& other) {
    return Vector(*this) -= other;
}

Vector Vector::operator*(float scalar) const {
    return Vector(i*scalar, j*scalar, k*scalar);
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
