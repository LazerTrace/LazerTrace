#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <memory>
#include <limits>

#include "scene.hpp"
#include "light.hpp"

#define MAX_LEVEL 5

using std::vector;
using std::auto_ptr;

/*
 * In the case of an empty constructor, Scene will generate a predefined
 * scene for rendering.
 */
Scene::Scene() : shapes(vector<Shape*>()),
                 lights(vector<LightSource*>()),
                 ambient(Color(0.25, 0.25, 0.25)),
                 camera(Camera(Point(0,2,-5)))
{
    // floor
    shapes.push_back(new Plane(Point(0, -3, 0), Vector(0, 1, 0), Color(1, 1, 1), 1, 0.5, 0.5, 0.5, 0));

    // back wall
    shapes.push_back(new Plane(Point(0, 0, 7), Vector(0, 0, -1), Color(1, 1, 1), 1, 0.5, 0.5, 0.5, 0));

    // left side wall
    shapes.push_back(new Plane(Point(-3, 0, 0), Vector(1, 0, 0), Color(1, 1, 1), 1, 0.5, 0.5, 0.5, 0));

    // ceiling
    shapes.push_back(new Plane(Point(0, 10, 0), Vector(0, -1, 0), Color(1, 1, 1), 1, 0.5, 0.5, 0.5, 0));

    // wall behind camera
    shapes.push_back(new Plane(Point(0, 0, -10), Vector(0, 0, 1), Color(1, 1, 1), 1, 0.5, 0.5, 0.5, 0));

    // right wall
    shapes.push_back(new Plane(Point(15, 0, 0), Vector(-1, 0, 0), Color(1, 1, 1), 1, 0.5, 0.5, 0.5, 0));

    // red sphere
    shapes.push_back(new Sphere(Point(3, -1, 5), 2,
                Color(1, 0, 0), 1, .3, 0, 1, 1));

    // blue sphere
    shapes.push_back(new Sphere(Point(-1, 2, 5), 1,
                Color(0, 0, 1), 1, 0.3, 0.5, 0.5, 0));

    //green sphere
        shapes.push_back(new Sphere(Point(-4, 0, 4), 2,
                Color(0, 1, 0), 1, 0.3, 0.5, 0.5, 0));

    // light source 1 (blueish)
    lights.push_back(new PointLight(Color(.5, .5, 1), Point(0, 0, 2)));

    // light source 2 (redish)
    lights.push_back(new PointLight(Color(1, .5, .5), Point(0, 5, 0)));

}

Scene::Scene(std::string sceneName): shapes(vector<Shape*>()),
                                    lights(vector<LightSource*>()),
                                    ambient(Color(0.25, 0.25, 0.25)),
                                    camera(Camera()) 
{
    std::ifstream input_scene (sceneName.c_str());
    // Read the file and add specified shapes.
    // We need to figure out what our syntax/grammar is first though.
}

Color Scene::raytrace(const Ray& camera_ray, int level) const {
    if(level>MAX_LEVEL) {
       /**
        * I'm not really sure if this is the correct return for this case
        * but in theory, this shouldn't trigger anyway.
        * We should always check the current level before attempting
        * to enter a new level of raytracing.
        */
        std::cout<<"level:"<<level<<"\n";
        return Color(1,1,1);
    }

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
        return shade(nearest_shape, nearest_hit, camera_ray, level);
    }
}

Color Scene::shade(const Shape *obj, Ray hit, const Ray& camera_ray, int level) const {
    Color result = Color(ambient) * obj->getAmbientCoefficient();
    for(vector<LightSource*>::const_iterator it = lights.begin(); it != lights.end(); it++) {
        LightSource *light = *it;
        Ray shadow = Ray::makeRay(hit.getOrigin(), light->getPoint());
        bool collision = false;
        // Detect collisions, for now do nothing if there is a collision
        for(vector<Shape*>::const_iterator sh = shapes.begin(); sh != shapes.end(); sh++) {
            Shape *shape = *sh;
            if (shape != obj) {
                auto_ptr<Ray> hit(shape->getIntersection(shadow));
                if (hit.get() != NULL && hit->getOrigin() != shadow.getOrigin()) {
                    Vector toHit(hit->getOrigin().x-shadow.getOrigin().x, 
                        hit->getOrigin().y-shadow.getOrigin().y,
                        hit->getOrigin().z-shadow.getOrigin().z);
                    if(fabs(toHit.i) <= fabs(shadow.getDir().i) && 
                        fabs(toHit.j) <= fabs(shadow.getDir().j) && 
                        fabs(toHit.k) <= fabs(shadow.getDir().k)){
                        collision = true;
                        break;
                    }
                }
            }
        }

        // Calculate local illumination
        if(!collision) {
            // Normalize the direction vectors before calculations
            shadow.normalize();
            hit.normalize();

            //diffuse lighting
            if(obj->getDiffuseCoefficient()>0) {
                float cos_theta = (shadow.getDir()).dotProduct(hit.getDir());
                if(cos_theta > 0){
                    Color diffuse = cos_theta * obj->getDiffuseCoefficient()
                        * light->getColor() * obj->getColor();
                    result = result + diffuse;
                }
            }

            //specular lighting
            if(obj->getSpecularCoefficient()>0) {
                Ray lightReflection(hit.getOrigin(), shadow.getDir()-
                    hit.getDir()*2*shadow.getDir().dotProduct(hit.getDir()));
                float cos_theta = 
                    camera_ray.getDir().dotProduct(lightReflection.getDir());
                if(cos_theta > 0) {
                    Color spec = powf( cos_theta, 20 ) * 
                        obj->getSpecularCoefficient() *
                        light->getColor();
                    result = result + spec;
                }
            }
        }        
    }

    if(obj->getReflectionCoefficient()>0 && level < MAX_LEVEL) {
        Ray reflection(hit.getOrigin(), camera_ray.getDir()-
                    hit.getDir()*2*camera_ray.getDir().dotProduct(hit.getDir()));
        Color refl = raytrace(reflection, level) *
            obj->getReflectionCoefficient() * obj->getColor();
        result = result + refl;
    }

    result = result.clamp();
    return result;
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
