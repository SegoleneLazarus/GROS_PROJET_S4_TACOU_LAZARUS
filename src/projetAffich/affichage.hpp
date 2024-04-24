#pragma once
#include "../../lib/p6/src/Context.h"
#include "../../lib/p6/src/internal/Time/Clock_Realtime.h"
#include "../GUI/gui.hpp"
#include "../TrackBallCamera/TrackballCamera.hpp"
#include "../model3D/model3D.hpp"
#include "../objet3D/Objet3D.hpp"
#include "../transfObjet/transfObjet.hpp"
#include "glm/fwd.hpp"
#include "p6/p6.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>

struct Scene {
  float baseCube = 15.f;
  float taille = 20.f;
  float sol = 2.f;
  Objet3D environnement{"cube", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D ovocyte{"ovocyte_avec_noyau", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D spermatoïde{"spermatoïde", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D environnement{"cube", "3D.vs.glsl", "tex3D.fs.glsl"};
};

class Rendu {
private:
  std::vector<Objet3D> objets;
  p6::Context *_ctx;
  TrackballCamera *camera;

public:
  explicit Rendu(p6::Context *ctx, TrackballCamera *camera);

  void dessinObjet(const glm::mat4 &modelMatrix, const Objet3D &objet) const;
  void clearAll();
  // static void initializeGUI();
  void ajoutObj(Objet3D &objets);
  void clearObjets();
  void close();
};

class ProjetAffich {
private:
  p6::Context _ctx = p6::Context{{.title = "caca"}};
  Rendu rendu;
  TrackballCamera camera;

  // Player             _player;
  Scene scene;

  void affichageGUI(std::vector<Boid> &boids_tab) {
    GUI::initializeGUI(boids_tab);
  }

  // void gameLogic()
  // {
  //     _player.handleMovements();
  // }

  void render() {
    rendu.clearAll();

    // _ctx.background(p6::NamedColor::Blue);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    Transform transfEnviro{{0.f, (scene.taille / 2) - scene.sol, 0.f},
                           {0.f, 0.f, 0.f},
                           scene.taille / scene.baseCube};
    rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement);
    // Transform transfEnviro{{0.f, (scene.taille / 2) - scene.sol, 0.f}, {0.f,
    // 0.f, 0.f}, scene.taille / scene.baseCube};
    // rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement);
    // Transform transfEnviro{{0.f, (scene.taille / 2) - scene.sol, 0.f}, {0.f,
    // 0.f, 0.f}, scene.taille / scene.baseCube};
    // rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement);

    // float     hoverDelta = _hoverAmplitude * sin(_hoverFrequency *
    // _hoverTime); _player.animatePlayer(); Transform
    // ghostTransform{_player.getPosition(), {0.f, -_player.getLastOrientation()
    // + 180, 0.f}, .3f}; _renderer.drawObject(ghostTransform.getTransform(),
    // _player.getObject3D());
  }

  void cleanUp() {
    scene.environnement.clear();
    scene.spermatoïde.clear();
    scene.ovocyte.clear();
    scene.environnement.clear();
  }

public:
  explicit ProjetAffich()
      : rendu(&_ctx, &camera)
  // _player(&_ctx, &camera, &_scene.size),
  // camera(&_player.getPosition())
  {
    _ctx.maximize_window();
    //     _player.handleControls();
  }

  ~ProjetAffich() { cleanUp(); }

  void update(std::vector<Boid> &boids_tab) {
    _ctx.update = [&]() {
      // game not so Logic();

      // Setup context GUI
      GUI::initializeGUI(boids_tab);

      implementation_boids(boids_tab);

      // affichage boids(boids_tab)

      render();
    };
  }

  void start() { _ctx.start(); }

  void stop() { cleanUp(); }
};
