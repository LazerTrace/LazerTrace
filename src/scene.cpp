#include <std::set>
#include <string>
#include <std::fstream>
#include <iostream>

class Scene {

protected:
    // Storage for shapes in scene
    set<Shape> shapes;
    set<Light> lights;

public:
    
    /*
     * In the case of an empty constructor, Scene will generate a predefined
     * scene for rendering.
     */
    Scene() {
        shapes.add(new Shere(new Point(0,0,0), 7.0, 0.0));
        shapes.add(new Shere(new Point(10,10,10), 3.0, 0.7));
        shapes.add(new Plane(new Point(10,0,0), new Vector(1,0,0) , 0.5));
        // Yet to add default lights.
    }

    Scene(string fileName) {
        ifstream input_scene (fileName);
        // Read the file and add specified shapes.
        // We need to figure out what our syntax/grammar is first though.
    }

    ~Scene() {
        for(set<Shape>::iterator it = shapes.cbegin(); it != shapes.cend(); i++) {
            delete *it;
        }
        for(set<Sphere>::iterator it = lights.cbegin(); it != shapes.cend(); i++) {
            delete *it;
        }
    }

}
