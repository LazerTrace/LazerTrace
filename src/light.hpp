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
public:
    unsigned char getRed() const;
    unsigned char getGreen() const;
    unsigned char getBlue() const;
    unsigned char getAlpha() const;
    Color getColor() const;
    LightSource(Color c);
    Point getPoint() const;
    virtual ~LightSource();
};

class PointLight : public LightSource {
protected:
    Point point;
public:
    Point getPoint() const;
    PointLight(Color c, Point p);
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
    DirectionalLight(Color c, Vector v);
    virtual ~DirectionalLight();
};

class SpotLight : public DirectionalLight {
protected:
    float theta;
    Point point;
public:
    float getTheta() const;
    /**
     * Returns the origin of the SpotLight.
     *
     * @return The Point representing the origin of the light.
     */
    Point getPoint() const;
    SpotLight(Color c, Point p, Vector v, float t);
    ~SpotLight();
};

#endif
