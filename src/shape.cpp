/**
 * Provides an implementation for all objects present in the scene.
 */

#include <utility>
#include <math>

#include "shape.hpp"

/**
 * @return Returns the index of refraction.
 */
float Shape::getIndexOfRefraction()
{ return index_of_refraction; }


/**
 * Creates a sphere primitive with the given parameters.
 * 
 * @param center The origin of the sphere.
 * @param radius The radius of the sphere.
 * @param index_of_refraction Index of refraction, specific to the
 * material of the sphere.
 */
Shere::Sphere(Point center, float radius, float index_of_refraction) {
    this.center = center;
    this.radius = radius;
    this.index_of_refraction = index_of_refraction);
}
    
Sphere::pair<Point, float> getIntersection(Ray ray) {
    return make_pair(center, 0.0); // Placeholder
}


/**
 * Represents an infinite plane.
 */

/**
 * Creates a plane primitive with the given parameters.
 * 
 * @param center The origin of the plane (any point on the plane.
 * @param normal The vector normal to the plane.
 * @param index_of_refraction Index of refraction, specific to the
 * material of the plane.
 */
Plane::Plane(Point center, Vector normal, float index_of_refraction) {
    this.center = center;
    this.normal = normal.normalize();
    this.index_of_refraction = index_of_refraction;

    
}

Plane::Ray getIntersection(Ray ray) {
    float v = Vector(this->center.x - ray.origin.x,
                     this->center.y - ray.origin.y,
                     this->center.z - ray.origin.z
                     );
    float d = this->normal.dotProduct(v) / this->normal.dotProduct(ray.dir);
    
    if (abs(d) < 0.0000001) {
        Point p = Point(ray.dir.i * d + ray.origin.x,
                        ray.dir.j * d + ray.origin.y,
                        ray.dir.k * d + ray.origin.z
                        );
        return new Ray(p, this->normal);
    } else { // we have no collision
        return NULL;
    }
 }
