#include <tut/tut.hpp>

namespace tut {
    struct basic {};
    typedef test_group<basic> factory;
    typedef factory::object object;
}

namespace {
    tut::factory tf("basic test");
}

namespace tut {
    template<>
    template<>
    void object::test<1>() {
        ensure_equals("2+2=?", 2+2, 4);
    }
}
