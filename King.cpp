

#include <iostream>
#include "King.h"


King::King(Team team, PieceType piontype, Handler* handler):Pion(team, piontype, handler)
{
	if (team == BLACK)
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/b_king_png_128px.png");
	}
	else
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/w_king_png_128px.png");
	}

	pionsprite.setTexture(piontexture);
	pionsprite.setScale(0.5f, 0.5f);

	m_team = team;
	m_piontype = piontype;
	m_handler = handler;

}

void King::allPosibleMove(Pion* board[8][8], bool doCheck)
{
	std::vector<m_PossibleMove> possible;

	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (m_pos.second + dx >= 0 && m_pos.second + dx <= 7 && m_pos.first + dy >= 0 && m_pos.first + dy <= 7)
			{
				if (board[m_pos.second + dx][m_pos.first + dy] != nullptr)
				{
					if (board[m_pos.second + dx][m_pos.first + dy]->getTeam() != m_team)
					{
						possible = pushMove(possible, m_pos.first + dy, m_pos.second + dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);
					}
				}
				else
				{
					possible = pushMove(possible, m_pos.first + dy, m_pos.second + dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				}
			}
		}
	}

	m_possible = possible;

}


void King::check(Pion* board[8][8], int x, int y) 
{
	bool check = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != nullptr)
			{
				if (board[i][j]->getTeam() != m_team)
				{
					if (board[i][j]->getTyp() == KING)
					{
						if (abs(board[i][j]->getPos().second - x) <= 1 && abs(board[i][j]->getPos().first - y) <= 1)
						{
							check = true;
						}

					}
					else if (board[i][j]->getTyp() == PAWN)
					{
						int dx_pawn;
						if (board[i][j]->getTeam() == WHITE)
						{
							dx_pawn = -1;
						}
						else
						{
							dx_pawn = 1;
						}

						if ((y == board[i][j]->getPos().first + 1 || y == board[i][j]->getPos().first - 1) && x == board[i][j]->getPos().second + dx_pawn)
						{
							check = true;
						}
					}
					else
					{
						board[i][j]->allPosibleMove(board, false);
						std::vector<m_PossibleMove> notPossible = board[i][j]->getPossibleMove();
						for (auto& value : notPossible)
						{
							
							if (value.xCord == x && value.yCord == y)
							{
								check = true;
							}
						}
					}
				}
			}
		}
	}

	m_check = check;
}

bool King::getCheck(){ return m_check; };