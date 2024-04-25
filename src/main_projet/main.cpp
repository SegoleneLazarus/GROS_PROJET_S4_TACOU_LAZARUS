#include "glm/fwd.hpp"
#include <cstddef>
#include <cstdlib>

#define DOCTEST_CONFIG_IMPLEMENT
#include "../projetAffich/affichage.hpp"
#include "doctest/doctest.h"
#include "p6/p6.h"
#include "projetAffich/affichage.hpp"


int main() {
  std::srand(time(NULL));
  auto start = std::chrono::high_resolution_clock::now();

  // Run the tests
  if (doctest::Context{}.run() != 0)
    return EXIT_FAILURE;

  ProjetAffich App;

  

  // initialize boids_tab
  std::vector<Boid> boids_tab;
  pushb_boids(boids_tab, 40);
  
  // update loop
  App.update(boids_tab);

  App.start();
  App.stop();
}