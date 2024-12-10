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

// House2 Colors
const Color HOUSE2_BASE_FRONT = {0.8f, 0.4f, 0.2f}; // Marrom claro
const Color HOUSE2_ROOF_FRONT = {0.5f, 0.2f, 0.1f}; // Marrom escuro
const Color HOUSE2_WINDOW_FRONT = {0.8f, 0.8f, 1.0f}; // Azul claro
const Color HOUSE2_BASE_SIDE = {0.7f, 0.3f, 0.1f}; // Marrom médio
const Color HOUSE2_WINDOW_SIDE = {0.8f, 0.8f, 1.0f}; // Azul claro
const Color HOUSE2_ROOF_SIDE = {0.5f, 0.2f, 0.1f}; // Marrom escuro

#endif // COLORS_H