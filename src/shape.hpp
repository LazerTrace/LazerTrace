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
    float index_of_refraction, ambient_coef, diffuse_coef, specular_coef;
    Color color; // Will need to be replaced with advanced method
    BoundingShape *boundary;
    Shape(Color color, float index_of_refraction, float ambient_coef, float diffuse_coef, float specular_coef);
public:
    /**
     * @return Returns the index of refraction.
     */
    float getIndexOfRefraction() const;

    /**
     * @return Returns the coefficient for ambient light effects.
     */
    float getAmbientCoefficient() const;
    
    /**
     * @return Returns the coefficient for diffuse light effects.
     */
    float getDiffuseCoefficient() const;
    
    /**
     * @return Returns the coefficient for specular light effects.
     */
    float getSpecularCoefficient() const;
    
    /**
     * @return Returns the color of the shape.
     */
    Color getColor() const;

    /**
     * Calculates the intersection between a ray and the object.
     *
     * @param ray The ray in question.
     * @return A unit normal ray at the point of intersection, or FIXME
     * null.
     */
    virtual Ray* getIntersection(const Ray& ray) const = 0;
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
     * @param ambient_coef The coefficient for ambient light effects.
     * @param diffuse_coef The coefficient for diffuse light effects.
     * @param specular_coef The coefficient for specular light effects.
     * 
     * @return a pointer to the Ray normal to the intersection,
     * or NULL if no intersection. Remember to delete the Ray when done!
     */
    Sphere(Point center, float radius, Color color, float index_of_refraction,
           float ambient_coef, float diffuse_coef, float specular_coef);

    virtual Ray* getIntersection(const Ray& ray) const;
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
     * @param ambient_coef The coefficient for ambient light effects.
     * @param diffuse_coef The coefficient for diffuse light effects.
     * @param specular_coef The coefficient for specular light effects.
     *
     * @return a pointer to the Ray normal to the intersection,
     * or NULL if no intersection. Remember to delete the Ray when done!
     */
    Plane(Point center, Vector normal, Color color, float index_of_refraction,
          float ambient_coef, float diffuse_coef, float specular_coef);

    virtual Ray* getIntersection(const Ray& ray) const;
};

#endif
