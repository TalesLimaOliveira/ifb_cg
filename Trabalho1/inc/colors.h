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
const Color BACKGROUND = {0.0f, 0.6f, 0.0f};
const Color GRASS = {0.0f, 0.6f, 0.0f};
const Color WOOD = {0.55f, 0.27f, 0.07f};

#endif // COLORS_H