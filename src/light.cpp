#include "light.hpp"
#include <cassert>

Color LightSource::getColor() const {
    return color;
}

LightSource::LightSource(Color c):color(c) {
}

Point LightSource::getPoint() const {
    assert(false); // Ensures this will never reach the return statement.
    // NOTE: This is a fix for the possibility of a DirectionalLight... need a better soln later.
    return Point(0, 0, 0);
}

LightSource::~LightSource(){
}

Point PointLight::getPoint() const {
    return point;
}

PointLight::PointLight(Color c, Point p):LightSource(c),point(p){
}

PointLight::~PointLight(){
}

Vector DirectionalLight::getDirection() const {
    return direction;
}

DirectionalLight::DirectionalLight(Color c, Vector d)
    : LightSource(c),
    direction(d)
{
}

DirectionalLight::~DirectionalLight(){
}

float SpotLight::getTheta() const {
    return theta;
}

Point SpotLight::getPoint() const {
    return point;
}

SpotLight::SpotLight(Color c, Point p, Vector v, float t)
    : DirectionalLight(c,v),
    theta(t),
    point(p)
{
}

SpotLight::~SpotLight(){
}
