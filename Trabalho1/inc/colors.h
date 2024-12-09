#ifndef COLORS_H
#define COLORS_H

struct Color {
    float r, g, b;
};

const Color WHITE = {1.0f, 1.0f, 1.0f};
const Color RED = {1.0f, 0.0f, 0.0f};
const Color GREEN = {0.0f, 1.0f, 0.0f};
const Color BLUE = {0.0f, 0.0f, 1.0f};
const Color BG = {0.4f, 0.4f, 0.4f};

#endif // COLORS_H