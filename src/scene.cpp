#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "scene.hpp"
#include "light.hpp"

using std::vector;

/*
 * In the case of an empty constructor, Scene will generate a predefined
 * scene for rendering.
 */
Scene::Scene() {
    shapes.push_back(new Sphere(Point(0,0,0), 7.0, Color(255, 0, 0), 0.0));
    shapes.push_back(new Sphere(Point(10,10,10), 3.0, Color(0, 255, 0), 0.7));
    shapes.push_back(new Plane(Point(10,0,0), Vector(1,0,0), Color(0, 0, 255), 0.5));
    // Yet to add default lights.
}

Scene::Scene(std::string fileName) {
    std::ifstream input_scene (fileName.c_str());
    // Read the file and add specified shapes.
    // We need to figure out what our syntax/grammar is first though.
}

Scene::~Scene() {
    for(vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        delete *it;
    }
    for(vector<LightSource*>::iterator it = lights.begin(); it != lights.end(); it++) {
        delete *it;
    }
}
