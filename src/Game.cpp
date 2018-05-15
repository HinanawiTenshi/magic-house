#include "lib/glad.h"
#include "Game.hpp"

#include <cstdio>
#include <GLFW/glfw3.h>

Game::Game(GLuint width, GLuint height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    window = glfwCreateWindow(width, height, TITLE, NULL, NULL);
    if (window == NULL) {
        printf("[ERROR]glfwCreateWindow failed\n");
        return;
    }
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    this->width = width;
    this->height = height;
    resManager = ResourceManager::GetInstance();
}

Game::~Game() {
    glfwTerminate();
}

void Game::init() {
    Shader *spriteShader = resManager->loadShader("res/shaders/sprite.vs", 
        "res/shaders/sprite.fs", NULL, "sprite");
    if (spriteShader == NULL) {
        printf("[ERROR]In Game::init\n");
        return;
    }
    resManager->loadRenderer(SPRITE_CUBE, spriteShader, "cube");
    resManager->loadCamera(glm::radians(45.f), (float)width / height, .1f, 100.f,
        0.f, 0.f, 5.f, 0.f, 0.f, -1.f, 0.f, 1.f, 0.f, "main");
}

void Game::processInput() {
    Camera *camera = resManager->getCamera("main");
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->moveForward(.1f);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->moveBack(.1f);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera->moveLeft(.1f);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera->moveRight(.1f);
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        camera->rotateLeft(.05f);
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        camera->rotateRight(.05f);
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
        camera->rotateUp(.05f);
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        camera->rotateDown(.05f);
}

void Game::render() {
    Camera *camera = resManager->getCamera("main");
    SpriteRenderer *renderer = resManager->getRenderer("cube");
    renderer->drawSprite(camera->getProjection(), camera->getView());
}

GLFWwindow *Game::getWindow() const {
    return window;
}