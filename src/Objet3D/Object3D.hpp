#pragma once
#include "../model3D/model3D.hpp"
#include "../shaders/shader.hpp"
#include "../textures/textures.hpp"
#include "p6/p6.h"

// Manages a 3D object including its model, texture, shader, and OpenGL buffer objects
class Object3D {
private:
    Modele   _model;
    Texture _texture;
    // Shader  _shader;

    GLuint _vbo{};
    GLuint _vao{};

public:
    explicit Object3D(const std::string& nom = "BoundingCube", const std::string& vertexShaderPath = "3D.vs.glsl", const std::string& fragmentShaderPath = "tex3D.fs.glsl");

    void defineVBO();
    void defineVAO();

    std::vector<glimac::ShapeVertex> getMesh() const { return _model.getVertices(); };
    GLuint                           getVAO() const { return _vao; };
    const Modele&                     getModel() const { return _model; };
    const Texture&                   getTexture() const { return _texture; };
    // const Shader&                    getShader() const { return _shader; };

    // Cleans up the resources
    void clear();
};