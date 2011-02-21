#include <utility>
#include <cmath>

#include "shape.hpp"
#include "data_structures.hpp"

Shape::Shape(float index_of_refraction_)
    : index_of_refraction(index_of_refraction_)
{
}

float Shape::getIndexOfRefraction() const {
    return index_of_refraction;
}


Sphere::Sphere(Point center_, float radius_, float index_of_refraction_)
    : Shape(index_of_refraction_),
    center(center_), radius(radius_)
{
}

Ray Sphere::getIntersection(const Ray& ray) const {
    // XXX Placeholder
}

Plane::Plane(Point center_, Vector normal_, float index_of_refraction_)
    : Shape(index_of_refraction_),
    center(center_), normal(normal_)
{
}

Ray Plane::getIntersection(const Ray& ray) const {
    Vector v(center.x - ray.origin.x,
             center.y - ray.origin.y,
             center.z - ray.origin.z);
    float d = normal.dotProduct(v) / normal.dotProduct(ray.dir);

    if (fabsf(d) < 0.0000001) {
        Point p(ray.dir.i * d + ray.origin.x,
                ray.dir.j * d + ray.origin.y,
                ray.dir.k * d + ray.origin.z);
        return Ray(p, normal);
    } else { // we have no collision
        // TODO
    }
 }

