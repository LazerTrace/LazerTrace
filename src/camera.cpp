#include "camera.hpp"


Camera::Camera(int width, int height):
    position(Point(0,0,0)),
    direction(Vector(0,0,1)),
    right(Vector((float)width/(float)height,0,0)),
    up(Vector(0,1,0)) {}

Camera::Camera(Point position, Vector direction, Vector right, Vector up):
    position(position), direction(direction), right(right), up(up) {}

Camera::Camera(Point position, int width, int height):
    position(position),
    direction(Vector(0,0,1)),
    right(Vector((float)width/(float)height,0,0)),
    up(Vector(0,1,0)) {}

Ray Camera::get_ray(float x, float y) const {
    Vector value = direction;
    value += right * x;
    value += up * y;
    value.normalize();
    return Ray(position, value);
}
