#include "Game.h"





Game::Game(Handler* handler) {



     for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            
            if (row == 0 && (col == 0 || col == 7)) {
                m_board[row][col] = new Rook(Pion::BLACK, Pion::ROOK, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
                
            }
            else if (row == 7 && (col == 0 || col == 7)) {
                m_board[row][col] = new Rook(Pion::WHITE, Pion::ROOK, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));

            }
            else if (row == 0 && (col == 1 || col == 6)) {
                m_board[row][col] = new Knight(Pion::BLACK, Pion::KNIGHT, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
                
            }
            else if (row == 7 && (col == 1 || col == 6)) {
                m_board[row][col] = new Knight(Pion::WHITE, Pion::KNIGHT, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
              
            }
            else if (row == 0 && (col == 2 || col == 5)) {
                m_board[row][col] = new Bishop(Pion::BLACK, Pion::BISHOP, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
               
            }
            else if (row == 7 && (col == 2 || col == 5)) {
                m_board[row][col] = new Bishop(Pion::WHITE, Pion::BISHOP, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
            
            }
            else if (row == 0 && col == 3) {
                m_board[row][col] = new Queen(Pion::BLACK, Pion::QUEEN, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
              
            }
            else if (row == 7 && col == 4) {
                m_board[row][col] = new Queen(Pion::WHITE, Pion::QUEEN, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
                    
            }
            else if (row == 0 && col == 4) {
                m_board[row][col] = new King(Pion::BLACK, Pion::KING, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
                blackking = static_cast<King*>(m_board[row][col]);
            }
            else if (row == 7 && col == 3) {
                m_board[row][col] = new King(Pion::WHITE, Pion::KING, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));
                whiteking = static_cast<King*>(m_board[row][col]);
               
            }
            else if(row == 1) {
                m_board[row][col] = new Pawn(Pion::BLACK, Pion::PAWN, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));

            }
            else if (row == 6) {          
                m_board[row][col] = new Pawn(Pion::WHITE, Pion::PAWN, handler);
                m_board[row][col]->setNewPosition(std::make_pair(col, row));

            }else
               m_board[row][col] = nullptr;
        }
    }

    m_turn = Pion::WHITE;
    m_handler = handler;

    calcAllMoves();
    
};


void Game::render(Handler* handler)
{

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
           if (m_board[row][col] != nullptr) 
           {
                m_board[row][col]->pionsprite.setPosition(col * size, row * size);
                handler->window.draw(m_board[row][col]->pionsprite);
           }
        }
    }   
}   

void Game::renderMove(Handler* handler, Pion* clickedpion) {

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(66, 66));
    rectangle.setFillColor(sf::Color(100, 250, 50, 64));

    clickedpion->allPosibleMove(m_board, true);
    std::vector<Pion::m_PossibleMove>possiblemove = clickedpion->getPossibleMove();
    if (possiblemove.size() != 0)
    {
        for (auto& i : possiblemove) {
            rectangle.setPosition(i.yCord * 66, i.xCord * 66);
            handler->window.draw(rectangle);
        }
    }
}

Pion* Game::getBoardPos(int row, int col)
{
    return m_board[col][row];
}

void Game::movePion(Pion* clickedpion,int xStart, int yStart, int xEnd, int yEnd, Pion::MoveType movetyp, Handler* handler)
{
   
    switch (movetyp)
    { 
    case Pion::NORMAL:
        normal(xStart, yStart, xEnd, yEnd);
        break;

    case  Pion::PROMOTION:
        promotion(xStart, yStart, xEnd, yEnd, handler);
        break;
        
    default:
        break;
    }


    if (clickedpion->getTyp() == Pion::KING && clickedpion->getTeam() == Pion::WHITE)
    {
        whiteking = static_cast<King*>(m_board[yEnd][xEnd]);
    }
    else if (clickedpion->getTyp() == Pion::KING && clickedpion->getTeam() == Pion::BLACK)
    {
        blackking = static_cast<King*>(m_board[yEnd][xEnd]);
    }
 
   
    gameState();
}

void Game::normal(int xStart, int yStart, int xEnd, int yEnd)
{
    if (m_board[yEnd][xEnd] != nullptr)
    {
        m_board[yEnd][xEnd]->~Pion();
    }

    m_board[yEnd][xEnd] = Game::getBoardPos(xStart, yStart);
    m_board[yEnd][xEnd]->setNewPosition(std::make_pair(xEnd, yEnd));

    m_board[yStart][xStart] = nullptr;
}

void Game::promotion(int xStart, int yStart, int xEnd, int yEnd, Handler* handler)
{
    if (m_board[yEnd][xEnd] != nullptr)
    {
        m_board[yEnd][xEnd]->~Pion();
    }

    if (m_turn == Pion::WHITE)
    {
        m_board[yEnd][xEnd] = new Queen(Pion::WHITE, Pion::QUEEN, handler);
    }
    else if (m_turn == Pion::BLACK)
    {
        m_board[yEnd][xEnd] = new Queen(Pion::BLACK, Pion::QUEEN, handler);
    }

    m_board[yEnd][xEnd]->setNewPosition(std::make_pair(xEnd, yEnd));

    m_board[yStart][xStart] = nullptr;
}

bool Game::isValidMove(Pion* clickedpion, int x, int y)
{
   
    std::vector<Pion::m_PossibleMove>possiblemove = clickedpion->getPossibleMove();


    for (auto& value : possiblemove)
    {
        if (value.xCord == y && value.yCord == x) 
        {
            return true;
        }
    }
    return false;


}

void Game::gameState()
{
    bool lost = true;
    King* king = blackking;

    

    if (m_turn == Pion::BLACK)
    {
        king = whiteking;
        
    }

    king->check(m_board, king->getPos().second, king->getPos().first);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (m_board[i][j] != nullptr)
            {
                if (m_board[i][j]->getTeam() != m_turn)
                {
                    m_board[i][j]->allPosibleMove(m_board, true);

                    if (!m_board[i][j]->getPossibleMove().empty())
                    {
                        lost = false;
                    }
                }
            }
        }
    }

    if (king->getCheck() && lost)
    {
        if (m_turn == Pion::BLACK)
        {
            std::cout << "Black wins!";
        }
        else
        {
            std::cout << "White wins!";
        }
    }
    else if (lost)
    {
        if (m_turn == Pion::BLACK)
        {
            std::cout << "Remis!";
        }
        else
        {
            std::cout << "Remis!";
        }
    }

}

void Game::calcAllMoves()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (m_board[i][j] != nullptr)
            {
                m_board[i][j]->allPosibleMove(m_board, false);
            }
        }
    }
}