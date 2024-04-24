#include <cstddef>
#include <cstdlib>
#include "glm/fwd.hpp"
#define DOCTEST_CONFIG_IMPLEMENT
#include "../projetAffich/affichage.hpp"
#include "doctest/doctest.h"
#include "p6/p6.h"

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