#include "randtest_math.hpp"

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

float loi_uniforme(float borne_bas, float borne_haut) {
  float random = rand01();
  random = random * (borne_haut - borne_bas) + borne_bas;
  return random;
}

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

int assign_DND_alignement(int biome) {
  // on va définir le biome aléatoirement seloin une grille de 9 cases et à
  // l'aide d'une distribution normale centrée sur l'une de ces cases

  // on définie sur quelle case est centrée la distribution, le tableau
  // imaginaire va de 1,1 à -1,-1 comme l'écran opengl
  if (biome == 1)
    glm::vec2 centre(0.0f, -0.5f);                // foret rouge
  elif (biome == 2) glm::vec2 centre(0.5f, 0.0f); // royaume champignon
  else glm::vec2 centre(-0.5f, 0.5f);             // océan sauvage
  glm::vec2 position = centre + CLT2D(50);

  // déterminer l'alignement en fonction de la position sur la grille imaginaire, de haut en gauche à bas en droite, 
  float x = position.x;
  float y = position.y;
  if (y > 0.333) {
    if (x < -0.333)
      return 1;
    elif (x < 0.333) return 2;
    else return 3;
  }
  elif (y > -0.333) {
    if (x < -0.333)
      return 4;
    elif (x < 0.333) return 5;
    else return 6;
  }
  else {
    if (x < -0.333)
      return 7;
    elif (x < 0.333) return 8;
    else return 9;
  }
}

// test CLT

  // int main() {
  //   int tab[200];
  //   float i = 0.f;
  //   int nb_cases = 40;
  //   for (int j = 0; j < nb_cases + 1; j++)
  //     tab[j] = 0;
  //   for (int k = 0; k < 1000; k++) {
  //     float exemple = CLT(50);
  //     i = 0.f;
  //     while (exemple > i / float(nb_cases))
  //       i++;
  //     tab[int(i)]++;
  //   }
  //   for (int j = 0; j < nb_cases + 1; j++)
  //     std::cout << tab[j] << std::endl;
  //   return 0;
  // }