#pragma once
#include <cmath>
#include <iostream>
#include <random>
#include <time.h>

float randfm11(); // entre -1 et 1

int pile_ou_face(double p);

int de6_eq();

int deX();

// int de6_deseq(double p);

// double esperance_exponentielle(double lambda, int N);

float expo(float lambda);

// float variance_exp(double lambda, int N);

float loi_uniforme(float borne_bas, float borne_haut);
