#pragma once
#include <vector>
#include "../TrackBallCamera/TrackballCamera.hpp"
// #include "Controls.hpp"
// #include "Maths/Math.hpp"
#include "../objet3D//Objet3D.hpp"
#include "../src-common/glimac/common.hpp"
#include "p6/p6.h"


class Joueur {
private:
    p6::Context*     _ctx;
    TrackballCamera* camera;
    Objet3D         objet3D;
    glm::vec3        position;
    float            hoverAmplitude;
    float            hoverFrequency;
    float            hoverTime;

public:
    // Constructor
    Joueur(p6::Context* ctx, TrackballCamera* camera, Objet3D objet3D);

    // Methods to handle Joueur actions and interactions
    void handleControls();
    void handleMovements();
    void animateJoueur();
    void initializeGUI();

    // Getter methods
    inline Objet3D& getObjet3D() { return objet3D; }
    inline glm::vec3& getPosition() { return position; }
    // inline float getLastOrientation() const {
    //     return glm::degrees(atan2(_controls.getLastDirection().z, _controls.getLastDirection().x)) + 90.0f;
    // }
    // inline float getTransparency() const { return _transparency; }

    // Setter method
    // inline void setPosition(const glm::vec3& position) { position = position; }
};