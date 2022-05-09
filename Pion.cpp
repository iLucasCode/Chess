
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pion.h"
#include "King.h"







Pion::Pion(Team team, PieceType piontype, Handler* handler) : m_team(team), m_piontype(piontype), m_handler(handler) {};

Pion::Pion(const Pion& pion) : m_team(pion.m_team), m_piontype(pion.m_piontype), m_handler(pion.m_handler) {};

Pion::~Pion() {};

void Pion::setNewPosition(std::pair<int, int> newPos) {m_pos = newPos; }
    
std::pair<int, int> Pion::getPos() {

    return  m_pos;
}





Pion::PieceType Pion::getTyp() {
    return m_piontype;
}

Pion::Team Pion::getTeam() {
    return m_team;
}


std::vector<Pion::m_PossibleMove> Pion::pushMove(std::vector<m_PossibleMove> listMove, int yCord, int xCord, Pion::MoveType typeMove, King* king, Pion* board[8][8],bool doCheck) {

	m_PossibleMove move{ xCord, yCord, typeMove };


	if (!doCheck)
	{
		 listMove.push_back(move);
	}
	else
	{
		
		king->check(board, king->getPos().second, king->getPos().first);
		Pion* blocker = &(*board[move.xCord][move.yCord]);

		bool enemyPlace = false;

		if (board[move.xCord][move.yCord] != nullptr)
		{
			enemyPlace = true;
			board[move.xCord][move.yCord] = nullptr;
		
		}

		std::swap(board[move.xCord][move.yCord],board[m_pos.second][m_pos.first]);
		if (m_piontype == KING)
		{
			king->check(board, move.xCord, move.yCord);
		}
		else
		{
			king->check(board, king->getPos().second, king->getPos().first);
		}
		std::swap(board[move.xCord][move.yCord], board[m_pos.second][m_pos.first]);

		if (enemyPlace)
		{
			board[move.xCord][move.yCord] = &(*blocker);
		}
		if (!king->getCheck())
		{
			listMove.push_back(move);
		}
		king->check(board, king->getPos().second, king->getPos().first);
	}

    return listMove;
}

std::vector<Pion::m_PossibleMove> Pion::getPossibleMove() { return m_possible; }


King* Pion::getOwnKing(Pion* board[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr)
			{
				if (board[i][j]->getTeam() == m_team && board[i][j]->getTyp() == Pion::KING)
				{
					King* king = static_cast<King*>(board[i][j]);
					return king;
				}
			}
		}
	}
	return nullptr;
}
