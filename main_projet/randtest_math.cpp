#include "randtest_math.hpp"

float randfm11() {
  srand(time(NULL));
  constexpr int N = 100;

  float res = 0;
  for (int i = 1; i < N; i++) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    float random_number = dist(mt);
    res += random_number / pow(2, i);
  }

  return res;
}

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
  double random = randfm11();
  if (p > random) {
    return 0;
  } else {
    return 1;
  }
}

int de6_eq() {
  double random = 6 * randfm11();
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
  double random = nombre_de_faces * randfm11();
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
  float random = (randfm11() + 1) / 2;
  random = random * (borne_haut - borne_bas) + borne_bas;
  return random;
}

// int main() {
//   for (int i = 0; i < 10; i++) {
//     std::cout << randfm11() << std::endl;
//     std::cout << loi_uniforme(0, 1) << std::endl;
//     std::cout << expo(1) << std::endl;
//   }
//   return 0;
// }