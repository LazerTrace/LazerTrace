#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <memory>
#include <limits>

#include "scene.hpp"
#include "light.hpp"

using std::vector;
using std::auto_ptr;

/*
 * In the case of an empty constructor, Scene will generate a predefined
 * scene for rendering.
 */
Scene::Scene() : shapes(vector<Shape*>()),
                 lights(vector<LightSource*>()),
                 ambient(Color(0.25, 0.25, 0.25)),
                 camera(Camera()) {
    shapes.push_back(new Plane(Point(0, -3, 0), Vector(0, 1, 0),
                Color(0, 1, 1), 1, 0.5, 0.5, 0.5));
    //shapes.push_back(new Plane(Point(0, 0, 10), Vector(0, 0, 1),
                //Color(0, 1, 0), 1, 0.5, 0.5, 0.5));
    shapes.push_back(new Sphere(Point(1, -1, 5), 1,
                Color(1, 0, 0), 1, 0.5, 0.5, 0.5));
    shapes.push_back(new Sphere(Point(-1, -1, 5), 1,
                Color(0, 0, 1), 1, 0.5, 0.5, 0.5));

    lights.push_back(new PointLight(Color(1, 1, 1), Point(0, 5, 5)));
}

Scene::Scene(std::string fileName): shapes(vector<Shape*>()),
                                    lights(vector<LightSource*>()),
                                    ambient(Color(0.25, 0.25, 0.25)),
                                    camera(Camera()) {
    std::ifstream input_scene (fileName.c_str());
    // Read the file and add specified shapes.
    // We need to figure out what our syntax/grammar is first though.
}

Color Scene::raytrace(const Ray& camera_ray) const {
    const Shape *nearest_shape = NULL;
    float nearest_distance2 = std::numeric_limits<float>::max();
    Ray nearest_hit;
    for (vector<Shape*>::const_iterator it = shapes.begin(); it != shapes.end(); it++) {
        const Shape *shape = *it;
        auto_ptr<Ray> intersection(shape->getIntersection(camera_ray));
        if (intersection.get() == NULL) // Didn't hit this shape
            continue;
        float int_distance2 = Ray::makeRay(camera_ray.getOrigin(),
                intersection->getOrigin()).getDir().magnitude2();
        if (int_distance2 < nearest_distance2) {
            // Found a closer hit
            nearest_shape = shape;
            nearest_distance2 = int_distance2;
            nearest_hit = *intersection;
        }
    }
    if (nearest_shape == NULL) {
        // Didn't hit anything
        return Color(1, 0, 1); // Magenta
    } else {
        return shade(nearest_shape, nearest_hit);
    }
}

Color Scene::shade(const Shape *obj, Ray hit) const{
    for(vector<LightSource*>::const_iterator it = lights.begin(); it != lights.end(); it++) {
        LightSource *light = *it;
        Ray shadow = Ray::makeRay(hit.getOrigin(), light->getPoint());
        Color result = Color(ambient);
        bool collision = false;

        // Detect collisions, for now do nothing if there is a collision
        for(vector<Shape*>::const_iterator sh = shapes.begin(); sh != shapes.end(); sh++) {
            Shape *shape = *sh;
            auto_ptr<Ray> hit(shape->getIntersection(shadow));
            if (hit.get() != NULL) {
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

            if(cos_theta < 0)
                cos_theta = -cos_theta;
            else
                cos_theta = 0;

            Color diffuse = cos_theta * obj->getDiffuseCoefficient()
                * light->getColor();
            result = result + diffuse;
            result = result * obj->getColor();
        }

        return result;
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
    return camera.get_ray(x, -y);
}

void Scene::move_camera(float x, float y, float z, float i, float j, float k) {
    camera.set_position(x,y,z);
    camera.set_direction(i,j,k);
}
