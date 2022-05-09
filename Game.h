#pragma once

#include "Chessboard.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pion.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Handler.h"




class Game 
{
public:
	float size = 66.f;

	Game(Handler* handler);

	void render(Handler* handler);

	Pion* getBoardPos(int row, int col);

	void movePion(Pion* clickedpion,int xStart, int yStart, int xEnd, int yEnd, Pion::MoveType movetyp, Handler* handler);

	void renderMove(Handler* handler, Pion* clickedpion);
	
	Pion* m_board[8][8];

	bool isValidMove(Pion* clickerpion, int x, int y);

	void gameState();

	Pion::Team m_turn;

	void calcAllMoves();

	void normal(int xStart, int yStart, int xEnd, int yEnd);

	void promotion(int xStart, int yStart, int xEnd, int yEnd, Handler* handler);

	
protected:
	

	Handler* m_handler;

	King* blackking;
	King* whiteking;
	
};


