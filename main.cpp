#include <iostream>
#include "MineB.h"


using namespace std;

void intro()
{
  cout<<endl;
  cout<<"Maciej (----56)"<<endl;
  cout<<endl;
}

void testowanie()
{
  MinesweeperBoard test(10,10,DEBUG);
  test.debug_display();
  cout<<"szerokość: "<<test.getBoardWidth()<<endl;
  cout<<"wysokość: "<<test.getBoardHeight()<<endl;
  cout<<"Liczba min: "<<test.getMineCount()<<endl; 

  //Sprawdza czy jest flaga
  cout<<"czy flaga "<<test.HasFlag(1, 2)<<endl;
  //Sprawdza czy jest odkryte
  cout<<"czy odkryte "<<test.IsRevealed(2, 2)<<endl;

  //odkryj pole
  test.revealField(1, 2);
  //zatknij flagę 
  test.toggleFlag(2, 2);
  
  //Miny na sąsiednich polach
  cout<<"Miny na sąsiednich "<<test.CountMines(1, 2)<<endl;

  //zwraca stan gry
  cout<<"stan gry: "<<test.getGameState()<<endl;

  

  

}

void display_test()
{
  MinesweeperBoard board(20,10,GameMode::EASY);
 MSBoardTextView view (board);
 view.display();
 board.revealField(0,5);
 view.display();

}

int main() {
  intro();
  srand(time(0));
  
  
  cout<<endl;
  cout<<endl; 

 // testowanie();

 display_test();

 

  


  

}