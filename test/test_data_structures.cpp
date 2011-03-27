#include <tut/tut.hpp>
#include "data_structures.hpp"

namespace tut {
    struct basic {
        Vector a, b, c;
        Vector d, e;
        basic(): a(1,2,3), b(4,6,8), c(5,8,11),
                 d(2,2,2), e(0.57735026,0.57735026,0.57735026) {}
    };
    typedef test_group<basic> factory;
    typedef factory::object object;
}

namespace {
    tut::factory tf("data structures test");
}

namespace tut {
    template<>
    template<>
    void object::test<1>() {
        ensure_equals("vector add",
                (a+b).i, c.i);
        ensure_equals("vector add",
                (a+b).j, c.j);
        ensure_equals("vector add",
                (a+b).k, c.k);
    }

    template<>
    template<>
    void object::test<2>() {
        d.normalize();
        ensure_equals("vector normalize", d.i, e.i);
        ensure_equals("vector normalize", d.j, e.j);
        ensure_equals("vector normalize", d.k, e.k);
    }

    template<>
    template<>
    void object::test<3>() {
        ensure("vector magnitude", d.normalized().approx_equals(e));
    }

    template<>
    template<>
    void object::test<4>() {
        Color c(1,2,3);
        c = 2.0 * c;
        ensure("color multiplication", c.red == 2);
        ensure("color multiplication", c.green == 4);
        ensure("color multiplication", c.blue == 6);
    }
}
