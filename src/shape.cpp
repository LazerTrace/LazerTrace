/**
 * Provides an implementation for all objects present in the scene.
 */

#include <utility>

/**
 * Represents any given object in the scene.
 */
class Shape {
    protected:
        float index_of_refraction;
        BoundingShape boundary;
    public:
        /**
         * @return Returns the index of refraction.
         */
        float getIndexOfRefraction()
            { return index_of_refraction; }
        /**
         * Calculates the intersection between a ray and the object.
         *
         * @param ray The ray in question.
         * @return A pair containing the point of intersection and the angle 
         * between the ray and the object.
         */
        virtual pair<Point, float> getIntersection(Ray ray) = 0;
}

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
        Sphere(Point center, float radius, float index_of_refraction) {
            this.center = center;
            this.radius = radius;
            this.index_of_refraction = index_of_refraction);
        }
        
        pair<Point, float> getIntersection(Ray ray) {
            return make_pair(center, 0.0) // Placeholder
        }
}

/**
 * Represents an infinite plane.
 */
class Plane: public Shape {
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
        Plane(Point center, Vector normal, float index_of_refraction) {
            this.center = center;
            this.normal = normal;
            this.index_of_refraction = index_of_refraction;
        }
        
        pair<Point, float> getIntersection(Ray ray) {
            return make_pair(center, 0.0) // Placeholder
        }
}