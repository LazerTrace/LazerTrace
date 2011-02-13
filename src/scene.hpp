#include <set>
#include <string>

class Scene {

protected:
    // Storage for shapes in scene
    std::set<Shape> shapes;
    std::set<Light> lights;

public:
    
    Scene();

    Scene(std::string fileName);
    
    ~Scene() ;
    
}
