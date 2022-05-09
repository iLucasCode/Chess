#pragma once

#include "Pion.h"



class Rook:public Pion
{
public:

	Rook(Team team, PieceType piontype, Handler* handler);

	void allPosibleMove(Pion* board[8][8], bool doCheck);
};

