#pragma once
#include "../../lib/p6/src/Context.h"
#include "../../lib/p6/src/internal/Time/Clock_Realtime.h"
#include "../GUI/gui.hpp"
#include "../TrackBallCamera/TrackballCamera.hpp"
#include "../joueur/joueur.hpp"
#include "../lumiere/lumiere.hpp"
#include "../model3D/model3D.hpp"
#include "../objet3D/Objet3D.hpp"

// #include "../controle/Controls.hpp"
#include "../transfObjet/transfObjet.hpp"
#include "glm/fwd.hpp"
#include "p6/p6.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>

struct Scene {
  float baseCube = 15.f;
  float taille = 50.f;
  Objet3D environnement{"cube", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D ovocyte{"ovocyte", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D spermato{"spermato", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D spermato_m790{"spermato_m790", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D spermato_tete{"spermato_tete", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D arbre{"arbre", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D champi{"champi", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D poissong{"poissong", "3D.vs.glsl", "tex3D.fs.glsl"};
};

class Rendu {
private:
  static float _uKd;
  static float _uKs;
  static float _uLightIntensity;
  static float _uShininess;
  static glm::vec3 lightDir;

  std::vector<Objet3D> objets;
  p6::Context *_ctx;
  TrackballCamera *camera;

public:
  explicit Rendu(p6::Context *ctx, TrackballCamera *camera);

  void dessinObjet(const glm::mat4 &modelMatrix, const Objet3D &objet) const;
  void clearAll();
};

class ProjetAffich {
private:
  p6::Context _ctx = p6::Context{{.title = "La rencontre"}};
  Rendu rendu;
  TrackballCamera camera;
  // Joueur  joueur;
  Scene scene;

  // std::map<std::string, std::unique_ptr<Lumiere>> _lightsMap;

  // void renderLights();

  void affichageGUI(std::vector<Boid> &boids_tab, int precision) {
    GUI::initializeGUI(boids_tab, &precision);
  }

  void draw_boids(std::vector<Boid> &boids_tab, int precision) {
    Transform transfBoid{
        {0.f, 0.f, 0.f}, {0.f, 0.f, 0.f}, {0.01f, 0.01f, 0.01f}};
    for (auto &boidy : boids_tab) {
      transfBoid.setPosition(boidy.transform_boid_pos());
      transfBoid.setRotation(boidy.transform_boid_rot());

      if (precision == 1) {
        rendu.dessinObjet(transfBoid.getTransform(), scene.spermato);
      }
      if (precision == 2) {
        rendu.dessinObjet(transfBoid.getTransform(), scene.spermato_m790);
      }
      if (precision == 3) {
        rendu.dessinObjet(transfBoid.getTransform(), scene.spermato_tete);
      }
    }
  }

  void render(std::vector<Boid> &boids_tab, int precision) {
    rendu.clearAll();

    _ctx.background(p6::NamedColor::Yellow);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    Transform transfEnviro{{1.f, -1.f, 3.f},
                           {0.f, 0.f, 0.f},
                           arrete_cube * scene.taille / scene.baseCube};
    // Transform transfDecor{
    //     {1.f, -1.f, 3.f}, {0.f, 0.f, 0.f}, {0.1f, 0.1f, 0.1f}};
    rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement);
    // rendu.dessinObjet(transfEnviro.getTransform(), scene.poissong);
    // rendu.dessinObjet(transfDecor.getTransform(), scene.champi);
    // rendu.dessinObjet(transfEnviro.getTransform(), scene.arbre);

    draw_boids(boids_tab, precision);

    // Transform transfOvocyte{joueur.getPosition(), {0.f,
    // -joueur.getLastOrientation() +180, 0.f}, .3f};
    // rendu.dessinObjet(transfOvocyte.getTransform(), joueur.getObjet3D(),
    // joueur.getTransparency());
  }

  void cleanUp() {
    scene.environnement.clear();
    scene.spermato.clear();
    // scene.poissong.clear();
    // scene.champi.clear();
    // scene.arbre.clear();
    // scene.ovocyte.clear();
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
    int precision = 1;
    _ctx.update = [&]() {
      // game not so Logic();

      // Setup context GUI

      GUI::initializeGUI(boids_tab, &precision);

      implementation_boids(boids_tab);

      render(boids_tab, precision);
    };
  }

  void start() { _ctx.start(); }

  void stop() { cleanUp(); }
};
