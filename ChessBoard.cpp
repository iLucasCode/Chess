#include "Chessboard.h"



ChessBoard::ChessBoard(){};
    

void ChessBoard::setSquares(Handler* handler)
{
    bool light = false;
    for (int i = 0; i < 8; i++) {
        light = !light;
        for (int j = 0; j < 8; j++) {
            if (light == true) {
                boardtexture.loadFromFile("C:/c++/Chess/assets/light.png");
                light = !light;
            }
            else {
                boardtexture.loadFromFile("C:/c++/Chess/assets/dark.png");
                light = !light;
            }
            boardspirte.setTexture(boardtexture);
            boardspirte.setPosition(j * 66.f, i * 66.f);
            handler->window.draw(boardspirte);
        }
    }
}
   

 

 
