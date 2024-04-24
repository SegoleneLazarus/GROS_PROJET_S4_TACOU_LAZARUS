#include "model3D.hpp"

Modele::Modele(const std::string& nomDuFichier) 
    : chemin("assets/modeles/" + nomDuFichier + ".obj")
{
    if (!chargeModele()) // Vérifie le chargement du modèle 3D
    {
        std::cerr << "chargerModèle() : Impossible de charger le modèle [" << nomDuFichier << "]." << std::endl;
    }
}

// Fonction pour charger le modèle
bool Modele::chargeModele()
{
    tinyobj::attrib_t                attributs;
    std::vector<tinyobj::shape_t>    formes;
    std::vector<tinyobj::material_t> materiaux;
    std::string                      erreur;
    std::string                      avertissement;

    // Charge le fichier objet
    const bool chargementReussi = tinyobj::LoadObj(&attributs, &formes, &materiaux, &avertissement, &erreur, chemin.c_str());
    if (!chargementReussi)
    {
        std::cerr << "LoadObj() a échoué : " << erreur << std::endl;
        return chargementReussi;
    }

    // Parcourt les formes du modèle
    for (const auto& forme : formes)
    {
        for (const auto& index : forme.mesh.indices)
        {
            glm::vec3 position(
                attributs.vertices[3 * index.vertex_index + 0],
                attributs.vertices[3 * index.vertex_index + 1],
                attributs.vertices[3 * index.vertex_index + 2]
            );

            glm::vec3 normal(
                attributs.normals[3 * index.normal_index + 0],
                attributs.normals[3 * index.normal_index + 1],
                attributs.normals[3 * index.normal_index + 2]
            );

            glm::vec2 texCoord(
                attributs.texcoords[2 * index.texcoord_index + 0],
                attributs.texcoords[2 * index.texcoord_index + 1]
            );

            vertices.emplace_back(position, normal, texCoord);
        }
    }

    return chargementReussi;
}