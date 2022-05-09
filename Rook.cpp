#include<iostream>

#include "Rook.h"


Rook::Rook(Team team, PieceType piontype, Handler* handler):Pion(team, piontype,handler)
{
	if (team == BLACK)
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/b_rook_png_128px.png");

	}
	else
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/w_rook_png_128px.png");
	}
	pionsprite.setTexture(piontexture);
	pionsprite.setScale(0.5f, 0.5f);

	m_team = team;
	m_piontype = piontype;
	m_handler = handler;
}

void Rook::allPosibleMove(Pion* board[8][8], bool doCheck)
{
	std::vector<m_PossibleMove> possible;

	int dx = 1;
	int dy = 1;

	while (m_pos.second + dx <= 7)
	{
		if(board[m_pos.second + dx][m_pos.first] == nullptr)
			possible = pushMove(possible, m_pos.first, m_pos.second + dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);

		if (board[m_pos.second + dx][m_pos.first] != nullptr)
		{
			if (board[m_pos.second + dx][m_pos.first]->getTeam() != m_team)
			{
				possible = pushMove(possible, m_pos.first, m_pos.second + dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				break;
			}
			else if (board[m_pos.second + dx][m_pos.first]->getTeam() == m_team)
				break;
		}

		dx++;
	}

	while (m_pos.first + dy <= 7){

		if(board[m_pos.second][m_pos.first + dy] == nullptr)
			possible = pushMove(possible, m_pos.first + dy, m_pos.second, MoveType::NORMAL, getOwnKing(board), board, doCheck);

		if (board[m_pos.second][m_pos.first + dy] != nullptr) {
			if (board[m_pos.second][m_pos.first + dy]->getTeam() != m_team)
			{
				possible = pushMove(possible, m_pos.first + dy, m_pos.second, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				break;
			}
			else if (board[m_pos.second][m_pos.first + dy]->getTeam() == m_team)
				break;
		}
		
		dy++;
	}

	dx = -1;
	dy = -1;

	while (m_pos.second + dx >= 0)
	{
		if (board[m_pos.second + dx][m_pos.first] == nullptr)
			possible = pushMove(possible, m_pos.first, m_pos.second + dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);

		if (board[m_pos.second + dx][m_pos.first] != nullptr)
		{
			if (board[m_pos.second + dx][m_pos.first]->getTeam() != m_team) 
			{
				possible = pushMove(possible, m_pos.first, m_pos.second + dx, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				break;
			}
			else if (board[m_pos.second + dx][m_pos.first]->getTeam() == m_team)
				break;
		}

		dx--;
	}

	while (m_pos.first + dy >= 0) {

		if (board[m_pos.second][m_pos.first + dy] == nullptr)
			possible = pushMove(possible, m_pos.first + dy, m_pos.second, MoveType::NORMAL, getOwnKing(board), board, doCheck);

		if (board[m_pos.second][m_pos.first + dy] != nullptr) {
			if (board[m_pos.second][m_pos.first + dy]->getTeam() != m_team)
			{
				possible = pushMove(possible, m_pos.first + dy, m_pos.second, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				break;
			}
			else if (board[m_pos.second][m_pos.first + dy]->getTeam() == m_team)
				break;
		}

		dy--;
	}

	
	
	m_possible = possible;
	

}

