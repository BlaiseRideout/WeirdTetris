#ifndef TETRIS_H
#define TETRIS_H

#include "game.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "mino.hpp"
#include "text.hpp"


class Tetris : public Game {
	public:
		Tetris();
	protected:
		virtual void update(double time);
	private:
		void newGame();
        void choosePiece();
        void passGridBuffer();

        Texture t;
        Texture font;
        ShaderProgram p;
        ShaderProgram text;
        Text scoreText;
        Text lossesText;
        Buffer inds;
        Buffer uvs;
        Buffer vertices;
        Buffer positions;
        Buffer gridBuffer;

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