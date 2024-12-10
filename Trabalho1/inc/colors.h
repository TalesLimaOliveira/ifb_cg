#ifndef COLORS_H
#define COLORS_H

struct Color {
    float r, g, b;
};

// DEFALUT COLORS
const Color WHITE = {1.0f, 1.0f, 1.0f};
const Color BLACK = {0.0f, 0.0f, 0.0f};
const Color RED = {1.0f, 0.0f, 0.0f};
const Color GREEN = {0.0f, 1.0f, 0.0f};
const Color BLUE = {0.0f, 0.0f, 1.0f};

// PALLETE
const Color BACKGROUND = {0.25f, 0.25f, 0.25f};
const Color HOUSE = {0.0f, 1.0f, 1.0f};
const Color INSIDE = {0.65f, 0.7f, 0.65f};

#endif // COLORS_H