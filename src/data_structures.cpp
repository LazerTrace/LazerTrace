/**
 * Includes any data structures required for ray-tracing.
 * Currently supports points, rays, and vectors
 */
 
#include <cmath>
 
/**
 * Represents a 3-dimensional vector.
 */
class Vector {
public:
    float i = 0.0;
    float j = 0.0;
    float k = 0.0;
    
    /**
     * Constructor for objects of class Vector.
     *
     * @param i The x-direction
     * @param j The y-direction
     * @param k The z-direction
     */
    Vector(float i, float j, float k) {
        this.i = i;
        this.j = j;
        this.k = k;
    }
    
    /**
     * Normalizes the vector to a unit vector.
     */
    void normalize() {
        float length = math.sqrt(i*i + j*j + k*k);
        i = i/length;
        j = j/length;
        k = k/length;
    }

    /**
     * Compute the dot product when dotted with the given Vector.
     *
     * @param v a normalized vector.
     * @return the dot product of this vector with v.
     */
    float dotProduct(Vector v) {
        return (i * v.i) + (j * v.j) + (k * v.k);
    }
    
}
 
 /**
  * Represents a 3-dimensional point in space.
  */
class Point {
    public:
        float x = 0.0;
        float y = 0.0;
        float z = 0.0;
        
        /**
         * Constructor for objects of class Point.
         *
         * @param x The x-coordinate
         * @param y The y-coordinate
         * @param z The z-coordinate
         */
        Point(float x, float y, float z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
}
 
 /**
  * Represents a ray, which includes a point and a vector.
  */
class Ray {
    private:
        Point origin;
        Vector dir;
    public:
        /**
         * Constructor for objects of class Ray.
         *
         * @param origin The origin of the ray.
         * @param dir The direction vector of the ray.
         */
        Ray(Point origin, Vector dir) {
            this.origin = origin;
            this.dir = dir;
        }
    
        /**
         * Accessor method for the origin.
         *
         * @return The point representing the origin of the ray.
         */
        Point getOrigin() {
            return origin;
        }
        
        /**
         * Accessor method for the direction vector.
         *
         * @return The vector representing the direction of the ray.
         */
        Vector getDir() {
            return dir;
        }
    
        /**
         * Normalizes the vector portion to a unit vector.
         */
        void normalize() {
            float length = math.sqrt(dir.i*dir.i + dir.j*dir.j + dir.k*dir.k);
            dir.i = dir.i/length;
            dir.j = dir.j/length;
            dir.k = dir.k/length;
        }
}
