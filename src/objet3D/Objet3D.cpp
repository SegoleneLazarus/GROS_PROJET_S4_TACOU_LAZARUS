#include "Objet3D.hpp"

Objet3D::Objet3D(const std::string& nom, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
    : modele(nom), texture(nom), shader(vertexShaderPath, fragmentShaderPath)
{
    defineVBO();
    defineVAO();
};

void Objet3D::defineVBO()
{
    glGenBuffers(1, &vbo);            
    glBindBuffer(GL_ARRAY_BUFFER, vbo); 

    glBufferData(GL_ARRAY_BUFFER, modele.getVertices().size() * sizeof(glimac::ShapeVertex), modele.getVertices().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Objet3D::defineVAO()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);   

    static constexpr GLuint vertex_attr_position  = 0;
    static constexpr GLuint vertex_attr_normal    = 1;
    static constexpr GLuint vertex_attr_texcoords = 2;
    glEnableVertexAttribArray(vertex_attr_position);
    glEnableVertexAttribArray(vertex_attr_normal);
    glEnableVertexAttribArray(vertex_attr_texcoords);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(vertex_attr_position, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, position));
    glVertexAttribPointer(vertex_attr_normal, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, normal));
    glVertexAttribPointer(vertex_attr_texcoords, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, texCoords));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Objet3D::clear()
{
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

// NE SERT A RIEN
// class GameObject {
// protected: // Changed from private to protected for inheritance access
//     Objet3D  objet3D;
//     Transform transform;

// public:
//     GameObject(){};

//     Object3D&  getObject3D() { return objet3D; };
//     Transform& getTransform() { return transform; };
// };