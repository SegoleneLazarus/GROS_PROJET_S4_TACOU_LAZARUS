#include "glm/fwd.hpp"
#include <cstddef>
#include <cstdlib>

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#include "p6/p6.h"
#include "projetAffich/affichage.hpp"


int main() {
  std::srand(time(NULL));

  // Run the tests
  if (doctest::Context{}.run() != 0)
    return EXIT_FAILURE;

  ProjetAffich App;

  // update loop

  App.update();

  App.start();
  App.stop();
}