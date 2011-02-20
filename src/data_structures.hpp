class Vector {
    public: 
        float i, j, k;
        
        Vector(float i, float j, float k);
        void normalize();
};

class Point {
    public:
        float x, y, z;
        
        Point(float x, float y, float z);
};

class Ray {
    public:
        Ray(Point origin, Vector dir);
        Point getOrigin();
        Vector getDir();
        void normalize();
};