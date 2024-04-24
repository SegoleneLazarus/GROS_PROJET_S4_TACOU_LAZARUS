#include "affichage.hpp"

<<<<<<< HEAD
Rendu::Rendu(p6::Context *ctx, TrackballCamera *camera)
    : _ctx(ctx), camera(camera) {
  _ctx->maximize_window();
  glEnable(GL_DEPTH_TEST);
  glCullFace(GL_BACK);
};

void Rendu::dessinObjet(const glm::mat4 &modelMatrix,
                        const Objet3D &objet) const {
  // glm::vec3 lightPos{0.f, 0.f, 0.f};

  // lightDir = glm::vec4(lightDir, 1.f) * glm::rotate(glm::mat4(1.f), 0.f,
  // {0.f, 1.f, 0.f});
=======
float     Rendu::_uKd             = 0.1f;          // [GUI]
float     Rendu::_uKs             = 1.14f;         // [GUI]
float     Rendu::_uLightIntensity = .012f;         // [GUI]
float     Rendu::_uShininess      = .006f;         // [GUI]
glm::vec3 Rendu::lightDir{17.36f, 15.48f, 7.81f}; // [GUI]


Rendu::Rendu(p6::Context* ctx, TrackballCamera* camera)
    : _ctx(ctx), camera(camera)
{
    _ctx->maximize_window();
    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);
};

void Rendu::dessinObjet(const glm::mat4& modelMatrix, const Objet3D& objet, float transparency) const
{
    glm::vec3 lightPos{0.f, 0.f, 0.f};

    lightDir = glm::vec4(lightDir, 1.f) * glm::rotate(glm::mat4(1.f), 0.f, {0.f, 1.f, 0.f});
>>>>>>> 4b654013182bb0bde9eea387eea204cc0932fc94

  glm::mat4 viewMatrix = camera->getViewMatrix();
  glm::mat4 projMatrix =
      glm::perspective(glm::radians(70.f), _ctx->aspect_ratio(), 0.1f, 1000.f);

  glBindVertexArray(objet.getVAO());
  objet.getShader().shader.use();

<<<<<<< HEAD
  // Handle transparancy
  // if (transparency < 1.f)
  // {
  //     glEnable(GL_BLEND);
  //     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // }
  // else
  // {
  //     glDisable(GL_BLEND);
  // }

  // glUniform3f(objet.getShader().uKd, _uKd, _uKd, _uKd);
  // glUniform3f(objet.getShader().uKs, _uKs, _uKs, _uKs);
  // glUniform3fv(objet.getShader().uLightDir_vs, 1,
  // glm::value_ptr(glm::vec4(_lightDir, 1.f) * glm::inverse(viewMatrix)));
  // glUniform3fv(objet.getShader().uLightPos_vs, 1, glm::value_ptr(viewMatrix *
  // glm::vec4(lightPos, 1.f))); glUniform3f(objet.getShader().uLightIntensity,
  // _uLightIntensity, _uLightIntensity, _uLightIntensity);
  // glUniform1f(objet.getShader().uShininess, _uShininess);
  // glUniform1f(objet.getShader().uTransparency, transparency);
  glUniform1i(objet.getShader().uTexture, 0);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, objet.getTexture().getTextureID());
=======
    // Handle transparancy
    // if (transparency < 1.f)
    // {
    //     glEnable(GL_BLEND);
    //     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // }
    // else
    // {
    //     glDisable(GL_BLEND);
    // };

    glUniform3f(objet.getShader().uKd, _uKd, _uKd, _uKd);
    glUniform3f(objet.getShader().uKs, _uKs, _uKs, _uKs);
    glUniform3fv(objet.getShader().uLightDir_vs, 1, glm::value_ptr(glm::vec4(lightDir, 1.f) * glm::inverse(viewMatrix)));
    glUniform3fv(objet.getShader().uLightPos_vs, 1, glm::value_ptr(viewMatrix * glm::vec4(lightPos, 1.f)));
    glUniform3f(objet.getShader().uLightIntensity, _uLightIntensity, _uLightIntensity, _uLightIntensity);
    glUniform1f(objet.getShader().uShininess, _uShininess);
    // glUniform1f(objet.getShader().uTransparency, transparency);
    glUniform1i(objet.getShader().uTexture, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, objet.getTexture().getTextureID());

    glUniformMatrix4fv(
        objet.getShader().uNormalMatrix, 1, GL_FALSE,
        glm::value_ptr(glm::transpose(glm::inverse(viewMatrix * modelMatrix)))
    );
    glUniformMatrix4fv(objet.getShader().uMVMatrix, 1, GL_FALSE, glm::value_ptr(viewMatrix * modelMatrix));
    glUniformMatrix4fv(objet.getShader().uMVPMatrix, 1, GL_FALSE, glm::value_ptr(projMatrix * viewMatrix * modelMatrix));
>>>>>>> 4b654013182bb0bde9eea387eea204cc0932fc94

  glUniformMatrix4fv(
      objet.getShader().uNormalMatrix, 1, GL_FALSE,
      glm::value_ptr(glm::transpose(glm::inverse(viewMatrix * modelMatrix))));
  glUniformMatrix4fv(objet.getShader().uMVMatrix, 1, GL_FALSE,
                     glm::value_ptr(viewMatrix * modelMatrix));
  glUniformMatrix4fv(objet.getShader().uMVPMatrix, 1, GL_FALSE,
                     glm::value_ptr(projMatrix * viewMatrix * modelMatrix));
};

void Rendu::clearAll() {
  glBindVertexArray(0);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, 0);
  _ctx->background({});
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}