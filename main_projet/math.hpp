#pragma once
#include "randtest_math.hpp"
#include <iostream>
#include <vector>

void assign_biomes(std::vector<int> tableau_de_biomes{});

int chaine_de_markov(int biome_actuel);

float CLT(); // return a random number from a standard normal distribution following the Central limit theorem