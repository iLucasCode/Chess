#include<iostream>

#include "Pawn.h"


Pawn::Pawn(Team team, PieceType piontype, Handler* handler) :Pion(team, piontype,handler)
{
	if (team == BLACK)
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/b_pawn_png_128px.png");
		m_dx = 1;
	}
	else
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/w_pawn_png_128px.png");
		m_dx = -1;
	}

	pionsprite.setTexture(piontexture);
	pionsprite.setScale(0.5f, 0.5f);

	m_team = team;
	m_piontype = piontype;
	m_handler = handler;

}

void Pawn::allPosibleMove(Pion* board[8][8], bool doCheck) {

	std::vector<m_PossibleMove> possible;


		if (board[m_pos.second + m_dx][m_pos.first] == nullptr)
		{
			possible = pushMove(possible, m_pos.first, m_pos.second + m_dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);
			
		}
		
		if(m_pos.second + m_dx == 0 || m_pos.second + m_dx == 7 && board[m_pos.second + m_dx][m_pos.first] == nullptr)
		{
			possible = pushMove(possible, m_pos.first, m_pos.second + m_dx, MoveType::PROMOTION, getOwnKing(board), board, doCheck);
		}
		
		if ((m_pos.second == 6 && m_dx == -1) || (m_pos.second == 1 && m_dx == 1))
		{
			if (board[m_pos.second + (2 * m_dx)][m_pos.first] == nullptr && board[m_pos.second + m_dx][m_pos.first] == nullptr)
			{
				possible = pushMove(possible, m_pos.first, m_pos.second + (2 * m_dx), MoveType::NORMAL, getOwnKing(board), board, doCheck);
			}
			
		}

		if (m_pos.first - 1 >= 0)
		{
			if (board[m_pos.second + m_dx][m_pos.first - 1] != nullptr)
			{

				if (m_pos.second + m_dx == 0 || m_pos.second + m_dx == 7)
				{
					if (board[m_pos.second + m_dx][m_pos.first - 1]->getTeam() != m_team)
						possible = pushMove(possible, m_pos.first - 1, m_pos.second + m_dx, MoveType::PROMOTION, getOwnKing(board), board, doCheck);
				}
				else
				{
					if (board[m_pos.second + m_dx][m_pos.first - 1]->getTeam() != m_team)
						possible = pushMove(possible, m_pos.first - 1, m_pos.second + m_dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				}
			}

		}
		if (m_pos.first + 1 <= 7)
		{
			if (board[m_pos.second + m_dx][m_pos.first + 1] != nullptr)
			{
				if (m_pos.second + m_dx == 0 || m_pos.second + m_dx == 7)
				{
					if (board[m_pos.second + m_dx][m_pos.first + 1]->getTeam() != m_team)
						possible = pushMove(possible, m_pos.first + 1, m_pos.second + m_dx, MoveType::PROMOTION, getOwnKing(board), board, doCheck);
				}
				else
				{
					if (board[m_pos.second + m_dx][m_pos.first + 1]->getTeam() != m_team)
						possible = pushMove(possible, m_pos.first + 1, m_pos.second + m_dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				}
			}

		}


		
		m_possible = possible;
	
		

}