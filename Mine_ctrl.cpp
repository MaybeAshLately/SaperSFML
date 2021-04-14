#include <iostream>
#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "Array2D.h"

//KONSTRUKTOR KLASY KONTROLERA 
MSTextController::MSTextController(MinesweeperBoard &board,MSBoardTextView &board_text): board(board), board_text(board_text)
{
  height=board.getBoardHeight();
  width=board.getBoardWidth();

}

//FUNKCJA PRYWATNA ODSŁANIAJĄCA POLE 
void MSTextController::reveal_field()
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

//FUNKCJA PRYWATNA ZATYKAJĄCA flagę
void MSTextController::put_flag()
{
   int wiersz, kolumna;
      std::cout<<"Na którym polu chcesz zatknąć flagę? Podaj w formacie wiersz,enter, kolumna (pamiętaj że numeracja jest od zera!)"<<std::endl;
      std::cin>>wiersz>>kolumna;
      std::cout<<std::endl;
      
      if(board.getFieldInfo(wiersz,kolumna)=='#') std::cout<<"WSKAZANE POLE NIE ISTNIEJE!"<<std::endl;
      else if(board.HasFlag(wiersz, kolumna)) std::cout<<"Na wskazanym polu już jest flaga!"<<std::endl;
      else if(board.IsRevealed(wiersz,kolumna)==true) std::cout<<"To pole już jest odkryte! "<<std::endl;
      else 
      {
        board.toggleFlag(wiersz, kolumna);
      }
}

//FUNKCJA PRYWATNA SPRAWDZAJĄCA CZY GDZIEŚ NA PLANSZY SĄ JAKIEŚ FLAGI
bool MSTextController::are_flags()
{
  for(int row=0;row<=height-1;row++)
  {
    for(int col=0;col<=width-1;col++)
    {
      if(board.HasFlag(row,col)==true) return true;
    }
    
  }

  return false;
}


//FUNKCJA PRYWATNA USUWAJĄCA FLAGI
void MSTextController::remove_flag()
{
  if(are_flags()==false) std::cout<<"Na planszy nie ma żadnych flag"<<std::endl;
       else
       {
         int wiersz, kolumna;
         std::cout<<"Z jakiego pola chcesz usunąć flagę? Podaj w formacie wiersz,enter, kolumna (pamiętaj że numeracja jest od zera!)"<<std::endl;
         std::cin>>wiersz>>kolumna;
         std::cout<<std::endl;

         if(board.HasFlag(wiersz, kolumna)==false) std::cout<<"Na podanym polu nie ma flagi!"<<std::endl;
         else
         {
           board.toggleFlag(wiersz, kolumna);
         }
       }
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
    std::cout<<"3. Usunąć flagę"<<std::endl;
    std::cin>>decyzja;

    switch(decyzja)
    {
          case '1':
          {
              reveal_field();
          }
          break;
          
          case '2':
          {
           put_flag();
          }
          break;
    
          case '3':
          {
            remove_flag();
          }
          break;
          default:
          {
            std::cout<<"Podana komenda nie istnieje!"<<std::endl;
          }
          break;
    }
    

  }


board_text.display();
}