#pragma once

#include "Pion.h"



class Knight :public Pion
{
public:
	Knight(Team team, PieceType piontype, Handler* handler);

	void allPosibleMove(Pion* board[8][8], bool doCheck);
};

