#include "light.hpp"

int main(void) {
    Color c(0x00,0x00,0x00);
    Vector v(0,0,0);
    Point p(0,0,0);
    LightSource* ls = new LightSource(c,0);
    PointLight* pl = new PointLight(c,0,p);
    DirectionalLight* dl = new DirectionalLight(c,0,v);
    SpotLight* sl = new SpotLight(c, 0, p, v, 0);
    
    
    delete ls;
    delete pl;
    delete dl;
    delete sl;
    return 0;
}
