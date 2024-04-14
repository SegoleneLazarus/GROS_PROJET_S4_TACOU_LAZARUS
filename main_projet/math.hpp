#pragma once
#include "randtest.hpp"
#include <iostream>
#include <vector>

void assign_biomes(std::vector<int> tableau_de_biomes{});

int chaine_de_markov(int biome_actuel);
