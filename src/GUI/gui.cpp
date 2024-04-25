#include "gui.hpp"

// std::vector<Boid>&  GUI::boids_tab             = 40;
float GUI::alignement_force = .5f;
float GUI::separation_force = .5f;
float GUI::cohesion_force = .5f;

void GUI::initializeGUI(std::vector<Boid> &boids_tab, int *precision) {
  ImGui::Begin("Test");
  {
    int nombre_boids = static_cast<int>(boids_tab.size());
    ImGui::SliderInt("Nb de boids", &nombre_boids, 0, 100);
    actualise_boids_tab(boids_tab, nombre_boids);
  }
  ImGui::SliderFloat("Alignement", &alignement_force, 0.f,
                     1.f); // modif de la force
  ImGui::SliderFloat("Séparation", &separation_force, 0.f,
                     1.f); // modif de la force
  ImGui::SliderFloat("Cohésion", &cohesion_force, 0.f,
                     1.f); // modif de la force
  for (auto &boidy : boids_tab) {
    boidy.change_forces(alignement_force, separation_force, cohesion_force);
  }

  ImGui::SliderInt("Précision", precision, 1,
                   3); // modif du niveau de détail
  ImGui::End();
}