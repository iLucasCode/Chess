#pragma once

#include "Pion.h"


class Queen :public Pion
{
public:
	Queen(Team team, PieceType piontype, Handler* handler);

	void allPosibleMove(Pion* board[8][8], bool doCheck);
};

