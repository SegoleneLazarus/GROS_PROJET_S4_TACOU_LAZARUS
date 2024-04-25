#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>

class Transform
{
private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale; 

    glm::mat4 transform;

    void updateTransform();

public:
    explicit Transform(glm::vec3 position = glm::vec3{0.f}, glm::vec3 rotation = glm::vec3{0.f}, glm::vec3 scale = glm::vec3{1.f});
    Transform(glm::vec3 position, glm::vec3 rotation, float uniformScale = 1.f);

        glm::mat4 getTransform() const { return transform; };

        void setPosition(const glm::vec3 &newPosition)
    {
        position = newPosition;
        updateTransform();
    }

        void setRotation(const glm::vec3 &newRotation)
    {
        rotation = newRotation;
        updateTransform();
    }

        void setScale(const glm::vec3 &newScale)
    {
        scale = newScale;
        updateTransform();
    }
};

glm::vec3 velocityToRotationVector(const glm::vec3 &velocity);
