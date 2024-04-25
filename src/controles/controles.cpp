#include "controles.hpp"
#include <iostream>

Controles::Controles(p6::Context* ctx, TrackballCamera* camera, float* mapSize)
    : _ctx(ctx), camera(camera), _mapSize(mapSize){};

// void Controls::handleCameraZoom()
// {
//     _ctx->mouse_scrolled = [&](p6::MouseScroll scroll) {
//         if (scroll.dy > 0 && (camera->getDistance() - _scrollSensitivity >= _minScrollDistance))
//         {
//             camera->moveFront(_scrollSensitivity);
//         }
//         else if (scroll.dy < 0 && (camera->getDistance() + _scrollSensitivity <= _maxScrollDistance))
//         {
//             camera->moveFront(-_scrollSensitivity);
//         }
//     };
// };

// void Controls::handleCameraRotation()
// {
//     _ctx->mouse_dragged = [&](p6::MouseDrag mouse_drag) {
//         if (ImGui::IsWindowFocused(ImGuiFocusedFlags_AnyWindow))
//             return;
//         camera->rotateLeft(-mouse_drag.delta.x * _mouseSensitivity);
//         camera->rotateUp(mouse_drag.delta.y * _mouseSensitivity);
//     };
// }

void Controles::handlePlayerMovements(glm::vec3& playerPosition)
{
    if (_ctx->key_is_pressed(GLFW_KEY_W))
    {
        std::cout << "avancer" << std::endl;
        playerPosition.z -= 0.1f; // Move forward
    }
    if (_ctx->key_is_pressed(GLFW_KEY_S))
    {
        playerPosition.z += 0.1f; // Move backward
    }
    if (_ctx->key_is_pressed(GLFW_KEY_A))
    {
        playerPosition.x -= 0.1f; // Move left
    }
    if (_ctx->key_is_pressed(GLFW_KEY_D))
    {
        playerPosition.x += 0.1f; // Move right
    }
}