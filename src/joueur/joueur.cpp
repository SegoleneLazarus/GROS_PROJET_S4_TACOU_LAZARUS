#include "joueur.hpp"

// Constructor definition
Joueur::Joueur(p6::Context* ctx, TrackballCamera* camera, Objet3D objet3D)
    : _ctx(ctx), camera(camera), objet3D("ovocyte", "3D.vs.glsl", "tex3D.fs.glsl"),
      position(0.f, 0.f, 0.f), hoverAmplitude(0.1f), hoverFrequency(2.0f), hoverTime(0.0f)
{
    // Initialize the player
        objet3D = Objet3D("ovocyte", "3D.vs.glsl", "tex3D.fs.glsl");
}

// Method to handle player controls
// void Player::handleControls()
// {
//     _controls.handleCameraZoom();
//     _controls.handleCameraRotation();
// }

// Method to handle player movements
// void Player::handleMovements()
// {
//     _controls.handlePlayerMovements(_position);
// }

// Method to animate the player
// void Player::animatePlayer()
// {
//     _hoverTime += _ctx->delta_time();
//     float hoverDelta = _hoverAmplitude * sin(_hoverFrequency * _hoverTime);
//     _position.y = 0 + hoverDelta;
// }

// Method to initialize the GUI
// void Player::initializeGUI()
// {
//     _controls.initializeGUI();
//     ImGui::Begin("Character look parameters");
//     ImGui::SliderFloat("Animation amplitude", &_hoverAmplitude, 0.01f, 0.4f);
//     ImGui::SliderFloat("Animation frequency", &_hoverFrequency, 0.01f, 20.f);
//     ImGui::End();
// }
