#ifndef INSTANCE_H
#define INSTANCE_H

class Instance {
public:
    // Constructor
    Instance(void);
    // Destructor
    ~Instance(void);

    // Getters for translation, scale, and angle
    float getTranslationX(void);
    float getTranslationY(void);
    float getScaleX(void);
    float getScaleY(void);
    float getAngle(void);

    // Methods to increment and decrement angle
    void incrementAngle();
    void decrementAngle();

    // Methods to increment translation and scale
    void incrementTranslationX();
    void incrementTranslationY();
    void incrementScaleX();
    void incrementScaleY();

    // Methods to decrement translation and scale
    void decrementTranslationX();
    void decrementTranslationY();
    void decrementScaleX();
    void decrementScaleY();

private:
    // Translation variables
    float translationX, translationY;
    // Scale variables
    float scaleX, scaleY;
    // Angle variable
    float angle;
};

#endif // INSTANCE_H