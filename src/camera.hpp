#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#include "data_structures.hpp"

/**
 * An implementation of a rectilinear camera. The camera is controlled
 * by three vectors (direction, right, and up) and one point (position).
 * A convenience function lookAt() is provided so the parameters don't
 * have to be computed by hand.
 */
class Camera {
private:
    Point position;
    Vector direction, right, up;

public:
    /**
     * Constructs a default camera. A left handed coordinate system is
     * used, where x is right, y is up, and z is forward, and the camera
     * is sitting at the origin looking forward with a focal length
     * equal to the image height.
     *
     * - position is 0
     * - direction is <0,0,1>
     * - right is <1,0,0>
     * - up is <0,1,0>
     *
     * \param width Image width, used to determine the aspect ratio
     * \param height Image width, used to determine the aspect ratio
     */
    Camera(int width, int height);

    /**
     * Constructs a camera from the given vectors.
     */
    Camera(Point position, Vector direction, Vector right, Vector up);

    /**
     * Constructs a camera whose position is the given point.
     *
     * The other parameters use the default values from Camera(int,int).
     */
    Camera(Point position);

    /**
     * Constructs a camera from the given point and image size.
     *
     * The other parameters use the default values from Camera(int,int).
     *
     * \param width Image width, used to determine the aspect ratio
     * \param height Image width, used to determine the aspect ratio
     */
    Camera(Point position, int width, int height);

    /**
     * Computes a camera based on the given parameters.
     *
     * The following formulas are used:
     *
     * - right_length = width/height
     * - direction_length = 0.5 * right_length / tan(angle/2)
     *
     * - direction = Vector pointing from position to look_at whose
     *   length is direction_length
     * - right = (sky × direction) with length of right_length
     * - up = (direction × right) with unit length
     *
     * \see Vector.normalized
     * \see × is Vector.crossProduct
     */
    static Camera lookAt(Point position, Vector sky, Point look_at, float angle, int width, int height);

    /**
     * Computes a camera ray from the given point in the image.
     *
     * The ray is determined as follows:
     *
     * - Ray's position = The Camera's position
     * - Ray's direction = direction + x*right + y*up
     *
     * @param x X coordinate in range [-1, 1]
     * @param y Y coordinate in range [-1, 1]
     * @return The camera ray
     */
    Ray get_ray(float x, float y) const;
};

#endif
