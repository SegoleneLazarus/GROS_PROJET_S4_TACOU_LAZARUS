#include "boid_class.hpp"

struct Boid boids;

glm::vec3 normalize_to_vit(glm::vec3 position,
                           glm::vec3 vitesse) { // 3D
  // this fonction allows to normalize a position to the length of a speed (vit
  // as vitesse), it is usefull if I want to use a difference of position
  // between 2 boids to change the speed of one of them (cohesion, separation)
  float length_vit = glm::length(vitesse);
  position = normalize(position) * length_vit;
  return position;
}

void pushb_boids(std::vector<Boid> &boids_tab, int nombre_boids) {
  for (int i = 0; i < nombre_boids; i++) {
    Boid bdt{};
    boids_tab.push_back(bdt);
  }
}

void actualise_boids_tab(std::vector<Boid> &boids_tab, int nombre_boids) {
  if (nombre_boids > boids_tab.size()) {
    pushb_boids(boids_tab, nombre_boids - boids_tab.size());
  } else if (nombre_boids < boids_tab.size()) {
    boids_tab.resize(nombre_boids);
  }
}

void implementation_boids(std::vector<Boid> &boids_tab) {

  for (auto &boidy : boids_tab) {
    boidy.deplacement_boids(boids_tab);
  }
}

