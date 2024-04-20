#pragma once
#define M_PI 3.14159265358979323846 /* pi */
#include <cmath>
#include <ctime>
#include <iostream>
#include <math.h>
#include <random>
#include <time.h>
#include "glm/fwd.hpp"
#include "glm/glm.hpp"


double rand01();

int pile_ou_face(double p);

int de6_eq();

int deX(int nombre_de_faces);

// int de6_deseq(double p);

// double esperance_exponentielle(double lambda, int N);

float loi_uniforme(float borne_bas, float borne_haut);

float expo(float lambda);

// float variance_exp(double lambda, int N);


float CLT(int precision);

int loi_geometrique_inverse(float p);
    
glm::vec2 CLT2D(int precision);

