#pragma once
#include "p6/p6.h"

class Shader
{
public:
    p6::Shader shader;
    GLint ID;

    GLint uVMatrix;
    GLint uMMatrix;
    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uTexture;
    GLint uKd;
    GLint uKs;
    GLint uShininess;
    GLint uLightDir_vs;
    GLint uLightPos_vs;
    GLint uLightIntensity;

    explicit Shader(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);
};