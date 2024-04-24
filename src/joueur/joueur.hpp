#pragma once
#include <vector>
#include "../TrackBallCamera/TrackballCamera.hpp"
// #include "../controle/Controls.hpp"
#include "../GUI/gui.hpp"
// #include "Maths/Math.hpp"
#include "../objet3D/Objet3D.hpp"
#include "../src-common/glimac/common.hpp"
#include "p6/p6.h"

class Joueur {
private:
    p6::Context*     _ctx;
    TrackballCamera* camera;
    // Controls         controls;
    glm::vec3        position{0.f, 0.f, 0.f};

    Objet3D objet3D{"ovocyte", "3D.vs.glsl", "tex3D.fs.glsl"};

    float _hoverAmplitude = 0.1f; // [GUI]
    float _hoverFrequency = 2.0f; // [GUI]
    float _hoverTime      = 0.0f;
    float _transparency = 1.f; // [GUI]

public:
    Joueur(p6::Context* ctx, TrackballCamera* camera, float* mapSize);

    // void handleControls();
    // void handleMovements();
    // void animatePlayer();
    // void initializeGUI();

    Objet3D&  getObjet3D() { return objet3D; };
    glm::vec3& getPosition() { return position; };
    // float      getLastOrientation() { return glm::degrees(atan2(controls.getLastDirection().z, controls.getLastDirection().x)) + 90.0f; };
    float      getTransparency() const { return _transparency; };
    void       setPosition(const glm::vec3& pos) { position = pos; };
};