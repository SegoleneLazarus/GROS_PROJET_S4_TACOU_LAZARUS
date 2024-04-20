#include "math.hpp"

void assign_biomes(std::vector<int> &tableau_de_biomes) {
  // on divise le jeu en des cubes imaginaires que l’on va explorer selon la
  // base : de gauche à droite et de bas en haut, puis de bas en haut(ligne,
  // colonne, hauteur) à chacune de ces cases on attribue un biome, la présence
  // d’un objet ou non,et son nom d’objet on va plutot faire : 1 biome =
  // plusieurs cases, 1 case = un objet(ou rien),par concéquent on va d’abord
  // explorer les grandes cases : celles des biomes, et leur attribuer leur
  // biome,on reviendra plus tard pour mettre les objets de manière aléatoire
  // l’exploration est une propagation aléatoire uniforme de proche en proche
  // enpartant d’un coin en bas pour aller vers le coin de l’autre coté de la
  // base, en haut biome est un int allant de 1 à 3, 1 est la foret rouge,2 le
  // royaume champignon et 3 l’océan sauvage
  // nombre de cases de biomes

  for (int i = 0; i < nbcB; i++) // parcours la hauteur, a c'est le
                                 // nombre de cases biome dans le cube
  {
    for (int j = 0; j < nbcB; j++) // parcours les colonnes
    {
      for (int k = 0; k < nbcB; k++) // parcours les lignes
      {
        int compteur = k + j * nbcB + i * nbcB * nbcB;
        if (compteur == 0)
          tableau_de_biomes[0] = deX(3) - 1; // renvoit 0 1 ou 2
        else {
          // le but c’est de sélectionner au hasard une case
          // précédente parmis les 3 directions,

          // on gère les cas de bord avec une sélection d’un
          // triplet ex : (ligne, colonne, hauteur)ou(hauteur,
          // ligne, colonne)etc et on va prendre le premier du
          // triplet et aller chercher s’il existe une case qui
          // lui correspond,sinon on va prendre le deuxième puis
          // le troisième(la première case est déterminée
          // aléatoirement) par ex pour le triplet(hauteur, ligne,
          // colonne) on regarde d’abord la case d’en dessous,s’il
          // n y en a pas on regarde la case juste avant sur la
          // même ligne,s’il n’y en a pas on regarde la case sur
          // la ligne d’avant.
          std::vector<int> selection{1, int(nbcB), int(nbcB * nbcB)};
          std::vector<int> selection_aleatoire{};
          int random = deX(3) - 1;
          selection_aleatoire.push_back(selection[random]);
          selection.erase(selection.begin() + random);
          random = deX(2) - 1;
          selection_aleatoire.push_back(selection[random]);
          selection.erase(selection.begin() + random);
          selection_aleatoire.push_back(selection[0]);

          // on prend la case précédente (si elle existe) et on définie le biome
          // de la case selon son biome via la chaine de markov
          if (selection_aleatoire[0] == 1) {
            if (k != 0)
              tableau_de_biomes.push_back(chaine_de_markov(
                  tableau_de_biomes[compteur - selection_aleatoire[0]]));
            else if (selection_aleatoire[1] == nbcB) {
              if (j != 0)
                tableau_de_biomes.push_back(chaine_de_markov(
                    tableau_de_biomes[compteur - selection_aleatoire[1]]));
              else
                tableau_de_biomes.push_back(chaine_de_markov(
                    tableau_de_biomes[compteur - selection_aleatoire[2]]));
            }
            else if (i != 0) tableau_de_biomes.push_back(chaine_de_markov(
                tableau_de_biomes[compteur - selection_aleatoire[1]]));
            else tableau_de_biomes.push_back(chaine_de_markov(
                tableau_de_biomes[compteur - selection_aleatoire[2]]));
          }
          else if (selection_aleatoire[0] == nbcB) {
            if (j != 0)
              tableau_de_biomes.push_back(chaine_de_markov(
                  tableau_de_biomes[compteur - selection_aleatoire[0]]));
            else if (selection_aleatoire[1] == 1) {
              if (k != 0)
                tableau_de_biomes.push_back(chaine_de_markov(
                    tableau_de_biomes[compteur - selection_aleatoire[1]]));
              else
                tableau_de_biomes.push_back(chaine_de_markov(
                    tableau_de_biomes[compteur - selection_aleatoire[2]]));
            }
            else if (i != 0) tableau_de_biomes.push_back(chaine_de_markov(
                tableau_de_biomes[compteur - selection_aleatoire[1]]));
            else tableau_de_biomes.push_back(chaine_de_markov(
                tableau_de_biomes[compteur - selection_aleatoire[2]]));
          }
          else if (i != 0) tableau_de_biomes.push_back(chaine_de_markov(
              tableau_de_biomes[compteur - selection_aleatoire[0]]));
          else if (selection_aleatoire[1] == 1) {
            if (k != 0)
              tableau_de_biomes.push_back(chaine_de_markov(
                  tableau_de_biomes[compteur - selection_aleatoire[1]]));
            else
              tableau_de_biomes.push_back(chaine_de_markov(
                  tableau_de_biomes[compteur - selection_aleatoire[2]]));
            }
          else if (j != 0) tableau_de_biomes.push_back(chaine_de_markov(
                tableau_de_biomes[compteur - selection_aleatoire[1]]));
          else tableau_de_biomes.push_back(chaine_de_markov(
                tableau_de_biomes[compteur - selection_aleatoire[2]]));
          
        }
      }
    }
  }
}

int chaine_de_markov(int biome_actuel) {
  if (biome_actuel == 1) {
    float nb_rand = loi_uniforme(0, 1);
    if (nb_rand < 0.1)
      return 3;
    else if (nb_rand < 0.8) return 1;
    else return 2;
  }
  else if (biome_actuel == 2) {
    float nb_rand = loi_uniforme(0, 1);
    if (nb_rand < 0.1)
      return 3;
    else if (nb_rand < 0.15) return 1;
    else return 2;
  }
  else {
    float nb_rand = rand01();
    if (nb_rand < 0.8)
      return 3;
    else if (nb_rand < 0.9) return 1;
    else return 2;
  }
}

// float CLT() // return a random number from a standard normal distribution
//             // following the Central limit theorem
// {
//   float somme = 0;
//   int n = 100;
//   for (int i = 0; i < n; i++)
//     somme += rand01();
//   return somme / float(n);
//   // return (somme / float(n)) * sqrt(12.f * float(n)); // moyenne - esperance
//   // (0) divisé par écart type
//   //  (écart type de loi uniforme / sqrt(n))
// }

// int main() {
//   int tab[200];
//   float i = 0.f;
//   int nb_cases = 20;
//   for (int j = 0; j < nb_cases + 1; j++)
//     tab[j] = 0;
//   for (int k = 0; k < 1000; k++) {
//     float exemple = CLT();
//     i = 0.f;
//     while (exemple > i / float(nb_cases))
//       i++;
//     tab[int(i)]++;
//   }
//   for (int j = 0; j < nb_cases + 1; j++)
//     std::cout << tab[j] << std::endl;
//   return 0;
// }