#pragma once
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