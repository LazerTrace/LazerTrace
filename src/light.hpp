#include "data_structures.hpp"

/**
 * Main light source class
 * Not to actually be implemented
 * Instead used derived classes below
 */

class LightSource {
protected:
    Color c;
public:
    unsigned char getRed() const;
    unsigned char getGreen() const;
    unsigned char getBlue() const;
    unsigned char getAlpha() const;
    Color getColor() const;
};

class PointLight : public LightSource {
protected:
    Point p;
    float intensity;
public:
    float getIntensity() const;
    Point getPoint() const;
};

class DirectionalLight : public LightSource {
protected:
    Vector v;
public:
    float getI() const;
    float getJ() const;
    float getK() const;
    Vector getVector() const;
};

class SpotLight : public DirectionalLight {
protected:
    float theta;
    Point p;
public:
    float getTheta() const;
    Point getPoint() const;
};
