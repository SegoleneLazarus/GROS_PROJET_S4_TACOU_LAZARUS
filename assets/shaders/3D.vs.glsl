#version 330 core

layout (location = 0) in vec3 aVertexPosition; // Position du sommet
layout (location = 1) in vec3 aVertexNormal; // Normale du sommet
layout (location = 2) in vec2 aVertexTexCoords; // Coordonnées de texture du sommet

uniform mat4 uVMatrix;
uniform mat4 uMMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uMVPMatrix;
uniform mat4 uNormalMatrix;

out vec3 vPosition_vs; // Position du sommet transformée dans l'espace View (vs)
out vec3 vNormal_vs; // Normale du sommet transformée dans l'espace View (vs)
out vec2 vTexCoords; // Coordonnées de texture du sommet
out vec3 vViewMatrix;

void main() {
    vec4 vertexPosition = vec4(aVertexPosition, 1.);
    vec4 vertexNormal = vec4(aVertexNormal, 0.);

    vPosition_vs = vec3(uVMatrix * uMMatrix * vertexPosition);
    vNormal_vs = vec3(uNormalMatrix * vertexNormal);
    vTexCoords = aVertexTexCoords;
    vViewMatrix = vec3(uVMatrix);

    gl_Position = uMVPMatrix * vertexPosition;
}