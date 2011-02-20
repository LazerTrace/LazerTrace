#include <utility>
#include "shape.hpp"

float Shape::getIndexOfRefraction() const {
    return index_of_refraction;
}


Shere::Sphere(Point center, float radius, float index_of_refraction) {
    this.center = center;
    this.radius = radius;
    this.index_of_refraction = index_of_refraction;
}

Sphere::pair<Point, float> getIntersection(Ray ray) {
    return make_pair(center, 0.0); // Placeholder
}

Plane::Plane(Point center, Vector normal, float index_of_refraction) {
    this.center = center;
    this.normal = normal.normalize();
    this.index_of_refraction = index_of_refraction;
}

Plane::pair<Point, float> getIntersection(Ray ray) const {

    //return make_pair(center, 0.0); // Placeholder
}
