#pragma once
#include <SFML/Graphics.hpp>
#include "Pion.h"
#include "Handler.h"

class ChessBoard 
{
public:
    sf::Texture boardtexture;
    sf::Sprite boardspirte;

    

    

    ChessBoard();

    void setSquares(Handler* handler);
  
       
};

