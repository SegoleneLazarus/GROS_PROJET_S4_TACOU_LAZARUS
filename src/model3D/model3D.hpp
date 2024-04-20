#pragma once
// #include "Shapes/Common.hpp"
#include "../lib/p6/include/p6/p6.h"
#include "tiny_obj_loader.h"
#include "../src-common/glimac/common.hpp"

// Represents a 3D model
class Modele {
private:
    std::vector<glimac::ShapeVertex> _vertices; // Vertices of the model
    std::string                      _filePath; // Path to the OBJ file

    // Loads model data from file
    bool chargeModele();

public:
    // Constructor that initializes a model with the name of the OBJ file
    explicit Modele(const std::string& name);

    // Getter for vertices that returns a constant reference to avoid copying
    const std::vector<glimac::ShapeVertex>& getVertices() const { return _vertices; }
};