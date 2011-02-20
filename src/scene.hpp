#include <set>
#include <string>

#include "shape.hpp"
#include "light.hpp"

class Scene {

protected:
    // Storage for shapes in scene
    std::set<Shape> shapes;
    std::set<Light> lights;

public:
    Scene();
    Scene(std::string fileName);
    ~Scene();

};
