#include "joueur.hpp"

Joueur::Joueur(p6::Context* ctx, TrackballCamera* camera, float* mapSize)
    : _ctx(ctx), camera(), position(0.f, 0.f, 0.f)
{
        objet3D = Objet3D("ovocyte", "3D.vs.glsl", "tex3D.fs.glsl");
}

// void Joueur::handleControls()
// {
//     controls.handleCameraZoom();
//     controls.handleCameraRotation();
// }

// void Joueur::handleMovements()
// {
//     controls.handleJoueurMovements(position);
// }

// void Joueur::animateJoueur()
// {
//     _hoverTime += _ctx->delta_time();
//     float hoverDelta = _hoverAmplitude * sin(_hoverFrequency * _hoverTime);
//     _position.y      = 0 + hoverDelta;
// }

// void Joueur::initializeGUI()
// {
//     if (ImGui::CollapsingHeader("Joueur"))
//     {
//         ImGui::Indent();
//         controls.initializeGUI();
//         if (ImGui::CollapsingHeader("Animation"))
//         {
//             ImGui::Indent();
//             GUIhelp("Adjust the up & down character animation.");
//             ImGui::SliderFloat("Animation amplitude", &_hoverAmplitude, .01f, .4f);
//             ImGui::SliderFloat("Animation frequency", &_hoverFrequency, .01f, 20.f);
//             ImGui::Unindent();
//         }
//         ImGui::Unindent();
//         // ImGui::SliderFloat("Transparency", &_transparency, .0f, 1.f);
//     }
// }