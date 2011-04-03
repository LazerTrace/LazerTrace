#ifndef _SCENE_HPP
#define _SCENE_HPP

#include <vector>
#include <string>

#include "shape.hpp"
#include "light.hpp"
#include "camera.hpp"

class Scene {

protected:
    // Storage for shapes in scene
    std::vector<Shape*> shapes;
    std::vector<LightSource*> lights;
    Color ambient;
    Camera camera;

public:
    /**
     * Default constructor for objects of class Scene().
     * Creates a default scene layout for testing purposes,
     * with a minimal number of objects and lights.
     * Auto-generates aspect ratio from width and height.
     */
    Scene(int width, int height);

    /**
     * Constructor for objects of class Scene().
     * Loads a scene from a file using JSON and OpenCTM file formats.
     * Auto-generates aspect ratio from width and height.
     */
    Scene(std::string fileName, int width, int height);

    /**
     * The entry point for the raytracer, and also recursively called
     * by shade.
     * @return The raytraced color
     */
    Color raytrace(const Ray& camera_ray, int level) const;

    /**
     * Given an object and the ray representing the intersection point,
     * returns the expected color given the local illumination calculation.
     *
     * @param obj The object which a ray intersected.
     * @param hit The ray representing the normal vector and point of intersection.
     * @return The color at the given point.
     */
    Color shade(const Shape *obj, Ray hit, const Ray &camera_ray, int level) const;

    ~Scene();

    /**
     * Asks the camera for a ray
     * @return The camera's ray
     */
    Ray get_camera_ray(float x, float y) const;

};

#endif
