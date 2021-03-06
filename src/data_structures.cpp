#include <cmath>

#include "data_structures.hpp"

Color::Color(float r, float g, float b)
    : red(r),green(g),blue(b) {}

Color Color::operator* (const float scalar) {
    return Color(red * scalar, green * scalar, blue * scalar);
}

Color operator*(float scalar, Color c){
    return c * scalar;
}

Color Color::operator* (const Color& c) {
    return Color(red * c.red, green * c.green, blue * c.blue);
}

Color Color::operator+(const Color& c){
    return Color(red + c.red, green + c.green, blue + c.blue);
}

Color Color::clamp() const {
    Color result(*this);
    if(red>1)
        result.red=1;
    if(green>1)
        result.green=1;
    if(blue>1)
        result.blue=1;
    if(red<0)
        result.red=0;
    if(green<0)
        result.green=0;
    if(blue<0)
        result.blue=0;
    return result;
}

Color::~Color(){
}

Vector::Vector(float i, float j, float k): i(i), j(j), k(k) {
}

bool Vector::approx_equals(const Vector& other) const {
    return std::abs(other.i - i) < EPSILON &&
           std::abs(other.j - j) < EPSILON &&
           std::abs(other.k - k) < EPSILON;
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

Vector Vector::operator/(float scalar) const {
    return Vector(i/scalar, j/scalar, k/scalar);
}

float Vector::magnitude() const {
    return sqrt(i*i + j*j + k*k);
}

float Vector::magnitude2() const {
    return i*i + j*j + k*k;
}

void Vector::normalize() {
    float length = magnitude();

    i /= length;
    j /= length;
    k /= length;
}

Vector Vector::normalized() const {
    return *this / magnitude();
}

float Vector::dotProduct(Vector v) const {
    return (i * v.i) + (j * v.j) + (k * v.k);
}

Vector Vector::crossProduct(Vector v) const {
    return Vector(j*v.k - k*v.j,
                  k*v.i - i*v.k,
                  i*v.j - j*v.i);
}

Point::Point(float x, float y, float z): x(x), y(y), z(z) {
}

bool Point::operator==(const Point &p) const {
    if(x != p.x)    return false;
    if(y != p.y)    return false;
    if(z != p.z)    return false;
    return true;
}

bool Point::operator!=(const Point &p) const {
    return !(*this == p);
}

Vector Point::operator-(const Point& rhs) {
    return Vector(x-rhs.x, y-rhs.y, z-rhs.z);
}

Ray::Ray(Point origin, Vector dir): origin(origin), dir(dir) {
}

Ray::Ray() : origin(0, 0, 0), dir(0, 0, 1) {}

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

Ray Ray::makeRay(Point origin, Point dest) {
    Vector dir = Vector(dest.x - origin.x, dest.y - origin.y, dest.z - origin.z);
    return Ray(origin, dir);
}

float degrees(float degrees) {
    return degrees * M_PI / 180;
}
