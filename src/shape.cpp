#include <utility>
#include <cmath>

#include "shape.hpp"
#include "data_structures.hpp"

Shape::Shape(Color color, float index_of_refraction, float ambient_coef,
             float diffuse_coef, float specular_coef, float reflection_coef)
    : index_of_refraction(index_of_refraction), color(color), ambient_coef(ambient_coef),
      diffuse_coef(diffuse_coef), specular_coef(specular_coef),
      reflection_coef(reflection_coef) {
}

float Shape::getIndexOfRefraction() const {
    return index_of_refraction;
}

float Shape::getAmbientCoefficient() const {
    return ambient_coef;
}

float Shape::getDiffuseCoefficient() const {
    return diffuse_coef;
}

float Shape::getSpecularCoefficient() const {
    return specular_coef;
}

float Shape::getReflectionCoefficient() const {
    return reflection_coef;
}

Color Shape::getColor() const {
    return color;
}


Sphere::Sphere(Point center, float radius, Color color, float index_of_refraction,
               float ambient_coef, float diffuse_coef, float specular_coef, float reflection_coef)
    : Shape(color, index_of_refraction, ambient_coef, diffuse_coef, specular_coef, reflection_coef),
      center(center), radius(radius)
{
}

Ray* Sphere::getIntersection(const Ray& ray) const {
   /*
    *   see http://www.siggraph.org/education/materials/HyperGraph/raytrace/rtinter1.htm
    *   for detailed description of this algorithm
    *
    */
    Vector v = ray.getDir();
    v.normalize();
    Point o = ray.getOrigin();
    int a=1;
    float b = 2 *
    (
        v.i * (o.x - center.x) +
        v.j * (o.y - center.y) +
        v.k * (o.z - center.z)
    );
    float c = (o.x - center.x) * (o.x - center.x) +
        (o.y - center.y) * (o.y - center.y) +
        (o.z - center.z) * (o.z - center.z) -
        radius * radius;

    float discriminant = b*b-4*a*c;
    if(discriminant<0)
        return NULL;
    float t = (-b - sqrt(discriminant)) / (2*a);
    if(t<=0)
        t = (-b + sqrt(discriminant)) / (2*a);
    /*
        the if statement below should really be if(t<=0).
        in the case where t=0, the ray is being cast directly from an object.
        the obvious case here is reflective surfaces
        these case should always return null, but unfortunately, rounding errors
        sometimes cause a number that should be 0 to be slightly > 0.
        this method should probably be rewritten to avoid this case.
        for now, i just moved the threshold to .01
    */
    if(t<=.01)
        return NULL;

    Point p
    (
        o.x + v.i * t,
        o.y + v.j * t,
        o.z + v.k * t
    );
    Vector d(p.x-center.x, p.y-center.y, p.z-center.z);
    return new Ray(p,d);
}

Plane::Plane(Point center, Vector normal, Color color, float index_of_refraction,
             float ambient_coef, float diffuse_coef, float specular_coef, float reflection_coef)
    : Shape(color, index_of_refraction, ambient_coef, diffuse_coef, specular_coef, reflection_coef),
      center(center), normal(normal) {
}

Ray* Plane::getIntersection(const Ray& ray) const {
    if (normal.dotProduct(ray.dir) == 0) { // ray is parallel to the plane
        if (normal.dotProduct(Vector(center.x-ray.origin.x, center.y-ray.origin.y, center.z-ray.origin.z))==0) // ray is directly on the plane
            return new Ray(ray.origin, normal);
        else // ray never intersects with the plane
            return NULL;
    } else { // must intersect with the at one specific point
        // solve for parametric equation of a line
        float t = (normal.i*(center.x-ray.origin.x)+
                    normal.j*(center.y-ray.origin.y)+
                    normal.k*(center.z-ray.origin.z))/
                    (normal.i*ray.dir.i+normal.j*ray.dir.j+normal.k*ray.dir.k);
        if (t <= 0)
            return NULL;
        else {
            Point p = Point(ray.origin.x+ray.dir.i*t, ray.origin.y+ray.dir.j*t, ray.origin.z+ray.dir.k*t);
            return new Ray(p, normal);
        }
    }
 }

