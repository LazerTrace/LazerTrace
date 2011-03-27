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

float DirectionalLight::getI() const {
    return vector.i;
}

float DirectionalLight::getJ() const {
    return vector.j;
}

float DirectionalLight::getK() const {
    return vector.k;
}

Vector DirectionalLight::getVector() const {
    return vector;
}

DirectionalLight::DirectionalLight(Color c, Vector v)
    : LightSource(c),
    vector(v)
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
