#pragma once

#include "Chessboard.h"
#include <SFML/Graphics.hpp>
#include "Handler.h"
#include <vector>


class King;

class Pion
{
public:
    sf::Vector2f position;
    sf::Texture piontexture;
    sf::Sprite pionsprite;
    
    
    enum Team { BLACK, WHITE, NONE };

    enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, KING, QUEEN, EMPTY };

    enum MoveType{ NORMAL, ATTACK, PROMOTION};

    

    Pion(Team team, PieceType piecetype, Handler* handler);

    Pion(const Pion& pion);

    ~Pion();

    void setNewPosition(std::pair<int, int> newPos);

    std::pair<int, int> getPos();

    virtual void allPosibleMove(Pion* board[8][8], bool doCheck) = 0;

    Pion::PieceType getTyp();

    Pion::Team getTeam();

    struct m_PossibleMove
    {
        int xCord, yCord;
        Pion::MoveType typeMove;
    };

    std::vector<Pion::m_PossibleMove> pushMove(std::vector<m_PossibleMove>listMove, int yCord, int xCord, Pion::MoveType typeMove, King* king, Pion* board[8][8], bool checkCheck);

    std::vector<m_PossibleMove> getPossibleMove();

    

protected:

    Team m_team;

    PieceType m_piontype;

    Handler* m_handler;

    std::pair<int, int> m_pos;

    std::vector<m_PossibleMove> m_possible;

    sf::RectangleShape rectangle;

    King* getOwnKing(Pion* board[8][8]);

};


