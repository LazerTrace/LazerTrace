#include <png.hpp>
#include <json/json.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include "scene.hpp"
#include "light.hpp"



const int WIDTH = 1440;
const int HEIGHT = 900;

const int NUM_WORKERS = 1;

Scene the_scene(WIDTH, HEIGHT);
png::image<png::rgb_pixel> image(WIDTH, HEIGHT);

struct bounding_box {
    unsigned int x1;
    unsigned int x2;
    unsigned int y1;
    unsigned int y2;
};

struct bounding_box box_allocator[NUM_WORKERS];


/**
 * draws pixels in the bounding box (inclusive) that is contained bbox
 */
void *draw_partial(void *bbox){


    struct bounding_box *box = (struct bounding_box *) bbox;

    for (size_t y = box->y1; y < box->y2; ++y) {
        for (size_t x = box->x1; x < box->x2; ++x) {
            //printf("doing shit %d %d\n", x,y);
            float scaled_x = 2 * x / (float) WIDTH - 1;
            float scaled_y = 2 * y / (float) HEIGHT - 1;
            Ray camera_ray = the_scene.get_camera_ray(scaled_x, scaled_y);
            Color color = the_scene.raytrace(camera_ray, 1);
            image[y][x] = png::rgb_pixel(
                                         color.red * 255, 
                                         color.green * 255, 
                                         color.blue * 255
                                         );
        }
    }

    return NULL;
}


int main(void) {

    pthread_t workers[NUM_WORKERS];
    pthread_attr_t attr;

    //Creating a set of attributes to send to the threads
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int wdivisor = NUM_WORKERS == 0 ? 0 : WIDTH / NUM_WORKERS;
    int hdivisor = NUM_WORKERS == 0 ? 0 : HEIGHT / NUM_WORKERS;

    for (int i = 0; i < NUM_WORKERS; i++) {
        box_allocator[i].x1 = 0;
        box_allocator[i].x2 = WIDTH;
        box_allocator[i].y1 = (HEIGHT / NUM_WORKERS) * i;
        box_allocator[i].y2 = (HEIGHT / NUM_WORKERS) * (i+1);
    }

    for(int i = 0; i < NUM_WORKERS; i++) {
        printf("Starting Thread...\n");
        pthread_create (&workers[i], &attr, draw_partial, (void*) &box_allocator[i]);
    }
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }

    image.write("output.png");

    return 0;
}
