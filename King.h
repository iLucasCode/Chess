#pragma once

#include "Pion.h"


class King :public Pion
{

public:
	King(Team team, PieceType piontype, Handler* handler);

	void allPosibleMove(Pion* board[8][8], bool doCheck);

	void check(Pion* board[8][8], int x, int y);

	bool getCheck();

	bool m_check = false;
};