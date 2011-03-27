#include "light.hpp"

Color LightSource::getColor() const {
    return color;
}

LightSource::LightSource(Color c, float i):color(c),intensity(i){
}

LightSource::~LightSource(){
}

Point PointLight::getPoint() const {
    return point;
}

PointLight::PointLight(Color c, float i, Point p):LightSource(c,i),point(p){
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

// DON"T YOU FUCKING CALL THIS. DON"T DO IT. I WILL KILL YOU.
Point PointLight::getPoint() const {
    return NULL;
}

Vector DirectionalLight::getVector() const {
    return vector;
}

DirectionalLight::DirectionalLight(Color c, float i, Vector v)
    : LightSource(c,i),
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

SpotLight::SpotLight(Color c, float i, Point p, Vector v, float t)
    : DirectionalLight(c,i,v),
    theta(t),
    point(p)
{
}

SpotLight::~SpotLight(){
}
