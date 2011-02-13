#include <set>
#include <string>
#include <fstream>
#include <iostream>

#include "scene.hpp"

using std::set;
using std:fstream;

    
/*
 * In the case of an empty constructor, Scene will generate a predefined
 * scene for rendering.
 */
Scene::Scene() {
    shapes.add(new Shere(new Point(0,0,0), 7.0, 0.0));
    shapes.add(new Shere(new Point(10,10,10), 3.0, 0.7));
    shapes.add(new Plane(new Point(10,0,0), new Vector(1,0,0) , 0.5));
    // Yet to add default lights.
}

Scene::Scene(string fileName) {
    ifstream input_scene (fileName);
    // Read the file and add specified shapes.
    // We need to figure out what our syntax/grammar is first though.
}

Scene::~Scene() {
    for(set<Shape>::iterator it = shapes.cbegin(); it != shapes.cend(); i++) {
        delete *it;
    }
    for(set<Sphere>::iterator it = lights.cbegin(); it != shapes.cend(); i++) {
        delete *it;
    }
}
