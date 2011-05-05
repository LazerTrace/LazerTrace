#ifndef _DATA_STRUCTURES_HPP
#define _DATA_STRUCTURES_HPP

/**
 * Represents a color as a triple (R,G,B) of floats from 0 to 1
 * representing the full range of intensity. Values above 1 are
 * considered to be at full intensity for output purposes, and values
 * below 0 are considered to be at no intensity (implemented by
 * clamp()).
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
     * Multiplication of a color by a scalar.
     * Each component of the color is multiplied by the scalar
     *
     * @param scalar The scalar to multiply with the color.
     * @return A new color (R*scalar, G*scalar, B*scalar)
     */
    Color operator* (float);

    /**
     * Multiplication of a color by a color.  Each component of this
     * color is multiplied by the corresponding component of the
     * parameter.
     *
     * @param c The color to multiply with the original color.
     * @return A new color (R1*R2, G1*G2, B1*B2).
     */
    Color operator* (const Color&);

    /**
     * Addition of a color to a color.  Each component of this
     * color is added to the corresponding component of the
     * parameter.
     *
     * @param c The color to add with the original color.
     * @return A new color (R1+R2, G1+G2, B1+B2).
     */
    Color operator+ (const Color&);

    /**
     * Limit color values to the range [0, 1].
     * @return A copy of this color with channels constrained.
     */
    Color clamp() const;
};

/**
 * \relates Color
 * Multiplication of a scalar by a color, with arguments reversed.
 *
 * @return Delegates to Color::operator*(Color,float)
 */
Color operator*(float, Color);

/**
 * Value used to compare vectors for approximate equality.
 */
const float EPSILON = 1e-4;

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
     * Vector approximate comparison. If corresponding elements of the
     * vectors differ by less than EPSILON, the vectors are
     * approximately equal.
     * @param other The vector to compare to.
     * @return Componentwise comparison to within EPSILON
     */
    bool approx_equals(const Vector&) const;

    /**
     * Overloaded addition-assignment operator.
     * Performs component based addition-assignment.
     *
     * @param other The vector to add.
     * @return The updated vector
     */
    Vector& operator+=(const Vector&);

    /**
     * Overloaded subtraction-assignment operator.
     * Performs component based subtraction-assignment.
     *
     * @param other The vector to subtract.
     * @return The updated vector
     */
    Vector& operator-=(const Vector&);

    /**
     * Overloaded addition operator.
     * Performs component based addition.
     *
     * @param other The vector to add.
     * @return The result
     */
    Vector operator+(const Vector&);

    /**
     * Overloaded subtraction operator.
     * Performs component based subtraction.
     *
     * @param other The vector to subtract.
     * @return A pointer to the result.
     */
    Vector operator-(const Vector&);

    /**
     * Vector multiplication by scalar.
     * @return <i*c, j*c, k*c>
     */
    Vector operator*(float) const;

    /**
     * Vector division by scalar.
     * @return <i/c, j/c, k/c>
     */
    Vector operator/(float) const;

    /**
     * Vector magnitude
     * @return The magnitude, computed by \f$ i^2 + j^2 + k^2 \f$
     */
    float magnitude() const;

    /**
     * Magnitude squared
     * @return The square of the magnitude, computed by
     * \f$ i^2 + j^2 + k^2 \f$
     */
    float magnitude2() const;

    /**
     * Normalizes the vector to a unit vector.
     * Divides each component of the vector by the magnitude.
     * The resultant vector has unit magnitude.
     */
    void normalize();

    /**
     * Returns a normalized copy of the vector
     * Divides each component of the vector by the magnitude.
     * @return A vector with the same direction and unit magnitude.
     */
    Vector normalized() const;

    /**
     * Compute the dot product when dotted with the given Vector.
     *
     * @param v A vector.
     * @return the dot product of this vector with v, computed by
     * \f$ i_1i_2 + j_1j_2 = k_1k_2 \f$
     */
    float dotProduct(Vector v) const;

    /**
     * Vector cross product
     * @return The cross product, orthogonal to this vector and the
     * other.
     */
    Vector crossProduct(Vector) const;
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
     * Subtracting two points yields the vector between them.
     *
     * @param other The Point to subtract.
     * @return A vector pointing from other to this.
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

/** \relatesalso Camera
 * Utility function to convert degrees to radians.
 * Useful for Camera::lookAt().
 * @param d An angle in degrees
 * @return \f$ \pi d / 180 \f$
 */
float degrees(float d);

#endif
