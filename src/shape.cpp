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

Ray* Sphere::getIntersection(const Ray& ray) const {
    Vector c(center.x, center.y, center.z);
    float det = pow(ray.getDir().dotProduct(c), 2)
        - ray.getDir().dotProduct(ray.getDir())
        * (c.dotProduct(c) - pow(radius, 2));
    
    if (det < 0) {
        return NULL;
    }
    float d =  ray.getDir()ray.getDir().dotProduct(c);
    if (det == 0) {
        Point p(ray.dir.i * d, ray.dir.j * d, ray.dir.k * d);
        Vector v(c.i - p.i, c.j - p.j, c.k - p.k);
        return new Ray(p,v);
    }
    // two collisions
    else {
        float sdet = sqrt(det);
        if (abs(d - sdet) > abs(d + sdet)) {
            float d = d + sdet;
        } else {
            float d = d - sdet;
        }
        
        Point p(ray.dir.i * d, ray.dir.j * d, ray.dir.k * d);
        Vector v(c.i - p.i, c.j - p.j, c.k - p.k);
        return new Ray(p,v);

            
    }
}

Plane::Plane(Point center_, Vector normal_, float index_of_refraction_)
    : Shape(index_of_refraction_),
      center(center_), normal(normal_)
{
}

Ray* Plane::getIntersection(const Ray& ray) const {
    Vector v(center.x - ray.origin.x,
             center.y - ray.origin.y,
             center.z - ray.origin.z);
    float d = normal.dotProduct(v) / normal.dotProduct(ray.dir);

    if (fabsf(d) < 0.0000001) {
        Point p(ray.dir.i * d + ray.origin.x,
                ray.dir.j * d + ray.origin.y,
                ray.dir.k * d + ray.origin.z);
        return new Ray(p, normal);
    } else { // we have no collision
        return NULL;
    }
 }

