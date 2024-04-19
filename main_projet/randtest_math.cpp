#include "randtest_math.hpp"
// #include <cmath>
// #include <ctime>
// #include <iostream>
// #include <math.h>
// #include <random>
// #include <time.h>
// #include "glm/fwd.hpp"
// #include "glm/glm.hpp"

double rand01() {
  thread_local std::default_random_engine gen{time(NULL)};
  thread_local auto distrib = std::uniform_real_distribution<double>{0.0, 1.0};

  return distrib(gen);
}

// double rand01() {
//   thread_local std::default_random_engine gen{std::random_device{}()};
//   thread_local auto distrib =
//   std::uniform_real_distribution<double>{0.0, 1.0};

//   return distrib(gen);
// }

/*void fonction_rand_1()
{
    srand((unsigned)time(NULL));

    int precision=10;
    double nombre01=0;
    int puissance2=1;
    for(int i=0;i<precision;i++){
        puissance2*=2;
        nombre01+=(rand()%2)*1/puissance2;
    }
    std::cout<<"lol"<<nombre01<<std::endl;

}*/

int pile_ou_face(double p) {
  double random = rand01();
  if (p > random) {
    return 0;
  } else {
    return 1;
  }
}

int de6_eq() {
  double random = 6 * rand01();
  for (int i = 1; i < 7; i++) {
    if (random < i) {
      return i;
    }
  }
}

float loi_uniforme(float borne_bas, float borne_haut) {
  float random = rand01();
  random = random * (borne_haut - borne_bas) + borne_bas;
  return random;
}

float expo(float lambda) { return -std::log(1 - loi_uniforme(0, 1)) / lambda; }

// int de6_deseq()
// {
//     double random = 6*randfm11();
//     for(int i=1;i<7;i++){
//         if(random<i){
//             return i;
//         }
//     }
// }

int deX(int nombre_de_faces) {
  double random = nombre_de_faces * rand01();
  for (int i = 1; i < nombre_de_faces + 1; i++) {
    if (random < i) {
      return i;
    }
  }
}

// double esperance_exponentielle(double lambda, int N) {
//   double tot;
//   for (int i = 0; i < N; i++) {
//     tot += exponentielle(lambda);
//   }
//   return tot / N;
// }

// float variance_exp(double lambda, int N) {
//   double tot;
//   for (int i = 0; i < N; i++) {
//     double esp_exp = esperance_exponentielle(lambda, N);
//     tot += exponentielle(lambda) - esp_exp * esp_exp;
//   }
//   return tot / N;
//
// }



// test exp

// int main() {
//   int tab[200];
//   float i = 0.f;
//   for (int j = 0; j < 200; j++)
//     tab[j] = 0;
//   for (int k = 0; k < 1000; k++) {
//     float exemple = expo(1);
//     i = 0;
//     while (exemple > i / 10.f)
//       i++;
//     tab[int(i)]++;
//   }
//   for (int j = 0; j < 100; j++)
//     std::cout << tab[j] << std::endl;
//   return 0;
// }

float CLT(int precision) // return a random number from a standard normal
                         // distribution following the Central limit theorem
{
  float somme = 0;
  for (int i = 0; i < precision; i++)
    somme += rand01();
  return somme / float(precision);
  // return (somme / float(n)) * sqrt(12.f * float(n)); // moyenne - esperance
  // (0) divisé par écart type
  //  (écart type de loi uniforme / sqrt(n))
}

glm::vec2
CLT2D(int precision) // returns a random vector ; first it generates a random
                     // number from a standard normal distribution following the
                     // Central limit theorem,used as the y in a (x,y) vec2
                     // rotated with a random (uniform) angle
{
  float randomf = CLT(precision);
  float beta = M_PI * rand01();
  glm::vec2 random(-glm::sin(beta) * randomf, cos(beta) * randomf);
  return random;
}

// test CLT

int main() {
  int tab[200];
  float i = 0.f;
  int nb_cases = 40;
  for (int j = 0; j < nb_cases + 1; j++)
    tab[j] = 0;
  for (int k = 0; k < 1000; k++) {
    float exemple = CLT(50);
    i = 0.f;
    while (exemple > i / float(nb_cases))
      i++;
    tab[int(i)]++;
  }
  for (int j = 0; j < nb_cases + 1; j++)
    std::cout << tab[j] << std::endl;
  return 0;
}

int loi_geometrique_inverse(float p) {// compte le nombre de succès avant un échec
  bool success = true;
  int compteur = 0;
  if (rand01() > p)
    success = false;
  while (success) {
    if (rand01() > p)
      success = false;
    compteur++;
  }
  return compteur;
}
