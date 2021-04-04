#include <iostream>
#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "Array2D.h"


//KONSTRUKTOR KLASY WYŚWIETLAJĄCEJ PLANSZĘ 
MSBoardTextView::MSBoardTextView(MinesweeperBoard & board): board_text(board) 
{
  height=board_text.getBoardHeight();
  width=board_text.getBoardWidth();
}


//WYŚWIETLA PLANSZĘ DLA GRACZA
void MSBoardTextView::display() const
{
  std::cout<<std::endl;
  
for(int row=0;row<=height-1;row++)
  {
    for(int col=0;col<=width-1;col++)
    {
      std::cout<<"[";
 
      if(board_text.getFieldInfo(row, col)=='F') std::cout<<"F";
      else if(board_text.getFieldInfo(row, col)=='_') std::cout<<".";
      else if(board_text.getFieldInfo(row, col)=='x') std::cout<<"M";
      else std::cout<<board_text.CountMines(row, col);
   
      std::cout<<"]";
    }
    std::cout<<std::endl;
  }



  if(board_text.getGameState()!=RUNNING)
  {
    if(board_text.getGameState()==FINISHED_WIN) std::cout<<"WYGRAŁEŚ/AŚ!"<<std::endl;
    else if(board_text.getGameState()==FINISHED_LOSS) std::cout<<"PRZEGRAŁEŚ/AŚ!"<<std::endl;
  }
  
  
 
  std::cout<<std::endl;
}