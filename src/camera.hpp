#ifndef _CAMERA_HPP
#define _CAMERA_HPP

#include "data_structures.hpp"

class Camera {
private:
    Point position;
    Vector direction, right, up;

public:
    /**
     * Constructs a default camera.
     * - position is 0
     * - direction is z
     * - right is x
     * - up is y
     */
    Camera();

    /**
     * Constructs a camera from the given vectors.
     */
    Camera(Point position, Vector direction, Vector right, Vector up);

    /**
     * Computes a camera ray.
     * @param x X coordinate in range [-1, 1]
     * @param y Y coordinate in range [-1, 1]
     * @return The camera ray
     */
    Ray get_ray(float x, float y) const;


    /**
     * changes the position vector of the camera
     */
    void set_position(float x, float y, float z);
    
    /**
     * changes the direction in which the camera points.
     */
    void set_direction(float i, float j, float k);
};

#endif
