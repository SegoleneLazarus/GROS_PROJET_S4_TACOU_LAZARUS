#include "Objet3D.hpp"

Objet3D::Objet3D(const std::string& nom, const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
    : modele(nom), texture(nom), shader(vertexShaderPath, fragmentShaderPath)
{
    defineVBO();
    defineVAO();
};

// Sets up the vertex buffer object (VBO)
void Objet3D::defineVBO()
{
    glGenBuffers(1, &vbo);              // Generate one buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // Bind the buffer as an array buffer

    // Load vertex data into buffer
    glBufferData(GL_ARRAY_BUFFER, modele.getVertices().size() * sizeof(glimac::ShapeVertex), modele.getVertices().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the buffer
}

void Objet3D::defineVAO()
{
    glGenVertexArrays(1, &vao); // Generate one vertex array
    glBindVertexArray(vao);     // Bind the vertex array

    // Define attribute pointers
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

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the buffer
    glBindVertexArray(0);             // Unbind the vertex array
}

// Cleans up OpenGL objects
void Objet3D::clear()
{
    glDeleteBuffers(1, &vbo);      // Delete the vertex buffer
    glDeleteVertexArrays(1, &vao); // Delete the vertex array
}