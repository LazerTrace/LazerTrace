#include "camera.hpp"

Camera::Camera():
    position(Point(0,0,0)),
    direction(Vector(0,0,1)),
    right(Vector(4/3.,0,0)),
    up(Vector(0,1,0)) {}

Camera::Camera(Point position, Vector direction, Vector right, Vector up):
    position(position), direction(direction), right(right), up(up) {}

Ray Camera::get_ray(float x, float y) const {
    Vector value = direction;
    value += right * x;
    value += up * y;
    return Ray(position, value);
}
