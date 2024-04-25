#include "controles.hpp"
#include <iostream>

Controles::Controles(p6::Context *ctx, TrackballCamera *camera, float *mapSize)
    : _ctx(ctx), camera(camera), _mapSize(mapSize){};

void Controles::handlePlayerMovements(glm::vec3 &playerPosition)
{
    if (_ctx->key_is_pressed(GLFW_KEY_W))
    {
        std::cout << "avancer" << std::endl;
        playerPosition.z -= 0.1f;
    }
    if (_ctx->key_is_pressed(GLFW_KEY_S))
    {
        playerPosition.z += 0.1f;
    }
    if (_ctx->key_is_pressed(GLFW_KEY_A))
    {
        playerPosition.x -= 0.1f;
    }
    if (_ctx->key_is_pressed(GLFW_KEY_D))
    {
        playerPosition.x += 0.1f;
    }
}