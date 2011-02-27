#include "light.hpp"

unsigned char LightSource::getRed() const {
    return color.red;
}

unsigned char LightSource::getGreen() const {
    return color.green;
}


unsigned char LightSource::getBlue() const {
    return color.blue;
}

unsigned char LightSource::getAlpha() const {
    return color.alpha;
}

Color LightSource::getColor() const {
    return color;
}

LightSource::LightSource(Color c, float i):color(c),intensity(i){
}

virtual LightSource::~LightSource(){
    delete color;
}
	
float PointLight::getIntensity() const {
    return intensity;
}

Point PointLight::getPoint() const {
    return point;
}

PointLight::PointLight(Color c, float i, Point p):LightSource(c,i),point(p){
}

PointLight::~PointLight(){
    delete point
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

DirectionalLight::DirectionalLight(Color c, float i, Vector v)
    : LightSource(c,i),
    vector(v)
{
}

virtual DirectionalLight::~DirectionalLight(){
    delete vector;
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
    delete point;
}
