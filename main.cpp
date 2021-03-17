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
  
  MinesweeperBoard test(9,7,DEBUG);
  
  cout<<endl;
  cout<<endl; 

  test.debug_display();

  cout<<test.getBoardWidth()<<endl;
  cout<<test.getBoardHeight()<<endl;
  cout<<test.getMineCount()<<endl;
  

  


  

}