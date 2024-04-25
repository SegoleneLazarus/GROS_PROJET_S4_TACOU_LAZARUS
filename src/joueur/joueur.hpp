#pragma once
#include <vector>
#include "../TrackBallCamera/TrackballCamera.hpp"
#include "../controles/controles.hpp"
#include "../GUI/gui.hpp"
// #include "Maths/Math.hpp"
#include "../objet3D/Objet3D.hpp"
#include "../src-common/glimac/common.hpp"
#include "p6/p6.h"

class Joueur
{
private:
    p6::Context *_ctx;
    TrackballCamera *camera;
    Controles controls;
    glm::vec3 _position{0.f, 0.f, 0.f};

    Objet3D objet3D{"ovocyte", "3D.vs.glsl", "tex3D.fs.glsl"};

    float _hoverAmplitude = 0.1f;
    float _hoverFrequency = 2.0f;
    float _hoverTime = 0.0f;

public:
    Joueur(p6::Context *ctx, TrackballCamera *camera, float *mapSize);

    void handleControls();
    void handleMovements();

    Objet3D &getObjet3D() { return objet3D; };
    glm::vec3 &getPosition() { return _position; };
    float getLastOrientation() { return glm::degrees(atan2(controls.getLastDirection().z, controls.getLastDirection().x)) + 90.0f; };
    void setPosition(const glm::vec3 &position) { _position = position; };
};