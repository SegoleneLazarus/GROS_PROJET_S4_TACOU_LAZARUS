#pragma once
#include "../../lib/p6/src/Context.h"
#include "../../lib/p6/src/internal/Time/Clock_Realtime.h"
#include "../GUI/gui.hpp"
#include "../TrackBallCamera/TrackballCamera.hpp"
#include "../joueur/joueur.hpp"
// #include "../controles/controles.hpp"
// #include "../lumiere/lumiere.hpp"
#include "../model3D/model3D.hpp"
#include "../objet3D/Objet3D.hpp"

// #include "../controle/Controls.hpp"
#include "../transfObjet/transfObjet.hpp"
#include "glm/fwd.hpp"
#include "main_projet/math.hpp"
#include "p6/p6.h"
#include <glm/gtc/type_ptr.hpp>
#include <vector>

struct Scene
{
  float baseCube = 15.f;
  float taille = 50.f;
  Objet3D environnement{"cube", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D ovocyte{"ovocyte", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D spermato{"spermato", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D spermato_m790{"spermato_m790", "3D.vs.glsl", "tex3D.fs.glsl"};
  Objet3D spermato_tete{"spermato_tete", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D arbre{"arbre", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D champi{"champi", "3D.vs.glsl", "tex3D.fs.glsl"};
  // Objet3D poissong{"poissong", "3D.vs.glsl", "tex3D.fs.glsl"};
};

class Rendu
{
private:
  static float _uKd;
  static float _uKs;
  static float _uLightIntensity;
  static float _uShininess;
  static glm::vec3 lightDir;

  std::vector<Objet3D> objets;
  p6::Context *_ctx;
  TrackballCamera *camera;
  // Joueur joueur(glm::vec3(0.f, 0.f, 0.f));
  // Camera camera(joueur.getPosition());

public:
  explicit Rendu(p6::Context *ctx, TrackballCamera *camera);

  void dessinObjet(const glm::mat4 &modelMatrix, const Objet3D &objet) const;
  void clearAll();
};

class ProjetAffich
{
private:
  p6::Context _ctx = p6::Context{{.title = "La rencontre"}};
  Rendu rendu;
  TrackballCamera camera;
  Joueur joueur;
  Scene scene;

  int precision = 1;

  void affichageGUI(std::vector<Boid> &boids_tab)
  {
    GUI::initializeGUI(boids_tab, precision);
  }

  void generate_terrain(std::vector<int> &tableau_de_biomes,
                        std::vector<std::vector<Objet3D>> &tableau_obstacles)
  {

    assign_biomes(tableau_de_biomes);

    // std::vector<Objet3D> foret_rouge;
    // std::vector<Objet3D> royaume_champignon;
    // std::vector<Objet3D> ocean_sauvage;
    // foret_rouge.push(scene.arbre);
    // royaume_champignon.push(scene.champi);
    // ocean_sauvage.push(scene.poissong);
    // possiblement plus que 1 seul;

    // tableau_obstacles.push_back(foret_rouge);
    // tableau_obstacles.push_back(royaume_champignon);
    // tableau_obstacles.push_back(ocean_sauvage);
  }

  void draw_boids(std::vector<Boid> &boids_tab)
  {

    for (auto &boidy : boids_tab)
    {
      glm::vec3 position = boidy.transform_boid_pos();
      glm::vec3 rotation = boidy.transform_boid_rot();
      Transform transfBoid{position, rotation, {0.01f, 0.01f, 0.01f}};
      // Transform transfBoid{boidy.transform_boid_pos(),
      //                      boidy.transform_boid_rot(),
      //                      {0.01f, 0.01f, 0.01f}};

      // transfBoid.setPosition(boidy.transform_boid_pos());
      // transfBoid.setRotation(boidy.transform_boid_rot());

      if (precision == 1)
      {
        rendu.dessinObjet(transfBoid.getTransform(), scene.spermato);
      }
      else if (precision == 2)
      {
        rendu.dessinObjet(transfBoid.getTransform(), scene.spermato_m790);
      }
      else if (precision == 3)
      {
        rendu.dessinObjet(transfBoid.getTransform(), scene.spermato_tete);
      }
    }
  }

  void draw_obstacle(std::vector<std::vector<Objet3D>> &tableau_obstacles,
                     std::vector<int> tableau_de_biomes)
  {
    for (int i = 0; i < nbcB; i++) // parcours la hauteur, a c'est le
                                   // nombre de cases biome dans le cube
    {
      for (int j = 0; j < nbcB; j++) // parcours les colonnes
      {
        for (int k = 0; k < nbcB; k++) // parcours les lignes
        {
          int compteur = k + j * int(nbcB) + i * int(nbcB * nbcB);
          if (true) // TODO aléatoire présence ou non d'élément
          {
            float a = float(arrete_cube) / nbcB;

            glm::vec3 position(k * a, j * a, i * a);
            Transform transfobstacle{
                position, {0.f, 0.f, 0.f}, {0.001f, 0.001f, 0.001f}};
            // tableau_obstacles a 3 vecteurs à l'intérieur qui
            // contiennent chacun les obstacles pour chaque élément. Dé
            // 1 car pour l'instant on a qu'un seule obstacle par
            // biome.l

            //   rendu.dessinObjet(
            //       transfobstacle.getTransform(),
            //       scene.tableau_obstacles[tableau_de_biomes[compteur]][deX(1)]);
            // }
          }
        }
      }
    }
  }

  void cameraMove()
  {
    _ctx.mouse_moved = [&](p6::MouseMove event)
    {
      std::cout << event.delta.x << std::endl;
      const float sensitivity = 150.f; // Ajustez à votre convenance
      camera.rotateLeft(event.delta.x * sensitivity);
      camera.rotateUp(-event.delta.y *
                      sensitivity); // Inversion de Y pour une rotation intuitive
    };

    _ctx.mouse_scrolled = [&](p6::MouseScroll event)
    {
      camera.moveFront(event.dy);
    };
  }

  // void render(std::vector<Boid> &boids_tab, int precision,
  //             std::vector<std::vector<Objet3D>> &tableau_obstacles,
  //             std::vector<int> tableau_de_biomes)
  void render(std::vector<Boid> &boids_tab)
  {
    rendu.clearAll();

    _ctx.background(p6::NamedColor::Yellow);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    Transform transfEnviro{
        {0.f, (-arrete_cube * scene.taille / scene.baseCube) / 2, 0.f},
        {0.f, 0.f, 0.f},
        arrete_cube * scene.taille / scene.baseCube / 2};
    // Transform transfDecor{
    //     {1.f, -1.f, 3.f}, {0.f, 0.f, 0.f}, {0.1f, 0.1f, 0.1f}};
    rendu.dessinObjet(transfEnviro.getTransform(), scene.environnement);
    // rendu.dessinObjet(transfEnviro.getTransform(), scene.poissong);
    // rendu.dessinObjet(transfDecor.getTransform(), scene.champi);
    // rendu.dessinObjet(transfEnviro.getTransform(), scene.arbre);

    draw_boids(boids_tab);

    // draw_obstacle(tableau_obstacles, tableau_de_biomes);

    Transform transfOvocyte{joueur.getPosition(), {0.f, 0.f, 0.f}, 1.f};
    rendu.dessinObjet(transfOvocyte.getTransform(), joueur.getObjet3D());
  }

  void cleanUp()
  {
    scene.environnement.clear();
    scene.spermato.clear();
    scene.spermato_m790.clear();
    scene.spermato_tete.clear();
    // scene.poissong.clear();
    // scene.champi.clear();
    // scene.arbre.clear();
    // scene.ovocyte.clear();
    scene.environnement.clear();
    joueur.getObjet3D().clear();
  }

public:
  explicit ProjetAffich()
      : rendu(&_ctx, &camera), joueur(&_ctx, &camera, &scene.taille), camera(&joueur.getPosition())
  // _player(&_ctx, &camera, &_scene.size),
  // camera(&_player.getPosition())
  {
    _ctx.maximize_window();
    joueur.handleControls();
  }

  ~ProjetAffich() { cleanUp(); }

  void update(std::vector<Boid> &boids_tab)
  {
    std::vector<int> tableau_de_biomes;
    // std::vector<std::vector<Objet3D>> tableau_obstacles;

    cameraMove();

    for (auto &boidy : boids_tab)
    {
      boidy.spawn_boids_repartition_exp();
    }
    // generate_terrain(tableau_de_biomes, tableau_obstacles);
    _ctx.update = [&]()
    {
      joueur.handleMovements();
      
      // game not so Logic();

      // Setup context GUI

      GUI::initializeGUI(boids_tab, precision);

      for (auto &boidy : boids_tab)
      {
        boidy.deplacement_boids(boids_tab);
      }

      render(boids_tab);
      // render(boids_tab, precision, tableau_obstacles, tableau_de_biomes);
    };
  }

  void start() { _ctx.start(); }

  void stop() { cleanUp(); }
};
