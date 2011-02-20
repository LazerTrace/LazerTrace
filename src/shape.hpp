#include <utility>

#include "data_structures.hpp"
#include "bounding_shape.hpp"

/**
 * Provides an implementation for all objects present in the scene.
 */
class Shape {
protected:
    float index_of_refraction;
    BoundingShape boundary;
public:
    /**
     * @return Returns the index of refraction.
     */
    float getIndexOfRefraction() const;

    /**
     * Calculates the intersection between a ray and the object.
     *
     * @param ray The ray in question.
     * @return A pair containing the point of intersection and the angle 
     * between the ray and the object.
     */
    virtual std::pair<Point, float> getIntersection(Ray ray) const;
};

/**
 * Represents a sphere primitive.
 */
class Sphere: public Shape {
private:
    float radius;
    Point center;
public:

    /**
     * Creates a sphere primitive with the given parameters.
     *
     * @param center The origin of the sphere.
     * @param radius The radius of the sphere.
     * @param index_of_refraction Index of refraction, specific to the
     * material of the sphere.
     */
    Sphere(Point center, float radius, float index_of_refraction);

    std::pair<Point, float> getIntersection(Ray ray) const;
};

/**
 * Represents an infinite plane.
 */
class Plane : public Shape {

private:
    Point center;
    Vector normal;
public:
    /**
     * Creates a plane primitive with the given parameters.
     *
     * @param center The origin of the plane (any point on the plane.
     * @param normal The vector normal to the plane.
     * @param index_of_refraction Index of refraction, specific to the
     * material of the plane.
     */
    Plane(Point center, Vector normal, float index_of_refraction);
    
    Ray getIntersection(Ray ray) const;
};

