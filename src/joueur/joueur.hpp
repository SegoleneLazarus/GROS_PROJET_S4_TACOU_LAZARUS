#pragma once

#include <p6/p6.h>
#include <glm/glm.hpp>
#include <vector>
#include "../src-common/glimac/sphere_vertices.hpp"
#include "../TrackBallcamera/camera.hpp"
// #include "../src/render/cube.hpp"
#include "../model3D/model3D.hpp"
// #include "../src/render/program.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/trigonometric.hpp"
#include "p6/p6.h"

class Joueur {
public:
    Joueur(glm::vec3 pos);
    void move(const p6::Context& ctx, Joueur& joueur, Camera& camera);

    /* *** GETTERS *** */
    glm::vec3 getPosition();

private:
    glm::vec3 m_pos;
    float     m_Phi;
    float     m_Theta;
    float     m_speed = 0.1f;

    glm::vec3 m_FrontVector;
    glm::vec3 m_LeftVector;
    glm::vec3 m_UpVector;

    void computeDirectionVectors();
    void moveFront(float speed);
    void moveLeft(float speed);
};