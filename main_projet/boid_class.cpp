#include "boid_class.hpp"

struct Boid boids;

glm::vec3 normalize_to_vit(glm::vec3 position,
                           glm::mediump_vec3 vitesse) { // 3D
  // this fonction allows to normalize a position to the length of a speed (vit
  // as vitesse), it is usefull if I want to use a difference of position
  // between 2 boids to change the speed of one of them (cohesion, separation)
  float length_vit = glm::length(vitesse);
  position = normalize(position) * length_vit;
  return position;
}

