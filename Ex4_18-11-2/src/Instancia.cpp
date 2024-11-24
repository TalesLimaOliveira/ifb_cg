#include "Instancia.h"

/**
 * @brief Constructor for the Instancia class.
 */
Instancia::Instancia(void) : translationX(0), translationY(0), scaleX(1), scaleY(1), angle(0) {}

/**
 * @brief Destructor for the Instancia class.
 */
Instancia::~Instancia(void) {}

/**
 * @brief Get the translation in the X direction.
 * @return The translation in the X direction.
 */
float Instancia::getTranslationX(void) { return translationX; }

/**
 * @brief Get the translation in the Y direction.
 * @return The translation in the Y direction.
 */
float Instancia::getTranslationY(void) { return translationY; }

/**
 * @brief Get the scale in the X direction.
 * @return The scale in the X direction.
 */
float Instancia::getScaleX(void) { return scaleX; }

/**
 * @brief Get the scale in the Y direction.
 * @return The scale in the Y direction.
 */
float Instancia::getScaleY(void) { return scaleY; }

/**
 * @brief Get the angle of rotation.
 * @return The angle of rotation.
 */
float Instancia::getAngle(void) { return angle; }

/**
 * @brief Increment the angle of rotation.
 */
void Instancia::incrementAngle() { angle += 1.0f; }

/**
 * @brief Decrement the angle of rotation.
 */
void Instancia::decrementAngle() { angle -= 1.0f; }

/**
 * @brief Increment the translation in the X direction.
 */
void Instancia::incrementTranslationX() { translationX += 0.1f; }

/**
 * @brief Increment the translation in the Y direction.
 */
void Instancia::incrementTranslationY() { translationY += 0.1f; }

/**
 * @brief Increment the scale in the X direction.
 */
void Instancia::incrementScaleX() { scaleX += 0.1f; }

/**
 * @brief Increment the scale in the Y direction.
 */
void Instancia::incrementScaleY() { scaleY += 0.1f; }

/**
 * @brief Decrement the translation in the X direction.
 */
void Instancia::decrementTranslationX() { translationX -= 0.1f; }

/**
 * @brief Decrement the translation in the Y direction.
 */
void Instancia::decrementTranslationY() { translationY -= 0.1f; }

/**
 * @brief Decrement the scale in the X direction.
 */
void Instancia::decrementScaleX() { scaleX -= 0.1f; }

/**
 * @brief Decrement the scale in the Y direction.
 */
void Instancia::decrementScaleY() { scaleY -= 0.1f; }