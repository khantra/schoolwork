#include "Board.hpp"
#include <iostream>

using namespace std;


class TicTacToe
{


    public:
        // gameBoard object of the Board class
        Board playingField;
        
        //updated after every move
        // which player's turn it is
        char playerTurn;
    
        // total number of turns taken in the game
        int turnCount;
        
        //constructor is used to initate who goes first    
        TicTacToe(char newTurn);
    
        // play Function
        void play();
};
