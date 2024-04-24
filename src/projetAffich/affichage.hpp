#pragma once
#include <vector>
#include "../../lib/p6/src/Context.h"
#include "../../lib/p6/src/internal/Time/Clock_Realtime.h"
#include "../TrackBallCamera/TrackballCamera.hpp"
#include "../model3D/model3D.hpp"
#include "../objet3D/Objet3D.hpp"
#include "../transfObjet/transfObjet.hpp"
#include "glm/fwd.hpp"
#include "p6/p6.h"

struct Scene {
    float    baseCube = 15.f;
    float    taille         = 20.f;
    float    sol  = 2.f;
    Objet3D boundingCube{"BoundingCube", "3D.vs.glsl", "tex3D.fs.glsl"};
    Objet3D environment{"BoundingCube", "3D.vs.glsl", "tex3D.fs.glsl"};
};

class ProjetAffich {
private:
    p6::Context     _ctx = p6::Context{{.title = "caca"}};
    // GlobalRenderer  _renderer;
    TrackballCamera camera;

    // Player             _player;
    Scene              scene;

    // void gameLogic()
    // {
    //     _player.handleMovements();
    // }

    void render()
    {
        // _renderer.clearAll();

        // _ctx.background(p6::NamedColor::Blue);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        Transform boundingCubeTransform{{0.f, (scene.taille / 2) - scene.sol, 0.f}, {0.f, 0.f, 0.f}, scene.taille / scene.baseCube};
        // _renderer.drawObject(boundingCubeTransform.getTransform(), scene.boundingCube);

        // float     hoverDelta = _hoverAmplitude * sin(_hoverFrequency * _hoverTime);
        // _player.animatePlayer();
        // Transform ghostTransform{_player.getPosition(), {0.f, -_player.getLastOrientation() + 180, 0.f}, .3f};
        _renderer.drawObject(ghostTransform.getTransform(), _player.getObject3D());

    }

    void cleanUp()
    {
        scene.boundingCube.clear();
        // player.getObject3D().clear();
    }

public:
    // explicit ProjetAffich(unsigned int nb_boids)
    //     : _renderer(&_ctx, &_camera), _player(&_ctx, &camera, &_scene.size), camera(&_player.getPosition())
    // {
    //     _ctx.maximize_window();

    //     _player.handleControls();
    // }

    ~ProjetAffich()
    {
        cleanUp();
    }

    void update()
    {
        _ctx.update = [&]() {
            gameLogic();
            render();
        };
    }

    void start()
    {
        _ctx.start();
    }

    void stop()
    {
        cleanUp();
    }
};