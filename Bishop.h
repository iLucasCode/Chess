#pragma once


#include "Pion.h"


class Bishop :public Pion
{
	public:
		Bishop(Team team, PieceType piontype, Handler* handler);

		void allPosibleMove(Pion* board[8][8], bool doCheck);
};
