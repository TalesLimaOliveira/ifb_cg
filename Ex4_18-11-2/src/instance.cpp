#include <instance.h>

// Declare extern variables
extern double left, right, top, bottom;

/**
 * @brief Constructor for the Instance class.
 */
Instance::Instance(void) : translationX(0), translationY(0), scaleX(1), scaleY(1), angle(0) {}

/**
 * @brief Destructor for the Instance class.
 */
Instance::~Instance(void) {}

/**
 * @brief Get the translation in the X direction.
 * @return The translation in the X direction.
 */
float Instance::getTranslationX(void) { return translationX; }

/**
 * @brief Get the translation in the Y direction.
 * @return The translation in the Y direction.
 */
float Instance::getTranslationY(void) { return translationY; }

/**
 * @brief Get the scale in the X direction.
 * @return The scale in the X direction.
 */
float Instance::getScaleX(void) { return scaleX; }

/**
 * @brief Get the scale in the Y direction.
 * @return The scale in the Y direction.
 */
float Instance::getScaleY(void) { return scaleY; }

/**
 * @brief Get the angle of rotation.
 * @return The angle of rotation.
 */
float Instance::getAngle(void) { return angle; }

/**
 * @brief Increment the angle of rotation.
 */
void Instance::incrementAngle() { 
    angle += 1.0f; 
    if (angle >= 360.0f) angle = 0.0f;
}

/**
 * @brief Decrement the angle of rotation.
 */
void Instance::decrementAngle() { 
    angle -= 1.0f; 
    if (angle < 0.0f) angle = 359.0f;
}

/**
 * @brief Increment the translation in the X direction.
 */
void Instance::incrementTranslationX() { 
    if (translationX < right) translationX += 0.1f; 
}

/**
 * @brief Increment the translation in the Y direction.
 */
void Instance::incrementTranslationY() { 
    if (translationY < top) translationY += 0.1f; 
}

/**
 * @brief Increment the scale in the X direction.
 */
void Instance::incrementScaleX() { scaleX += 0.1f; }

/**
 * @brief Increment the scale in the Y direction.
 */
void Instance::incrementScaleY() { scaleY += 0.1f; }

/**
 * @brief Decrement the translation in the X direction.
 */
void Instance::decrementTranslationX() { 
    if (translationX > left) translationX -= 0.1f; 
}

/**
 * @brief Decrement the translation in the Y direction.
 */
void Instance::decrementTranslationY() { 
    if (translationY > bottom) translationY -= 0.1f; 
}

/**
 * @brief Decrement the scale in the X direction.
 */
void Instance::decrementScaleX() { scaleX -= 0.1f; }

/**
 * @brief Decrement the scale in the Y direction.
 */
void Instance::decrementScaleY() { scaleY -= 0.1f; }