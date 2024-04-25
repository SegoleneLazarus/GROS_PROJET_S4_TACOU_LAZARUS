#include "transfObjet.hpp"

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
    : position(position), rotation(rotation), scale(scale)
{
    updateTransform();
}

Transform::Transform(glm::vec3 position, glm::vec3 rotation, float uniformScale)
    : Transform(position, rotation, glm::vec3{uniformScale})
{
}

void Transform::updateTransform()
{
    glm::mat4 posMat = glm::translate(glm::mat4{1.f}, position);
    glm::mat4 rotMat = glm::eulerAngleXYZ(glm::radians(rotation.x), glm::radians(rotation.y), glm::radians(rotation.z));
    glm::mat4 scaleMat = glm::scale(glm::mat4{1.f}, scale);
    transform = posMat * rotMat * scaleMat;
}

glm::vec3 velocityToRotationVector(const glm::vec3 &velocity)
{
    glm::vec3 direction = glm::normalize(velocity);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::quat rotation = glm::rotation(up, direction);
    glm::vec3 eulerAngles = glm::degrees(glm::eulerAngles(rotation));
    return eulerAngles;
}
