#include <cmath>

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

Camera Camera::lookAt(Point position, Vector sky, Point look_at, float angle, int width, int height) {
    float right_length = width / (float) height;
    float direction_length = 0.5 * right_length / tan(angle / 2);

    Vector direction(Ray::makeRay(position, look_at).getDir()
        .normalized() * direction_length);
    Vector right(sky.crossProduct(direction).normalized() * right_length);
    Vector up(direction.crossProduct(right).normalized());

    return Camera(position, direction, right, up);
}

Ray Camera::get_ray(float x, float y) const {
    Vector value = direction;
    value += right * x;
    value += up * y;
    value.normalize();
    return Ray(position, value);
}

void Camera::set_position(float x, float y, float z) {
    this->position = Point(x,y,z);
}

void Camera::set_direction(float i, float j, float k) {
    this->direction = Vector(i,j,k);
}


void Camera::offset_direction(float i, float j, float k){
    direction.i += i;
    direction.j += j;
    direction.k += k;
}
    

void Camera::offset_position(float x, float y, float z) {
    position.x += x;
    position.y += y;
    position.z += z;
}
