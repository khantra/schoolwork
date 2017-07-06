/*********************************************************************
** Author: Khandkar shadid
** Date:3/16/2017
** Description: Class Definition of Board including member functions
and constructor
*********************************************************************/

enum GameState {xWins, oWins, draw, inprogress};

class Board
{
private:
    
public:
    char board[3][3];
    
    // Default Constructor
    Board();
    
    // makeMove Function
    bool makeMove(int newX, int newY, char newTurn);
    
    // gameState Function
    int gameState();
    int totalCount;
    // print Function
    void print();
    
    // which player's turn it is
    char playerTurn;
    
    // total number of turns taken in the game
    int totalTurns;
};