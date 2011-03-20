#include <png.hpp>

#include "scene.hpp"
#include "light.hpp"

int main(void) {
    Scene default_scene;

    png::image<png::rgb_pixel> image(128, 128);
    for (size_t y = 0; y < image.get_height(); ++y) {
        for (size_t x = 0; x < image.get_width(); ++x) {
            // TODO
            image[y][x] = png::rgb_pixel(x, y, x + y);
        }
    }
    image.write("output.png");

    return 0;
}
