#ifndef MINO_H
#define MINO_H


class Mino {
	public:
		Mino();
		Mino(int piece);
		Mino(Mino const &m);
		Mino &operator=(Mino const &m);
		const int *getArray();
		void rotClock();
		void rotCounterClock();
		int startOffset();

		const static int numPieces = 16;
	protected:
		int type;
		int rot;

		static const int minos[numPieces][4][16];
		static const int stoffset[numPieces];

};

#endif