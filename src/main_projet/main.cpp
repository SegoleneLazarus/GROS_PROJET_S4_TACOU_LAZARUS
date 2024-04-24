#include "glm/fwd.hpp"
#include <cstddef>
#include <cstdlib>

#define DOCTEST_CONFIG_IMPLEMENT
<<<<<<< HEAD
=======
#include "../projetAffich/affichage.hpp"
>>>>>>> 4b654013182bb0bde9eea387eea204cc0932fc94
#include "doctest/doctest.h"
#include "p6/p6.h"
#include "projetAffich/affichage.hpp"


int main() {
  std::srand(time(NULL));

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