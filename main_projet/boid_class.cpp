#include "boid_class.hpp"
#include "glm/fwd.hpp"

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

void spawn_boids_repartition_exp( // 3D
    const std::vector<Boid>
        &boids_tab) { // objectif : donner une répartition du spawn des boids
                      // suivant une probabilité exponentielle qui fait
                      // apparaitre principalement vers les extrémités du
                      // cube, le spawn étant centré
  for (const auto &other : boids_tab) {
    float random = expo(1);
    while (random > 4) // on néglige les résultats extrèmes;
      random = expo(1);
    float norme =
        (4 - expo(1)) *
        0.25; // en gros 1-expo/4 pour bien avoir  bc de boids vers l'extérieur
    other.pos = normalize(other.pos) *
                norme; // on a pas changé la direction, seulement la norme
  }
}