#include <utility>

class Shape {
    protected:
        float index_of_refraction;
        BoundingShape boundary;
    public:
        float getIndexOfRefraction()
            { return index_of_refraction; }
        virtual pair<Point, float> getIntersection(Ray ray) = 0;
}

class Sphere: public Shape {
    private:
        float radius;
        Point center;
    public:
        Sphere(Point center, float radius, float index_of_refraction) {
            this.center = center;
            this.radius = radius;
            this.index_of_refraction = index_of_refraction);
        }
        
        pair<Point, float> getIntersection(Ray ray) {
            return make_pair(center, 0.0) // Placeholder
        }
}