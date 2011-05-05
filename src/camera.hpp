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
     *
     * Takes the width and height of the image and auto-generates the
     * aspect ratio and such.
     */
    Camera(int width, int height);

    /**
     * Constructs a camera from the given vectors.
     */
    Camera(Point position, Vector direction, Vector right, Vector up);

    /**
     * Constructs a camera from the given point.
     */
    Camera(Point position);

    /**
     * Constructs a camera from the given point. Auto-generates the
     * aspect ration from the width and height
     */
    Camera(Point position, int width, int height);

    /**
     * Computes a camera based on the given parameters.
     */
    static Camera lookAt(Point position, Vector sky, Point look_at, float angle, int width, int height);

    /**
     * Computes a camera ray.
     * @param x X coordinate in range [-1, 1]
     * @param y Y coordinate in range [-1, 1]
     * @return The camera ray
     */
    Ray get_ray(float x, float y) const;
};

#endif
