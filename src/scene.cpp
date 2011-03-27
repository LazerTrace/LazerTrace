#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

#include "scene.hpp"
#include "light.hpp"

using std::vector;

/*
 * In the case of an empty constructor, Scene will generate a predefined
 * scene for rendering.
 */
Scene::Scene() {
    Color c(0x10,0x10,0x10);
    Vector v(0,0,0);
    Point p(0,0,0);

    shapes.push_back(new Sphere(Point(0,0,0), 7.0, Color(0xff, 0x00, 0x00), 0.0, 0.5, 0.5, 0.5));
    shapes.push_back(new Sphere(Point(10,10,10), 3.0, Color(0, 0xff, 0), 0.7, 0.5, 0.5, 0.5));
    shapes.push_back(new Plane(Point(10,0,0), Vector(1,0,0), Color(0x00, 0x00, 0xff), 0.5, 0.5, 0.5, 0.5));

    lights.push_back(new PointLight(c,p));
    //lights.push_back(new DirectionalLight(c,v));
    //lights.push_back(new SpotLight(c, p, v, 0));
}

Scene::Scene(std::string fileName) {
    std::ifstream input_scene (fileName.c_str());
    // Read the file and add specified shapes.
    // We need to figure out what our syntax/grammar is first though.
}

Color Scene::shade(Shape *obj, Ray hit){
    for(vector<LightSource*>::iterator it = lights.begin(); it != lights.end(); it++) {
        Ray shadow = Ray::makeRay(hit.getOrigin(), (*it)->getPoint());
        Color result = Color(c);
        bool collision = false;

        // Detect collisions, for now do nothing if there is a collision
        for(vector<Shape*>::iterator sh = shapes.begin(); sh != shapes.end(); sh++) {
            if((*sh)->getIntersection(shadow) != NULL) {
                collision = true;
                break;
            }
        }

        // Calculate local illumination
        if(!collision) {
            // Normalize the direction vectors before calculations
            shadow.normalize();
            hit.normalize();

            float cos_theta = (shadow.getDir()).dotProduct(hit.getDir());
            Color diffuse = cos_theta*obj.getDiffuseCoefficient()*((*it)->getColor());
            result = Color(result.red + diffuse.red, result.green + diffuse.green, result.blue + diffuse.blue);
        }

        return result; // Should add operator overloader for color addition
    }
}

Scene::~Scene() {
    for(vector<Shape*>::iterator it = shapes.begin(); it != shapes.end(); it++) {
        delete *it;
    }
    for(vector<LightSource*>::iterator it = lights.begin(); it != lights.end(); it++) {
        delete *it;
    }
}

Ray Scene::get_camera_ray(float x, float y) const {
    return camera.get_ray(x, y);
}
