#include <png.hpp>

int main(void) {
    png::image<png::rgb_pixel> image("input.png");
    image.write("output.png");
}
