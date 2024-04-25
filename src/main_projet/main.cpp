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
  time_t tmm = time(0);
  // Run the tests
  if (doctest::Context{}.run() != 0)
    return EXIT_FAILURE;

  ProjetAffich App;

  

  // initialize boids_tab
  std::vector<Boid> boids_tab;
  pushb_boids(boids_tab, 40);
  
  // update loop
  App.update(boids_tab,tmm);

  App.start();
  App.stop();
}