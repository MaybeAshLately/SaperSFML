#include <iostream>
#include "MineB.h"

using namespace std;

void intro()
{
  cout<<endl;
  cout<<"Maciej (----56)"<<endl;
  cout<<endl;
}

int main() {
  intro();
  srand(time(0));
  
  MinesweeperBoard test(10,10,DEBUG);
  
  cout<<endl;
  cout<<endl; 

  test.debug_display();

  //cout<<test.getBoardWidth()<<endl;
  //cout<<test.getBoardHeight()<<endl;
  //cout<<test.getMineCount()<<endl;
  //cout<<test.CountMines(1, 0)<<endl;
  //cout<<test.CountMines(2, 9)<<endl;
  //cout<<test.CountMines(2, 1)<<endl;
  //cout<<test.CountMines(6, 7)<<endl;
 //test.toggleFlag(-1, -5);
  

  


  

}