#include <png.hpp>
#include <json.h>

#include "scene.hpp"
#include "light.hpp"

int main(void) {
    Scene the_scene;

    const int WIDTH = 1600;
    const int HEIGHT = 1200;

    png::image<png::rgb_pixel> image(WIDTH, HEIGHT);
    for (size_t y = 0; y < image.get_height(); ++y) {
        for (size_t x = 0; x < image.get_width(); ++x) {
            float scaled_x = 2 * x / (float) WIDTH - 1;
            float scaled_y = 2 * y / (float) HEIGHT - 1;
            Ray camera_ray = the_scene.get_camera_ray(scaled_x, scaled_y);
            Color color = the_scene.raytrace(camera_ray, 1);
            image[y][x] = png::rgb_pixel(
                    color.red * 255, color.green * 255, color.blue * 255);
        }
    }
    image.write("output.png");

    return 0;
}
