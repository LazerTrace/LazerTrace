//possibly move the color class to tylers data structurs file
class Color{
    public:
        unsigned char alpha, red, green, blue;
};

class LightSource{
    protected:
        Color c;
    public:
        char getRed(){
            return c.red;
        }

        char getGreen(){
            return c.green;
        }

        char getBlue(){
            return c.blue;
        }

        char getAlpha(){
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
