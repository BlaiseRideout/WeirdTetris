#ifndef GAME_H
#define GAME_H

#include "window.hpp"

#include <glm/glm.hpp>


class Game {
    public:
        Game();
        Game(std::string title);
        Game(std::string title, int majorVersion, int minorVersion);
        virtual ~Game();
        void run();
    protected:
        virtual void update(double time) = 0;

        bool running;
        Window window;
        double time;
};

#endif