#include "game.hpp"


Game::Game(std::string title, int majorVersion, int minorVersion) : window(800, 600, false, title, majorVersion, minorVersion) {
  this->running = true;
}

Game::Game(std::string title) : Game(title, 3, 3) {
}

Game::Game() : Game("Divamia") {
}

Game::~Game() {
  glfwTerminate();
}

void Game::run() {
  while(this->running && !this->window.shouldClose()) {
    double curTime = glfwGetTime();
    double timeDelta = curTime - this->time;
    this->time = curTime;
    update(timeDelta);
    this->window.swapBuffers();
    glfwPollEvents();
  }
}
