#ifndef GAME_H
#define GAME_H

#include "shader.hpp"
#include "graphics.hpp"
#include "texture.hpp"
#include "mino.hpp"
#include "text.hpp"

#include <glm/glm.hpp>


class Game {
    public:
        Game();
        void init();
        void run();
        void cleanup();
    protected:
        virtual void update();
        virtual void draw();
    private:
        void newGame();
        void choosePiece();
        void passGridBuffer();

        bool running;
        Texture t;
        ShaderProgram p;
        ShaderProgram text;
        Text scoreText;
        Text lossesText;
        Buffer inds;
        Buffer uvs;
        Buffer vertices;
        Buffer positions;
        Buffer gridBuffer;
        VAO vao;

        bool prevLeft, prevRight, prevUp, prevDown, prevSpace, prevShift, prevZ;
        bool moved, held;

        const static int gridWidth = 10, gridHeight = 20;

        std::vector<int> grid;

        const static int defTicks = 60;
        int ticks;
        int tick;

        int posx;
        int posy;
        int score;
        int losses;

        Mino piece;
        Mino hold;
        Mino next;

        static const glm::vec3 pieceColors[Mino::numPieces + 2];
};

#endif