/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/18/2017
** Description:A program that program that prompts the user for an 
integer that the player (maybe the user, maybe someone else) will 
try to guess. They are then notified if its 'too low', 'too high'
or if they guessed correctly.
*********************************************************************/
#include <iostream>

using namespace std;

int main()
{
/*********************************************************************
** Description:Prompt User for a number to guess.
*********************************************************************/	
    int userInput=0, guess=0, playerGuess=0, count=1;
    bool game=false;
   cout << "Enter the number for the player to guess." << endl; 
   cin>>userInput;
   game=true;
      guess=userInput;
      cout<<"Enter Your Guess."<<endl;
/*********************************************************************
** Description:Keep taking guesses while the correct answer has not 
been found, notifying them of whether they should go higher or lower
by comparing the number they have currently guessed to the correct
guess.
*********************************************************************/		  
   while(game){
       cin>>playerGuess;
       if(playerGuess > guess){
      cout<<"Too high - try again."<<endl; 
      
       }
       else if(playerGuess < guess){
      cout<<"Too low - try again."<<endl; 
       }
       else if(playerGuess == guess){
           if(count==0){
                     cout<<"You guessed it in "<<"1" <<" tries"<<endl; 
           }
           else{
         cout<<"You guessed it in "<<count <<" tries."<<endl; 
      game=false;
           }
       }
       count++;
   }


  
  
   
   return 0;
}