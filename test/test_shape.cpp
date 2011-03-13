#include <tut/tut.hpp>

#include "shape.hpp"

namespace tut {
    struct Sphere_fixture {
        Sphere the_sphere;
        Sphere_fixture() : the_sphere(Sphere(Point(0,0,0), 1, Color(0xff, 0x00, 0x00, 0x00), 1))
        {
        }
    };
    typedef test_group<Sphere_fixture> factory;
    typedef factory::object object;
}

namespace {
    tut::factory tf("sphere test");
}

namespace tut {
    template<>
    template<>
    void object::test<1>() {
        ensure_equals("Sphere returns its index of refraction",
                the_sphere.getIndexOfRefraction(), 1);
    }
}
