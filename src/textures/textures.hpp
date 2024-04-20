#pragma once
#include "p6/p6.h"
#include "stb_image/stb_image.h"

class Texture {
private:
    GLuint      _textureID;    // id de la texture
    std::string _filePath;     // chemin
    void        loadTexture(); // chargement

public:
    // initialisation
    explicit Texture(const std::string& name);

    // retourne la texture
    GLuint getTextureID() const { return _textureID; }
};