#pragma once

#include <glm/glm.hpp>

class TrackballCamera
{
private:
    float m_Distance;
    float m_AngleX;
    float m_AngleY;
    glm::vec3 *m_Target;

public:
    // Constructeur
    TrackballCamera(glm::vec3 *target);

    void moveFront(float delta);
    void rotateLeft(float degrees);
    void rotateUp(float degrees);

    glm::mat4 getViewMatrix() const;
    float getDistance() const { return m_Distance; };

    void setTarget(glm::vec3 *target) { m_Target = target; };
};