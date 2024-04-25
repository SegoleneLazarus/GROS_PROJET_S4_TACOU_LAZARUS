#include "Lumiere.hpp"
#include "glm/gtc/matrix_transform.hpp"

Lumiere::Lumiere() = default;

Lumiere::Lumiere(const glm::vec3& position)
    : _environmentPosition(position)
{}

DirectionalLumiere::DirectionalLumiere(const glm::vec3& position)
    : Lumiere(position)
{}

PointLumiere::PointLumiere(const glm::vec3& position)
    : Lumiere(position)
{}

auto Lumiere::getPosition() const -> glm::vec3
{
    return this->_position;
}

void Lumiere::setPosition(const glm::vec3& position)
{
    this->_environmentPosition = position;
}

void PointLumiere::update(const glm::mat4& viewMatrix)
{
    glm::mat4 lumiereMatrix = glm::translate(viewMatrix, this->_environmentPosition);
    this->_position       = glm::vec3((lumiereMatrix)*glm::vec4(0, 0, 0, 1));
}

void DirectionalLumiere::update(const glm::mat4& viewMatrix)
{
    this->_position = glm::vec3((viewMatrix)*glm::vec4(this->_environmentPosition, 0.f));
}