/*********************************************************************
** Author: Khandkar shadid
** Date:3/16/2017
** Description: Class Definition of Board including member functions
and constructor
*********************************************************************/

#include "Board.hpp"
#include <iostream>

using namespace std;

Board::Board()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = '.';
        }
    }
    
    totalTurns = 0;
}


bool Board::makeMove(int x, int y, char playerTurn)
{
   // cout<<"Board::makeMove: made it here"<<endl;
    if (playerTurn == 'x')
    { 
	//cout<<"made it here makeMove playerturn==x"<< x <<" " << y<< endl;
        if (board[x][y] == '.'  )
        {
			//cout<<"made it here makeMove board[x][y] == "<< board[x][y] << endl;
            board[x][y] = 'x';
			print();
            return true;
        }
    }
    else if (playerTurn == 'o')
    {
        if (board[x][y] == '.' )
        {
            board[x][y] = 'o';
			print();
            return true;
        }
    }
    else
    {  //  cout<<"Board::makeMove: made it to Else Statemeent"<<endl;
			print();
			return false;
    }
    
    return 0;
}


int Board::gameState()
{
    
    for (int i = 0; i < 3; i++)
    {
        if ( (board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]) ||
            (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        {
            if ( (board[i][0] == 'x' && board[i][1] == 'x' && board[i][2] == 'x') ||
                (board[0][i] == 'x' && board[1][i] == 'x' && board[2][i] == 'x') ||
                (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') ||
                (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x'))
            {
                return xWins;
            }
            else if ( (board[i][0] == 'o' && board[i][1] == 'o' && board[i][2] == 'o') ||
                     (board[0][i] == 'o' && board[1][i] == 'o' && board[2][i] == 'o') ||
                     (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') ||
                     (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'))
            {
                return oWins;
            }
        }
    }
        if (totalTurns == 9)
        {
            return draw;
        }
        else
        {
            return inprogress;
        }
    
    return 0;
}

void Board::print()
{
    cout << endl << "  " << "0" << " " << "1" << " " << "2" << endl;
    cout << "0" << " " << board[0][0] << " " << board[0][1] << " " << board[0][2] << endl;
    cout << "1" << " " << board[1][0] << " " << board[1][1] << " " << board[1][2] << endl;
    cout << "2" << " " << board[2][0] << " " << board[2][1] << " " << board[2][2] << endl;
}