#include <png.hpp>

#include "other.hpp"

void other(void) {
    png::image<png::rgb_pixel> image("input.png");
    image.write("output.png");
}
