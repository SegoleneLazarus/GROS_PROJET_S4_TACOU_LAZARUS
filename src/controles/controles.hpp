#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <vector>
#include "../TrackBallCamera/TrackballCamera.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtx/quaternion.hpp"
#include "glm/matrix.hpp"
#include "p6/p6.h"

class Controles
{
private:
    p6::Context *_ctx;
    TrackballCamera *camera;
    glm::vec3 lastDirection = glm::vec3(0);

    float *_mapSize;
    float _margin = .5f;

    // float _scrollSensitivity = .2f;  // [GUI]
    // float _mouseSensitivity  = 90.f; // [GUI]
    // float _minScrollDistance = .5f; // [GUI]
    // float _maxScrollDistance = 5.f; // [GUI]

    float _movementSpeed = .1f; // [GUI]

public:
    Controles(p6::Context *ctx, TrackballCamera *camera, float *mapSize);

    // void      handleCameraZoom();
    // void      handleCameraRotation();
    void handlePlayerMovements(glm::vec3 &playerPosition);
    glm::vec3 getLastDirection() { return lastDirection; };
};