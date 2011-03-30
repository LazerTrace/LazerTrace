#include <png.hpp>
#include <string.h>
#include <math.h>

#include "scene.hpp"
#include "light.hpp"

#define PI 3.14159265


int main(void) {
    Scene the_scene;

    const int WIDTH = 400;
    const int HEIGHT = 300;

    const int FRAMES = 10;

    for (int i = 0; i < FRAMES; i++) {

        png::image<png::rgb_pixel> image(WIDTH, HEIGHT);
        for (size_t y = 0; y < image.get_height(); ++y) {
            for (size_t x = 0; x < image.get_width(); ++x) {
                float scaled_x = 2 * x / (float) WIDTH - 1;
                float scaled_y = 2 * y / (float) HEIGHT - 1;
                Ray camera_ray = the_scene.get_camera_ray(scaled_x, scaled_y);
                Color color = the_scene.raytrace(camera_ray);
                image[y][x] = png::rgb_pixel(color.red * 255, 
                                             color.green * 255, 
                                             color.blue * 255);
            }
        }
        
        char buffer [50];
        sprintf(buffer, "output%d.png", i);
        image.write(buffer);
        the_scene.move_camera_offset(1, 0, 1, .1, 0, .1);
    }
    return 0;
}
