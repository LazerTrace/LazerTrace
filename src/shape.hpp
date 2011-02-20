#ifndef _SHAPE_HPP
#define _SHAPE_HPP

#include <utility>

#include "data_structures.hpp"
#include "bounding_shape.hpp"

/**
 * Provides an implementation for all objects present in the scene.
 */
class Shape {
protected:
    float index_of_refraction;
    BoundingShape *boundary;
    Shape(float index_of_refraction);
public:
    /**
     * @return Returns the index of refraction.
     */
    float getIndexOfRefraction() const;

    /**
     * Calculates the intersection between a ray and the object.
     *
     * @param ray The ray in question.
     * @return A unit normal ray at the point of intersection, or FIXME
     * null.
     */
    virtual Ray getIntersection(const Ray& ray) const = 0;
};

/**
 * Represents a sphere primitive.
 */
class Sphere : public Shape {
private:
    Point center;
    float radius;
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

    virtual Ray getIntersection(const Ray& ray) const;
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

    virtual Ray getIntersection(const Ray& ray) const;
};

#endif
