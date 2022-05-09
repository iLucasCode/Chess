#include "Knight.h"



Knight::Knight(Team team, PieceType piontype, Handler* handler) :Pion(team, piontype, handler)
{
	if (team == BLACK)
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/b_knight_png_128px.png");
	}
	else
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/w_knight_png_128px.png");
		pionsprite.setTexture(piontexture);
		pionsprite.setScale(0.5f, 0.5f);
	}
	pionsprite.setTexture(piontexture);
	pionsprite.setScale(0.5f, 0.5f);

	m_team = team;
	m_piontype = piontype;
	m_handler = handler;
}

void Knight::allPosibleMove(Pion* board[8][8], bool doCheck)
{
	struct MovePair
	{
		int x, y;
	};

	std::vector<MovePair> possibleDirect =
	{
		MovePair{-1, -2},
		MovePair{-1, 2},
		MovePair{ 1, -2},
		MovePair{ 1, 2},
		MovePair{-2, -1},
		MovePair{-2, 1},
		MovePair{ 2, -1},
		MovePair{ 2, 1},
	};

	std::vector<m_PossibleMove> possible;

	for (auto& i : possibleDirect)
	{

		if ((m_pos.first + i.y >= 0 && m_pos.first + i.y <= 7) && (m_pos.second + i.x >= 0 && m_pos.second + i.x <= 7))
		{
			if (board[m_pos.second + i.x][m_pos.first + i.y] == nullptr)
			{
				possible = pushMove(possible, m_pos.first + i.y, m_pos.second + i.x, MoveType::NORMAL, getOwnKing(board), board, doCheck);
			}

			if (board[m_pos.second + i.x][m_pos.first + i.y] != nullptr)
			{
				if (board[m_pos.second + i.x][m_pos.first + i.y]->getTeam() != m_team)
				{
					possible = pushMove(possible, m_pos.first + i.y, m_pos.second + i.x, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				}
			}
		}
	}
	
	

	m_possible = possible;

}
