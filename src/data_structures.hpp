#ifndef _DATA_STRUCTURES_HPP
#define _DATA_STRUCTURES_HPP

/**
 * Includes any data structures required for ray-tracing.
 * Currently supports points, rays, and vectors
 */

/**
 * Represents a color in RGBA format
 */
class Color{
    public:
        unsigned short red, green, blue;
        Color(unsigned short r, unsigned short g, unsigned short b);
        ~Color();
        Color& operator* (int scaler);
        Color& operator* (const Color& c);
};

/**
 * Represents a 3-dimensional vector.
 */
class Vector {
public:
    float i, j, k;

    /**
     * Constructor for objects of class Vector.
     *
     * @param i The x-direction
     * @param j The y-direction
     * @param k The z-direction
     */
    Vector(float i, float j, float k);
    
    /**
     * Overloaded addition-assignment operator.
     * Performs component based addition-assignment.
     *
     * @param rhs The vector to add.
     * @return A pointer to the lhs of the equation.
     */
     Vector& operator+=(const Vector& rhs);
     
    /**
     * Overloaded subtraction-assignment operator.
     * Performs component based subtraction-assignment.
     *
     * @param rhs The vector to subtract.
     * @return A pointer to the lhs of the equation.
     */
     Vector& operator-=(const Vector& rhs);
     
    /**
     * Overloaded addition operator.
     * Performs component based addition.
     *
     * @param rhs The vector to add.
     * @return A pointer to the result.
     */
     Vector operator+(const Vector& other);
     
    /**
     * Overloaded subtraction operator.
     * Performs component based subtraction.
     *
     * @param rhs The vector to subtract.
     * @return A pointer to the result.
     */
     Vector operator-(const Vector& other);

    /**
     * Normalizes the vector to a unit vector.
     */
    void normalize();

    /**
     * Compute the dot product when dotted with the given Vector.
     *
     * @param v a normalized vector.
     * @return the dot product of this vector with v.
     */
    float dotProduct(Vector v) const;
};

/**
 * Represents a 3-dimensional point in space.
 */
class Point {
public:
    float x, y, z;

    /**
     * Constructor for objects of class Point.
     *
     * @param x The x-coordinate
     * @param y The y-coordinate
     * @param z The z-coordinate
     */
    Point(float x, float y, float z);
};

/**
  * Represents a ray, which includes a point and a vector.
  */
class Ray {
public:
    Point origin;
    Vector dir;

    /**
     * Constructor for objects of class Ray.
     *
     * @param origin The origin of the ray.
     * @param dir The direction vector of the ray.
     */
    Ray(Point origin, Vector dir);

    /**
     * Accessor method for the origin.
     *
     * @return The point representing the origin of the ray.
     */
    Point getOrigin() const;

    /**
     * Accessor method for the direction vector.
     *
     * @return The vector representing the direction of the ray.
     */
    Vector getDir() const;

    /**
     * Normalizes the vector portion to a unit vector.
     */
    void normalize();
};

#endif
