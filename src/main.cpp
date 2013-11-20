#include <stdexcept>
#include <iostream>

#include "tetris.hpp"


int main(int argc, char **argv) {
  try {
    Tetris game;
    game.run();
    return 0;
  }
  catch(const std::exception &exc) {
    std::cerr << exc.what() << std::endl;
  }
}