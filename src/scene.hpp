#ifndef _SCENE_HPP
#define _SCENE_HPP

#include <vector>
#include <string>

#include "shape.hpp"
#include "light.hpp"
#include "camera.hpp"

/**
 * This class serves two purposes: Maintaining the set of shapes and
 * light sources, and running the raytracing and shading algorithms.
 */
class Scene {

protected:

    /**
     * Storage for the shapes in the scene
     */
    std::vector<Shape*> shapes;

    /**
     * Storage for the light sources in the scene
     */
    std::vector<LightSource*> lights;

    /**
     * Multiplier for the ambient light in the scene.
     * Ambient shading is computed by multipling this value by an
     * object's ambient value.
     */
    Color ambient;

    /**
     * The Camera for the scene.
     */
    Camera camera;

public:
    /**
     * Default constructor:  Creates a default scene layout for
     * testing purposes, with a minimal number of objects and lights.
     * Auto-generates aspect ratio from width and height.
     */
    Scene(int width, int height);

    /**
     * The entry point for the raytracer, and also recursively called
     * by shade.
     * @param camera_ray The ray to be traced.
     * @param level Recursion levels remaining.
     * @return The raytraced color.
     */
    Color raytrace(const Ray& camera_ray, int level) const;

    /**
     * Given an object and the ray representing the intersection point,
     * returns the expected color given the local illumination calculation.
     *
     * @param obj The object which a ray intersected.
     * @param hit The ray representing the normal vector and point of intersection.
     * @param camera_ray The camera ray which produced the hit.
     * @param level Recursion levels remaining.
     * @return The color at the given point.
     */
    Color shade(const Shape *obj, Ray hit, const Ray &camera_ray, int level) const;

    ~Scene();

    /**
     * Asks the camera for a ray.
     *
     * \param x Increases from -1 to 1 across the image
     * \param y Increases from -1 to 1 down the image
     * @return The camera's ray
     */
    Ray get_camera_ray(float x, float y) const;

};

#endif
