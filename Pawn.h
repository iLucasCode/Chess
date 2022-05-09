#pragma once

#include "Pion.h"


class Pawn :public Pion
{
	public:

		Pawn(Team team, PieceType piontype, Handler* handler);

		
		void allPosibleMove(Pion* board[8][8], bool doCheck);

protected:
	int m_dx;


};
