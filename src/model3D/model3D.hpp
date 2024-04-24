#pragma once
// #include "Shapes/Common.hpp"
// #include "Shapes/Common.hpp"
#include "../lib/p6/include/p6/p6.h"
#include "tiny_obj_loader.h"
#include "../src-common/glimac/common.hpp"

class Modele {
private:
    std::vector<glimac::ShapeVertex> vertices;
    std::string                      chemin;

    bool chargeModele();

public:
    explicit Modele(const std::string& name);
    
    const std::vector<glimac::ShapeVertex>& getVertices() const { return vertices; }
};

// #pragma once
// #include "../src-common/glimac/common.hpp"
// #include "p6/p6.h"
// #include "tiny_obj_loader.h"

// // Represents a 3D model
// class Modele {
// private:
//     std::vector<glimac::ShapeVertex> vertices; // Vertices of the model
//     std::string                      _filePath; // Path to the OBJ file

//     // Loads model data from file
//     bool loadModel();

// public:
//     // Constructor that initializes a model with the name of the OBJ file
//     explicit Modele(const std::string& name);

//     // Getter for vertices that returns a constant reference to avoid copying
//     const std::vector<glimac::ShapeVertex>& getVertices() const { return vertices; }
// };


// #pragma once

// #include <iostream>
// #include <string>
// #include <vector>
// #include "tiny_obj_loader.h"
// #include <glm/glm.hpp>

// class Modele {
// private:
//     struct ShapeVertex {
//         glm::vec3 position;
//         glm::vec3 normal;
//         glm::vec2 texCoords;
//     };

//     std::vector<ShapeVertex> _vertices;
//     std::string _filePath;

//     bool loadModel();

// public:
//     explicit Modele(const std::string& name);

//     const std::vector<ShapeVertex>& getVertices() const { return _vertices; }
// };
