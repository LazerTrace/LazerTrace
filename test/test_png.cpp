#include <png.hpp>
#include <tut/tut.hpp>

namespace tut {
    struct png_test {};
    typedef test_group<png_test> factory;
    typedef factory::object object;
}

namespace {
    tut::factory tf("pngpp test");
}

namespace tut {
    template<>
    template<>
    void object::test<1>() {
        png::image<png::rgb_pixel> image(128, 128);
        for (size_t y = 0; y < image.get_height(); ++y) {
            for (size_t x = 0; x < image.get_width(); ++x) {
                // TODO
                image[y][x] = png::rgb_pixel(x, y, x + y);
            }
        }
        ensure(true);
    }
}
