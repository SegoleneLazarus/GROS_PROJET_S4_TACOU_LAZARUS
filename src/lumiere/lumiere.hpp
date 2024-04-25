#pragma once

#include "glm/glm.hpp"

class Lumiere {
protected:
    explicit Lumiere(const glm::vec3& position);
    glm::vec3 _position;
    glm::vec3 _environmentPosition;

public:
    virtual ~Lumiere() = default;
    Lumiere();
    Lumiere(const lumiere&)                            = default;
    Lumiere(lumiere&&)                                 = delete;
    auto         operator=(const lumiere&) -> lumiere& = default;
    auto         operator=(lumiere&&) -> lumiere&      = delete;
    auto         getPosition() const -> glm::vec3;
    void         setPosition(const glm::vec3& position);
    virtual void update(const glm::mat4& viewMatrix) = 0;
};

class PointLumiere : public Lumiere {
public:
    ~PointLumiere() override                           = default;
    PointLumiere(const PointLumiere&)                    = default;
    PointLumiere(PointLumiere&&)                         = delete;
    auto operator=(const PointLumiere&) -> PointLumiere& = default;
    auto operator=(PointLumiere&&) -> PointLumiere&      = delete;
    explicit PointLumiere(const glm::vec3& position);
    void update(const glm::mat4& viewMatrix) override;
};

class DirectionalLumiere : public Lumiere {
public:
    ~DirectionalLumiere() override                                 = default;
    DirectionalLumiere(const DirectionalLumiere&)                    = default;
    DirectionalLumiere(DirectionalLumiere&&)                         = delete;
    auto operator=(const DirectionalLumiere&) -> DirectionalLumiere& = default;
    auto operator=(DirectionalLumiere&&) -> DirectionalLumiere&      = delete;
    explicit DirectionalLumiere(const glm::vec3& position);
    void update(const glm::mat4& viewMatrix) override;
};