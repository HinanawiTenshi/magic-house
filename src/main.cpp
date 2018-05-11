#include "lib/glad.h"
#include "Game.hpp"

#include <GLFW/glfw3.h>

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;

int main() {
    Game game(WIDTH, HEIGHT);
    game.init();

    // Main Loop
    while (!glfwWindowShouldClose(game.getWindow())) {
        glfwPollEvents();

        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);

        game.processInput();
        game.render();

        glfwSwapBuffers(game.getWindow());
    }

    return 0;
}