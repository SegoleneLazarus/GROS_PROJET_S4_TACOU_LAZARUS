#pragma once
#include "glm/fwd.hpp"
#include "glm/glm.hpp"
#include "math.hpp"
#include "p6/p6.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include <time.h>


glm::vec3 normalize_to_vit(glm::vec3 position, glm::vec3 vitesse); // 3D

void spawn_boids_repartition_exp(const std::vector<Boid> &boids_tab); // 3D

struct Boid {
private:
  float separationRadius;
  float cohesionRadius;
  float alignementRadius;

public:
  glm::vec3 pos;
  glm::vec3 vit;
  Boid(float sepRad = 0.1, float cohRad = 0.1, float aliRad = 0.3) // 3D
      : pos(loi_uniforme(-1, 1), loi_uniforme(-1, 1), loi_uniforme(-1, 1)),
        vit(loi_uniforme(-0.01, 0.01), loi_uniforme(-0.01, 0.01),
            loi_uniforme(-0.01, 0.01)),
        separationRadius(sepRad), cohesionRadius(cohRad),
        alignementRadius(aliRad){};

  void limites() { // 3D
    if (abs(pos.x) >= 1)
      pos.x = -pos.x / abs(pos.x);
    if (abs(pos.y) >= 1)
      pos.y = -pos.y / abs(pos.y);
    if (abs(pos.z) >= 1)
      pos.z = -pos.z / abs(pos.z);
  }

  void alignement(const std::vector<Boid> &boids_tab,
                  float alignementForce) { // 3D
    glm::vec3 somme_vit(0.0f, 0.0f, 0.0f);
    float nb_Bproches = 0;

    for (const auto &other : boids_tab) {
      if (distance(other.pos, pos) < alignementRadius) {
        somme_vit += normalize_to_vit(other.vit, vit);
        nb_Bproches++;
      }
    }
    vit = normalize_to_vit(
        vit + somme_vit * (1.f / nb_Bproches) * alignementForce * 10.f, vit);
  }

  void separation(const std::vector<Boid> &boids_tab,
                  float separationForce) { // 3D
    float distance_mini = 10;
    glm::vec3 this_minus_other_pos(0.0f, 0.0f, 0.0f);

    float distance = 0;

    for (const auto &other : boids_tab) {
      if (&other != this) {
        distance = glm::distance(other.pos, pos);

        if (distance < distance_mini) {
          this_minus_other_pos = pos - other.pos;
          distance_mini = distance;
        }
      }
    }
    if (distance_mini < separationRadius) {
      glm::vec3 modifier = normalize_to_vit(this_minus_other_pos, vit) *
                           separationForce * (1.f / (distance_mini * 20));

      vit = normalize_to_vit(vit + modifier, vit);
    }
  }

  void cohesion(const std::vector<Boid> &boids_tab, float cohesionForce) { // 3D
    // version où tout les autres boids influencent la direction de notre boid
    // de manière inversement proportionelle à la distance
    glm::vec3 somme_other_dif_pos(0.0f, 0.0f, 0.0f);
    for (const auto &other : boids_tab) {
      if (&other != this) {
        float distance = glm::distance(other.pos, pos);
        if (distance > this->cohesionRadius) {
          somme_other_dif_pos += (pos - other.pos) * (1.f / (distance));
        }
      }
    }
    vit = normalize_to_vit(vit - normalize_to_vit(somme_other_dif_pos, vit) *
                                     cohesionForce * (1.f / 10),
                           vit);
  }

  void deplacement_boids(const std::vector<Boid> &boids_tab, // 3D
                         const float cohesion_force,
                         const float separation_force,
                         const float alignement_force) {
    this->cohesion(boids_tab, cohesion_force);
    this->separation(boids_tab, separation_force);
    this->alignement(boids_tab, alignement_force);
    pos = pos + vit;
    this->limites();
  }

  int find_biome(
      std::vector<int>
          tableau_de_biomes{}) // on va réutiliser la manière dont on a généré
                               // les biomes pour retrouver le biome en fonction
                               // de la position du boid :DDDDDDDDDDDDD sounds
                               // fun ; hehe do u remember how we coded the
                               // biomes generation ??? With a tab... more
                               // precisely a vector; like a vec1 ... :D ....
                               // FOR A 3 DIMENTIONAL TABLE!!!!!!!!!
  {
    // k c'est les lignes x, j les colonnes y, i la hauteur z
    int k = 0;
    int j = 0;
    int i = 0;
    float a = float(arrete_cube) / nbcB;
    while (pos.x > k * a)
      k++;
    while (pos.y > j * a)
      j++;
    while (pos.z > i * a)
      i++;

    return tableau_de_biomes[k + j * nbcB + i * nbcB * nbcB];
  } // simple ^^

  int assign_DND_alignement(std::vector<int> tableau_de_biomes{}) {
    // on va définir le biome aléatoirement seloin une grille de 9 cases et à
    // l'aide d'une distribution normale centrée sur l'une de ces cases

    // tout d'abord trouver le biome

    int biome = this->find_biome(std::vector<int> tableau_de_biomes{});

    // on définie sur quelle case est centrée la distribution, le tableau
    // imaginaire va de 1,1 à -1,-1 comme l'écran opengl
    if (biome == 1)
      glm::vec2 centre(0.0f, -0.5f);                // foret rouge
    elif (biome == 2) glm::vec2 centre(0.5f, 0.0f); // royaume champignon
    else glm::vec2 centre(-0.5f, 0.5f);             // océan sauvage
    glm::vec2 position = centre + CLT2D(50);

    // déterminer l'alignement en fonction de la position sur la grille
    // imaginaire, de haut en gauche à bas en droite,
    float x = position.x;
    float y = position.y;
    if (y > 0.333) {
      if (x < -0.333)
        return 1;
      elif (x < 0.333) return 2;
      else return 3;
    }
    elif (y > -0.333) {
      if (x < -0.333)
        return 4;
      elif (x < 0.333) return 5;
      else return 6;
    }
    else {
      if (x < -0.333)
        return 7;
      elif (x < 0.333) return 8;
      else return 9;
    }
  }

  

  void draw_boid(p6::Context &ctx) { // 2D
    ctx.circle(p6::Center{pos}, p6::Radius{0.02f});
  }
};
