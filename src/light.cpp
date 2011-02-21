#include "light.hpp"

unsigned char LightSource::getRed() const {
    return c.red;
}

unsigned char LightSource::getGreen() const {
    return c.green;
}

unsigned char LightSource::getBlue() const {
    return c.blue;
}

unsigned char LightSource::getAlpha() const {
    return c.alpha;
}

Color LightSource::getColor() const {
    return c;
}


float PointLight::getIntensity() const {
    return intensity;
}

Point PointLight::getPoint() const {
    return p;
}


float DirectionalLight::getI() const {
    return v.i;
}

float DirectionalLight::getJ() const {
    return v.j;
}

float DirectionalLight::getK() const {
    return v.k;
}

Vector DirectionalLight::getVector() const {
    return v;
}

float SpotLight::getTheta() const {
    return theta;
}

Point SpotLight::getPoint() const {
    return p;
}
