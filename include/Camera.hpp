#pragma once

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Camera {
private:
    GLfloat pFov, pAspect, pNear, pFar;
    GLfloat pitch, yaw;
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 right;
    glm::vec3 up;

public:
    Camera(GLfloat pFov, GLfloat pAspect, GLfloat pNear, GLfloat pFar,
        GLfloat posX, GLfloat posY, GLfloat posZ,
        GLfloat frontX, GLfloat frontY, GLfloat frontZ,
        GLfloat upX, GLfloat upY, GLfloat upZ);

    void moveForward(const GLfloat &distance);
    void moveBack(const GLfloat &distance);
    void moveRight(const GLfloat &distance);
    void moveLeft(const GLfloat &distance);

    void rotateLeft(const GLfloat &quantity);
    void rotateRight(const GLfloat &quantity);
    void rotateUp(const GLfloat &quantity);
    void rotateDown(const GLfloat &quantity);

    void rotate(const GLfloat pitch, const GLfloat yaw);

    glm::vec3 getPos() const;
    glm::mat4 getView() const;
    glm::mat4 getProjection() const;
};