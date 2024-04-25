#pragma once
#include "../main_projet/boid_class.hpp"
#include "glm/fwd.hpp"

#include <imgui.h>

class GUI
{
private:
  static float alignement_force;
  static float separation_force;
  static float cohesion_force;
  static int precision;

public:
  static void initializeGUI(std::vector<Boid> &boids_tab, int &precision);
};