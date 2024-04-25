#include "joueur.hpp"
#include <iostream>

Joueur::Joueur(p6::Context *ctx, TrackballCamera *camera, float *mapSize)
    : _ctx(ctx), camera(), controls(ctx, camera, mapSize), _position(0.f, 0.f, 0.f)
{
}

void Joueur::handleControls()
{
    // controls.handleCameraZoom();
    // controls.handleCameraRotation();
}

void Joueur::handleMovements()
{
    std::cout << "dedans handlemovements" << std::endl;
    controls.handlePlayerMovements(_position);
}