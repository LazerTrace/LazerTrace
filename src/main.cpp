#include <png.hpp>

#include "scene.hpp"
#include "light.hpp"

int main(void) {
    Scene default_scene;

    png::image<png::rgb_pixel> image(128, 128);
    for (size_t y = 0; y < image.get_height(); ++y) {
        for (size_t x = 0; x < image.get_width(); ++x) {
            float scaled_x = 2 * x / 128. - 1;
            float scaled_y = 2 * y / 128. - 1;
            Ray camera_ray = default_scene.get_camera_ray(scaled_x, scaled_y);
            // TODO: Trace the ray
            Vector dir = camera_ray.getDir();
            image[y][x] = png::rgb_pixel(
                    dir.i * 128 + 128, dir.j * 128 + 128, dir.k * 128 + 128);
        }
    }
    image.write("output.png");

    return 0;
}
