#pragma once
#include "../../lib/p6/src/Context.h"
#include "../../lib/p6/src/internal/Time/Clock_Realtime.h"
#include "../GUI/gui.hpp"
#include "../TrackBallCamera/TrackballCamera.hpp"
#include "../model3D/model3D.hpp"
#include "../joueur/joueur.hpp"
#include "../objet3D/Objet3D.hpp"
// #include "../controle/Controls.hpp"
#include "../transfObjet/transfObjet.hpp"
#include "glm/fwd.hpp"
#include "p6/p6.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>

struct Scene {
    float    baseCube = 15.f;
    float    taille         = 20.f;
    float    sol  = 2.f;
    Objet3D environnement{"cube", "3D.vs.glsl", "tex3D.fs.glsl"};
    Objet3D ovocyte{"ovocyte", "3D.vs.glsl", "tex3D.fs.glsl"};
    // Objet3D spermatoïde{"spermatoïde", "3D.vs.glsl", "tex3D.fs.glsl"};
    std::vector<std::pair<float, float>> positions;

};

class Rendu {
private:
    static float     _uKd;             // [GUI]
    static float     _uKs;             // [GUI]
    static float     _uLightIntensity; // [GUI]
    static float     _uShininess;      // [GUI]
    static glm::vec3 lightDir;        // [GUI]

  std::vector<Objet3D> objets;
  p6::Context *_ctx;
  TrackballCamera *camera;

public:
  explicit Rendu(p6::Context *ctx, TrackballCamera *camera);

  void dessinObjet(const glm::mat4 &modelMatrix, const Objet3D &objet, float transparency) const;
  void clearAll();
};

class ProjetAffich {
private:
  p6::Context _ctx = p6::Context{{.title = "caca"}};
  Rendu rendu;
  TrackballCamera camera;
  // Joueur  joueur;
  Scene scene;

  void affichageGUI() { GUI::initializeGUI(); };

  // void gameLogic()
  // {
  //     joueur.handleMovements();
  // }

  void render() {
    rendu.clearAll();

    _ctx.background(p6::NamedColor::Yellow);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

        Transform transfEnviro{{0.f, (scene.taille / 2) - scene.sol, 0.f}, {0.f, 0.f, 0.f}, scene.taille / scene.baseCube};
        rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement, 0);
        // Transform transfEnviro{{0.f, (scene.taille / 2) - scene.sol, 0.f}, {0.f, 0.f, 0.f}, scene.taille / scene.baseCube};
        // rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement);
        // Transform transfEnviro{{0.f, (scene.taille / 2) - scene.sol, 0.f}, {0.f, 0.f, 0.f}, scene.taille / scene.baseCube};
        // rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement);

        // Transform transfOvocyte{joueur.getPosition(), {0.f, -joueur.getLastOrientation() +180, 0.f}, .3f};
        // rendu.dessinObjet(transfOvocyte.getTransform(), joueur.getObjet3D(), joueur.getTransparency());

    // float     hoverDelta = _hoverAmplitude * sin(_hoverFrequency *
    // _hoverTime); _player.animatePlayer(); Transform
    // ghostTransform{_player.getPosition(), {0.f, -_player.getLastOrientation()
    // + 180, 0.f}, .3f}; _renderer.drawObject(ghostTransform.getTransform(),
    // _player.getObject3D());
  }


    void cleanUp()
    {
        scene.environnement.clear();
        // scene.spermatoïde.clear();
        scene.ovocyte.clear();
    };

public:
  explicit ProjetAffich()
      : rendu(&_ctx, &camera) 
      // , joueur(&_ctx, &camera, &scene.taille), camera(&joueur.getPosition())
  {
    _ctx.maximize_window();
    //     _player.handleControls();
  }

  ~ProjetAffich() { cleanUp(); }

  void update() {
    _ctx.update = [&]() {
      // game not so Logic();
      //
      // Setup context GUI
      GUI::initializeGUI();

      // Boid boids_tab=implementation_boid();

      //affichage boids(boids_tab) ;

      render();
    };
  }

  void start() { _ctx.start(); }

  void stop() { cleanUp(); }
};
