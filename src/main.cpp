#include <png.hpp>

#include "scene.hpp"
#include "light.hpp"

int main(void) {
    Scene the_scene;

    png::image<png::rgb_pixel> image(128, 128);
    for (size_t y = 0; y < image.get_height(); ++y) {
        for (size_t x = 0; x < image.get_width(); ++x) {
            float scaled_x = 2 * x / 128. - 1;
            float scaled_y = 2 * y / 128. - 1;
            Ray camera_ray = the_scene.get_camera_ray(scaled_x, scaled_y);
            Color color = the_scene.raytrace(camera_ray);
            image[y][x] = png::rgb_pixel(
                    color.red * 255, color.green * 255, color.blue * 255);
        }
    }
    image.write("output.png");

    return 0;
}
