#ifndef _LIGHT_HPP
#define _LIGHT_HPP

#include "data_structures.hpp"

/**
 * Main light source class
 * Not to actually be implemented
 * Instead used derived classes below
 */

class LightSource {
protected:
    Color color;
    float intensity;
public:
    unsigned char getRed() const;
    unsigned char getGreen() const;
    unsigned char getBlue() const;
    unsigned char getAlpha() const;
    Color getColor() const;
    LightSource(Color c, float i);
    virtual ~LightSource();
};

class PointLight : public LightSource {
protected:
    Point point;
public:
    float getIntensity() const;
    Point getPoint() const;
    PointLight(Color c, float i, Point p);
    ~PointLight();
};

class DirectionalLight : public LightSource {
protected:
    Vector vector;
public:
    float getI() const;
    float getJ() const;
    float getK() const;
    Vector getVector() const;
    DirectionalLight(Color c, float i, Vector v);
    virtual ~DirectionalLight();
};

class SpotLight : public DirectionalLight {
protected:
    float theta;
    Point point;
public:
    float getTheta() const;
    Point getPoint() const;
    SpotLight(Color c, float i, Point p, Vector v, float t);
    ~SpotLight();
};

#endif
