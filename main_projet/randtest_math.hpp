#pragma once
#define M_PI 3.14159265358979323846 /* pi */
#include "boid_class.hpp"
#include <cmath>
#include <ctime>
#include <iostream>
#include <math.h>
#include <random>
#include <time.h>

double rand01();

int pile_ou_face(double p);

int de6_eq();

int deX();

// int de6_deseq(double p);

// double esperance_exponentielle(double lambda, int N);

float expo(float lambda);

// float variance_exp(double lambda, int N);

float loi_uniforme(float borne_bas, float borne_haut);

float CLT(int precision);

glm::vec2 CLT2D(int precision);

