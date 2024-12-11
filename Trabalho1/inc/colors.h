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

const Color LIGHT_BLUE = {0.68f, 0.85f, 1.0f};  // Azul claro
const Color BACKGROUND = {0.35f, 0.45f, 0.35f}; // Verde escuro
const Color BROWN = {0.4f, 0.2f, 0.1f};         // Marrom médio

// House Colors
const Color HOUSE_BASE_FRONT = {0.8f, 0.4f, 0.2f}; // Marrom claro
const Color HOUSE_ROOF_FRONT = {0.5f, 0.2f, 0.1f}; // Marrom escuro
const Color HOUSE_BASE_SIDE = {0.7f, 0.3f, 0.1f};  // Marrom médio
const Color HOUSE_ROOF_SIDE = {0.3f, 0.1f, 0.05f}; // Marrom escuro+

#endif // COLORS_H