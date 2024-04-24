#pragma once
#include "../model3D/model3D.hpp"
#include "../shaders/shader.hpp"
#include "../textures/textures.hpp"
#include "../src-common/glimac/common.hpp"
#include "p6/p6.h"

// comment gérer un objet 3D bienvenue dans mon podcast
class Objet3D {
private:
    Modele   modele;
    Texture texture;
    Shader  shader;

    GLuint vbo{};
    GLuint vao{};

public:
    explicit Objet3D(const std::string& nom = "cube", const std::string& vertexShaderPath = "3D.vs.glsl", const std::string& fragmentShaderPath = "tex3D.fs.glsl");

    void defineVBO();
    void defineVAO();

    std::vector<glimac::ShapeVertex> getMesh() const { return modele.getVertices(); };
    GLuint                           getVAO() const { return vao; };
    const Modele&                     getModel() const { return modele; };
    const Texture&                   getTexture() const { return texture; };
    const Shader&                    getShader() const { return shader; };

    // Cleans up the resources
    void clear();
};