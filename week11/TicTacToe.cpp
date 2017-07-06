/*********************************************************************
** Author: Khandkar shadid
** Date:3/16/2017
** Description: Class Definition of Tick Tac Toe including member functions
and constructor
*********************************************************************/
#include "TicTacToe.hpp"
#include <iostream>

using namespace std;
TicTacToe::TicTacToe(char inputFirstTurn)
{
int x,y;
    playerTurn = inputFirstTurn;
    cout << "Please enter the coordinates of player " << playerTurn << "'s first move" << endl;
    cin >> x >> y;

	playingField.makeMove( x, y,playerTurn);
	playingField.totalTurns++;
	//cout<<"contructor playingField.totalTurns "<<	playingField.totalTurns<<endl;
	if(playerTurn=='x')
		playerTurn='o';
	else{
		playerTurn='x';
	}

	play();
}


void TicTacToe::play()
{
	//cout<<"TicTacToe::play(): made it here"<<endl;
    int x, y;
    bool inputMove=true;
    int gameState =  playingField.gameState();
	while(inputMove && gameState==inprogress){
       // playingField.print();
        			gameState = playingField.gameState();
					//cout<<"gameState "<<gameState<<endl;
        cout << "It is player " << playerTurn << "'s turn." << endl;
        cout << "Please  enter the coordinates of your move." << endl;
        cin >> x >> y;
        
        inputMove = playingField.makeMove(x, y, playerTurn);
			if (gameState == 0)
			{
           // playingField.print();
            cout << "'x' has won" << endl;
			}
			else if (gameState == 1)
			{
			 // playingField.print();
				cout <<" 'o' has won" << endl;
			}
			else if (gameState == 2)
			{
				// playingField.print();
				cout << "The game is a draw" << endl;
			}
        if (inputMove == true)
        {
            playingField.totalTurns++;
      //  cout<<"playingField.totalTurns "<<playingField.totalTurns<<endl;
			gameState =  playingField.gameState();
			if (gameState == 0)
			{
           // playingField.print();
            cout << "'x' has won" << endl;
			}
			else if (gameState == 1)
			{
			 // playingField.print();
				cout <<" 'o' has won" << endl;
			}
			else if (gameState == 2)
			{
				// playingField.print();
				cout << "The game is a draw" << endl;
			}
			else{
				//cout << "The game is in progress" << endl;

			}
			if (playerTurn == 'x')
            {	
				gameState = playingField.gameState();
			//	cout<<"playerTurn == 'x' gameState "<<gameState<<endl;
                playerTurn = 'o';
            }
            else if (playerTurn == 'o')
            {	
				gameState = playingField.gameState();
			//	cout<<"playerTurn == 'o' gameState "<<gameState<<endl;
                playerTurn = 'x';
				
            }


			
        }
        
        if (inputMove == false)
        {
            playingField.print();
            cout << "That space is taken." << endl;
            cin >> x >> y;
            inputMove = playingField.makeMove(x, y, playerTurn);
				playingField.totalTurns++;
		gameState = playingField.gameState();
					
			if (gameState == 0)
			{
           // playingField.print();
            cout << "'x' has won" << endl;
			}
			else if (gameState == 1)
			{
			 // playingField.print();
				cout <<" 'o' has won" << endl;
			}
			else if (gameState == 2)
			{
				// playingField.print();
				cout << "The game is a draw" << endl;
			}
			else{
				//cout << "The game is in progress" << endl;

			}		
			if (playerTurn == 'x')
            {	
				gameState = playingField.gameState();
			//	cout<<"playerTurn == 'x' gameState "<<gameState<<endl;
                playerTurn = 'o';
            }
            else if (playerTurn == 'o')
            {	
				gameState = playingField.gameState();
				//cout<<"playerTurn == 'o' gameState "<<gameState<<endl;
                playerTurn = 'x';
				
            }

        }
    }
    

 
}

int main()
{   
    int playerOne, playerTwo;
    char inputFirstTurn, inputMove;
    
    Board playingField;
    
    playingField.print();
    
	    cout << "Please enter which player will go first (x or o)." << endl;
    cin >> inputFirstTurn;
    
   // inputMove = playingField.makeMove(playerOne, playerTwo, inputFirstTurn);
    
	//DEFAULT CONSTRUCTOR  handles first
    TicTacToe game(inputFirstTurn);

        
    return 0;
}

