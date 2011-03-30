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
