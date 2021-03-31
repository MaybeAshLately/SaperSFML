#include <iostream>
#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"

//KONSTRUKTOR KLASY KONTROLERA 
MSTextController::MSTextController(MinesweeperBoard &board,MSBoardTextView &board_text): board(board), board_text(board_text)
{
  height=board.getBoardHeight();
  width=board.getBoardWidth();

}


//IMPLEMENTACJA KOMUNIKACJI Z GRACZEM
void MSTextController::play()
{
  while(board.getGameState()==RUNNING) 
  {
    board_text.display();
    char decyzja;
    std::cout<<"Jaki ruch chcesz wykonać?"<<std::endl;
    std::cout<<"1. Odkryć pole"<<std::endl;
    std::cout<<"2. Zatknąć flagę"<<std::endl;
    std::cin>>decyzja;
    if(decyzja=='1')
    {
      int wiersz, kolumna;
      std::cout<<"Które pole chcesz odsłonić? Podaj w formacie wiersz,enter, kolumna (pamiętaj że numeracja jest od zera!)"<<std::endl;
      std::cin>>wiersz>>kolumna;

      if(board.getFieldInfo(wiersz,kolumna)=='#') std::cout<<"WSKAZANE POLE NIE ISTNIEJE!"<<std::endl;
      else if(board.HasFlag(wiersz, kolumna)) std::cout<<"Na wskazanym polu jest Flaga!"<<std::endl;
      else if(board.IsRevealed(wiersz,kolumna)==true) std::cout<<"To pole już jest odkryte! "<<std::endl;
      else 
      {
        board.revealField(wiersz, kolumna);
      }

      
      
    }
    else if(decyzja=='2')
    {
      int wiersz, kolumna;
      std::cout<<"Na którym polu chcesz zatknąć flagę? Podaj w formacie wiersz,enter, kolumna (pamiętaj że numeracja jest od zera!)"<<std::endl;
      std::cin>>wiersz>>kolumna;
      
      if(board.getFieldInfo(wiersz,kolumna)=='#') std::cout<<"WSKAZANE POLE NIE ISTNIEJE!"<<std::endl;
      else if(board.HasFlag(wiersz, kolumna)) std::cout<<"Na wskazanym polu już jest Flaga!"<<std::endl;
      else if(board.IsRevealed(wiersz,kolumna)==true) std::cout<<"To pole już jest odkryte! "<<std::endl;
      else 
      {
        board.toggleFlag(wiersz, kolumna);
      }
    }

  }


board_text.display();
}