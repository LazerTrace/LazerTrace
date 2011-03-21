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
    Camera camera;

public:
    Scene();
    Scene(std::string fileName);
    ~Scene();

    /**
     * Asks the camera for a ray
     * @return The camera's ray
     */
    Ray get_camera_ray(float x, float y) const;

};

#endif
