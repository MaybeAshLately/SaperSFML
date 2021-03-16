#include <iostream>

using namespace std;

void intro()
{
  cout<<endl;
  cout<<"Maciej (----56)"<<endl;
  cout<<endl;
}

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
  Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy

public:
  MinesweeperBoard();
  void debug_display() const;
};

MinesweeperBoard::MinesweeperBoard()
{
  width=5;
  height=3;

  for(int wie=0;wie<=height-1;wie++)
  {
    for(int kol=0;kol<=width-1;kol++)
    {
      board[wie][kol].hasMine=0;
      board[wie][kol].hasFlag=0;
      board[wie][kol].isRevealed=0;
    }
    
  }

 
  
}

void MinesweeperBoard::debug_display() const
{
  for(int wie=0;wie<=height-1;wie++)
  {
    for(int kol=0;kol<=width-1;kol++)
    {
      cout<<"[";
      if(board[wie][kol].hasMine==true) cout<<"M";
      else cout<<".";
      if(board[wie][kol].isRevealed==true) cout<<"o";
      else cout<<".";
      if(board[wie][kol].hasFlag==true ) cout<<"f";
      else cout<<".";
      cout<<"] ";
    }
    cout<<endl;
    
  }
}
int main() {
  intro();

  MinesweeperBoard test;
  
  cout<<endl;
  cout<<endl; 

  test.debug_display();

  


  

}