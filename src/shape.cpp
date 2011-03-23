#include <utility>
#include <cmath>

#include "shape.hpp"
#include "data_structures.hpp"

Shape::Shape(Color color, float index_of_refraction, float ambient_coef,
             float diffuse_coef, float specular_coef)
    : index_of_refraction(index_of_refraction), color(color), ambient_coef(ambient_coef),
      diffuse_coef(diffuse_coef), specular_coef(specular_coef) {
}

float Shape::getIndexOfRefraction() const {
    return index_of_refraction;
}

float getAmbientCoefficient() const {
    return ambient_coef;
}
    
float getDiffuseCoefficient() const {
    return diffuse_coef;
}
    
float getSpecularCoefficient() const {
    return specular_coef;
}

Color Shape::getColor() const {
    return color;
}


Sphere::Sphere(Point center, float radius, Color color, float index_of_refraction,
               float ambient_coef, float diffuse_coef, float specular_coef)
    : Shape(color, index_of_refraction, ambient_coef, diffuse_coef, specular_coef),
      center(center), radius(radius)
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
    float d =  ray.dir.dotProduct(c);
    if (det == 0) {
        Point p(ray.dir.i * d, ray.dir.j * d, ray.dir.k * d);
        Vector v(c.i - p.x, c.j - p.y, c.k - p.z);
        return new Ray(p,v);
    }
    // two collisions
    else {
        float sdet = sqrt(det);
        if (fabsf(d - sdet) > fabsf(d + sdet)) {
            float d = d + sdet;
        } else {
            float d = d - sdet;
        }

        Point p(ray.dir.i * d, ray.dir.j * d, ray.dir.k * d);
        Vector v(c.i - p.x, c.j - p.y, c.k - p.z);
        return new Ray(p,v);
    }
}

Plane::Plane(Point center, Vector normal, Color color, float index_of_refraction,
             float ambient_coef, float diffuse_coef, float specular_coef)
    : Shape(color, index_of_refraction, ambient_coef, diffuse_coef, specular_coef),
      center(center), normal(normal) {
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

