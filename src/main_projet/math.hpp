#pragma once
#include "randtest_math.hpp"
#include <vector>
#define nbcB 10.0f // nombres de cases de biomes
#define arrete_cube 2

void assign_biomes(std::vector<int> &tableau_de_biomes);

int chaine_de_markov(int biome_actuel);

float angle_calculum(float x, float y);

// float CLT(); // return a random number from a standard normal distribution
             // following the Central limit theorem