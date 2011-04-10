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
    float red, green, blue;

    /**
     * Constructor for objects of class Color.
     *
     * @param r the color red
     * @param g the color green
     * @param b the color blue
     */
    Color(float r, float g, float b);
    ~Color();
    /**
     * Overloaded multiplcation-assignment operator.
     * color * scalar
     *
     * @param scalar The scalar to multiply with the color.
     * @return A pointer to the lhs of the equation.
     */
    Color operator* (float);

    /**
     * Overloaded multiplcation-assignment operator.
     *
     * @param c The color to multiply with the original color.
     * @return The componentwise product of the colors
     */
    Color operator* (const Color&);

    /**
     * Overloaded addition operator.
     *
     * @param c The color to add with the original color.
     * @return The sum of the colors
     */
    Color operator+ (const Color&);

    /**
     * Limit color values to the range [0, 1]
     * @return This color with channels constrained
     */
    Color clamp() const;
};

/**
 * Overloaded multiplcation-assignment operator.
 * scalar * color
 *
 * @param scalar The scalar to multiply.
 * @param c The color to multiply
 * @return A pointer to the lhs of the equation.
 */
Color operator*(float, Color);

const float EPSILON = 1e-6;

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
     * Vector approximate comparison
     * @return Componentwise comparison to within EPSILON
     */
    bool approx_equals(const Vector&) const;

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
     * @param other The vector to add.
     * @return A pointer to the result.
     */
    Vector operator+(const Vector& other);

    /**
     * Overloaded subtraction operator.
     * Performs component based subtraction.
     *
     * @param other The vector to subtract.
     * @return A pointer to the result.
     */
    Vector operator-(const Vector& other);

    /**
     * Vector multiplication by scalar.
     */
    Vector operator*(float) const;

    /**
     * Vector division by scalar.
     */
    Vector operator/(float) const;

    /**
     * Vector magnitude
     */
    float magnitude() const;

    /**
     * Magnitude squared
     */
    float magnitude2() const;

    /**
     * Normalizes the vector to a unit vector.
     */
    void normalize();

    /**
     * Returns a normalized copy of the vector
     */
    Vector normalized() const;

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

    /**
     * Overloaded comparison operator.
     * Does coordinate based comparison.
     *
     * @param p The point to compare with.
     * @return True if the points are equivalent, false otherwise.
     */
    bool operator==(const Point &p) const;

    /**
     * Overloaded subtraction operator.
     * Performs component based subtraction.
     *
     * @param other The Point to subtract.
     * @return A pointer to the result.
     */
    Vector operator-(const Point& other);

    /**
     * Overloaded comparison operator.
     * Does coordinate based comparison.
     *
     * @param p The point to compare with.
     * @return False if the points are equivalent, true otherwise.
     */
    bool operator!=(const Point &p) const;

    /*
    //this operator overload doesn't really work yet.
    //it was designed for an operation in plane intersection
    Vector operator-(const Point& p);
    */
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
     * Default ray constructor
     * Lives at <0,0,0> and points at <0,0,1>
     */
    Ray();

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

    /**
     * Creates a ray between two points.
     *
     * @param origin The starting point for the ray.
     * @param dest The destination point for the ray.
     * @return A ray object which starts at origin and passes through dest.
     */
    static Ray makeRay(Point origin, Point dest);
};

#endif
