#include "data_structures.hpp"
/*
 *Main light source class
 *Not to actually be implemented
 *Instead used derived classes below
 */    
class LightSource{
    protected:
        Color c;
    public:
        unsigned char getRed(){
            return c.red;
        }

        unsigned char getGreen(){
            return c.green;
        }

        unsigned char getBlue(){
            return c.blue;
        }

        unsigned char getAlpha(){
            return c.alpha;
        }

        Color getColor(){
            return c;
        }

};

class pointLight : public lightSource{
    protected:
        Point p;
        float intensity;
    public:
        float getIntensity(){
            return intensity;
        }
        Point getPoint(){
            return p;
        }
};

class directionalLight : public lightSource{
    protected:
        Vector v;
    public:
        float getI(){
            return v.i;
        }
        float getJ(){
            return v.j;
        }
        float getK(){
            return v.k;
        }
        DVector getVector{
            return v;
        }
};

class spotLight : public directionalLight{
    protected:
        float theta;
        Point p;
    public:
        float getTheta(){
            return theta;
        }
        Point getPoint(){
            Point p;
        }
};
