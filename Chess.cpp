#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pion.h"
#include "ChessBoard.h"
#include "Game.h"
#include "Handler.h"
#include <list>


int main()
{
    Handler* handler = new Handler;
    
    Game game(handler);

    ChessBoard chessboard;

    int xStart = -1;
    int yStart = -1;
    int xEnd = -1;
    int yEnd = -1;
    Pion* clickedpion = nullptr;

    
  
    while (handler->window.isOpen())
    {
        
        
        sf::Event event;
        while (handler->window.pollEvent(event))
        {
            chessboard.setSquares(handler);
            

            if (event.type == sf::Event::Closed) {
                handler->window.close();
            }
                


            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                     
                
                    sf::Vector2i mouse_position_start = sf::Mouse::getPosition(handler->window);
                    xStart = mouse_position_start.x / 64;
                    yStart = mouse_position_start.y / 64;
                    
                 
                    if (game.m_board[yStart][xStart] != nullptr && game.m_board[yStart][xStart]->getTeam() == game.m_turn) {
                        clickedpion = game.getBoardPos(xStart, yStart);  
                    }           
                    
                    
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                 
                if(clickedpion != nullptr)
                    game.renderMove(handler, clickedpion);
               
            }

            if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
            {

                    sf::Vector2i mouse_position_end = sf::Mouse::getPosition(handler->window);
                    xEnd = mouse_position_end.x / 64;
                    yEnd = mouse_position_end.y / 64;

                    if (clickedpion != nullptr && game.isValidMove(clickedpion, xEnd, yEnd) == true)
                    {

                        std::vector<Pion::m_PossibleMove> list = game.getBoardPos(xStart, yStart)->getPossibleMove();
                        for (const auto& value : list)
                        {
                            if (value.yCord == xEnd && value.xCord == yEnd)
                            {
                                game.movePion(clickedpion, xStart, yStart, xEnd, yEnd, value.typeMove, handler);
                            }
                        }

                        if (game.m_turn == Pion::WHITE)
                            game.m_turn = Pion::BLACK;
                        else if (game.m_turn == Pion::BLACK)
                            game.m_turn = Pion::WHITE;

                        game.calcAllMoves();
                        
                    }
                   
                   
                   clickedpion = nullptr;
            }
            game.render(handler);
            handler->window.display();
                
        }
       
        
    }

    return 0;
}

