#include "shader.hpp"

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
    : ID(shader.id()),
    shader{p6::load_shader("assets/shaders/" 
    + vertexShaderPath, "assets/shaders/" 
    + fragmentShaderPath)}, 
    uVMatrix(glGetUniformLocation(ID, "uVMatrix")),
    uMMatrix(glGetUniformLocation(ID, "uMMatrix")),
    uMVPMatrix(glGetUniformLocation(shader.id(), "uMVPMatrix")), 
    uMVMatrix(glGetUniformLocation(shader.id(), "uMVMatrix")), 
    uNormalMatrix(glGetUniformLocation(shader.id(), "uNormalMatrix")), 
    uTexture(glGetUniformLocation(shader.id(), "uTexture"))
    // uKd(glGetUniformLocation(shader.id(), "uKd")), 
    // uKs(glGetUniformLocation(shader.id(), "uKs")), 
    // uShininess(glGetUniformLocation(shader.id(), "uShininess")), 
    // uLightDir_vs(glGetUniformLocation(shader.id(), "uLightDir_vs")), 
    // uLightPos_vs(glGetUniformLocation(shader.id(), "uLightPos_vs")), 
    // uLightIntensity(glGetUniformLocation(shader.id(), "uLightIntensity"))
{
}