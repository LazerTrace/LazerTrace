#ifndef _BOUNDINGSHAPE_HPP
#define _BOUNDINGSHAPE_HPP

/**
 * Provides an implementation for different bounding shapes.
 */

class BoundingShape {
    public:
        virtual bool intersects() = 0;
};

#endif
