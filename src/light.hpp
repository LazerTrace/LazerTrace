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
   /**
     * Accessor method for the color of the light
     *
     * @return The color of the light as a color object (3-tuple of floats)
     */
    Color getColor() const;
    Point getPoint() const;
    /**
     * Constructor for objects of class LightSource.  
     * Also not to be used directly.  Simply used for inheritance of other contrsuctors
     *
     * @param c the color of the light source
     */
    LightSource(Color c);
    virtual ~LightSource();
};

/**
 * Represents a point light source (point and color)
 */
class PointLight : public LightSource {
protected:
    Point point;
public:
    /**
     * Accessor method for the location of the light
     *
     * @return The point of origin of the light source
     */
    Point getPoint() const;
    /**
     * Constructor for objects of class PointLight.  
     *
     * @param c the color of the light source
     * @param p the point of the origin of the light source
     */
    PointLight(Color c, Point p);
    ~PointLight();
};

/**
 * Represents a spot light source (vector and color)
 */
class DirectionalLight : public LightSource {
protected:
    Vector direction;
public:
   /**
     * Accessor method for the direction of the light
     *
     * @return The direction of the light as a vector
     */
    Vector getDirection() const;
    /**
     * Constructor for objects of class DirectionalLight.  
     *
     * @param c the color of the light source
     * @param v the dirction that the light is coming from as a vector
     */
    DirectionalLight(Color c, Vector v);
    virtual ~DirectionalLight();
};

/**
 * Represents a spot light source (point, conical spread angle theta, and color)
 */
class SpotLight : public DirectionalLight {
protected:
    float theta;
    Point point;
public:
     /**
     * Accessor method for theta
     *
     * @return The conical spread angle of the spotLight
     */
    float getTheta() const;
    /**
     * Accessor method for the location of the light
     *
     * @return The point of origin of the light source
     */
    Point getPoint() const;
    /**
     * Constructor for objects of class SpotLight.  
     *
     * @param c the color of the light source
     * @param p the point of the origin of the light source
     * @param v the direction the light is pointing in as a vector
     * @param t the angle theta of the conical spread of the light
     */
    SpotLight(Color c, Point p, Vector v, float t);
    ~SpotLight();
};

#endif
