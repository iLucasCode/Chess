

#include "Queen.h"


Queen::Queen(Team team, PieceType piontype, Handler* handler):Pion(team, piontype,handler)
{
	if (team == BLACK)
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/b_queen_png_128px.png");

	}
	else
	{
		piontexture.loadFromFile("C:/c++/Chess/assets/w_queen_png_128px.png");
	}
	pionsprite.setTexture(piontexture);
	pionsprite.setScale(0.5f, 0.5f);

	m_team = team;
	m_piontype = piontype;
	m_handler = handler;

}

void Queen::allPosibleMove(Pion* board[8][8], bool doCheck)
{
	std::vector<m_PossibleMove> possible;
	
	int dx = 1;
	int dy = 1;

	while (m_pos.second + dx <= 7)
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

		dx++;
	}

	while (m_pos.first + dy <= 7) {

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
			if (board[m_pos.second + dx][m_pos.first]->getTeam() != m_team) {
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

	int dx_copy;
	int dy_copy;

	for (int dx = -1; dx <= 1; dx += 2)
	{

		for (int dy = -1; dy <= 1; dy += 2)
		{

			dx_copy = dx;
			dy_copy = dy;

			while (board[m_pos.second + dx_copy][m_pos.first + dy_copy] == nullptr
				&& (m_pos.first + dy_copy >= 0 && m_pos.first + dy_copy <= 7) && (m_pos.second + dx_copy >= 0 && m_pos.second + dx_copy <= 7))
			{

				possible = pushMove(possible, m_pos.first + dy_copy, m_pos.second + dx_copy, MoveType::NORMAL, getOwnKing(board), board, doCheck);

				if (dx_copy > 0)
				{
					dx_copy += 1;
				}
				else
				{
					dx_copy -= 1;
				}

				if (dy_copy > 0)
				{
					dy_copy += 1;
				}
				else
				{
					dy_copy -= 1;
				}
			}

			if (board[m_pos.second + dx_copy][m_pos.first + dy_copy] != nullptr
				&& (m_pos.first + dy_copy >= 0 && m_pos.first + dy_copy <= 7) && (m_pos.second + dx_copy >= 0 && m_pos.second + dx_copy <= 7))
			{
				if (board[m_pos.second + dx_copy][m_pos.first + dy_copy]->getTeam() != m_team)
				{
					possible = pushMove(possible, m_pos.first + dy_copy, m_pos.second + dx_copy, MoveType::NORMAL, getOwnKing(board), board, doCheck);
				}
			}
		}
	}

	
	m_possible = possible;
	
}
