#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MineB.h"


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

MinesweeperBoard::MinesweeperBoard(const int width,const  int height, const GameMode mode):width(width),height(height),mode(mode)
{
  
  for(int wie=0;wie<=height-1;wie++)
  {
    for(int kol=0;kol<=width-1;kol++)
    {
      board[wie][kol].hasMine=0;
      board[wie][kol].hasFlag=0;
      board[wie][kol].isRevealed=0;
    }
    
  }

  int number_of_fields=width*height;
  int wiersz,kolumna;
  if(mode==EASY)
  {
    int number_of_mines=0.1*number_of_fields;
    int postawione_miny=0;

    while(postawione_miny!=number_of_mines)
    {
       kolumna=rand()%width;
       wiersz=rand()%height;
       if(board[wiersz][kolumna].hasMine==false)
       {
         board[wiersz][kolumna].hasMine=true;
         postawione_miny++;
       }     
       
    }
     
  }
  else if(mode==NORMAL)
  {
    int number_of_mines=0.2*number_of_fields;
    int postawione_miny=0;

    while(postawione_miny!=number_of_mines)
    {
       kolumna=rand()%width;
       wiersz=rand()%height;
       if(board[wiersz][kolumna].hasMine==false)
       {
         board[wiersz][kolumna].hasMine=true;
         postawione_miny++;
       }     
       
    }
  }
  else if(mode==HARD)
  {
     int number_of_mines=0.3*number_of_fields;
    int postawione_miny=0;

    while(postawione_miny!=number_of_mines)
    {
       kolumna=rand()%width;
       wiersz=rand()%height;
       if(board[wiersz][kolumna].hasMine==false)
       {
         board[wiersz][kolumna].hasMine=true;
         postawione_miny++;
       }     
       
    }
  }
  else if(mode==DEBUG)
  {
     for(int wie=0;wie<=height-1;wie++)
     {
        for(int kol=0;kol<=width-1;kol++)
         {
           if(((wie==0)||(wie==kol)||(kol==0 && wie%2==0)))
           {
             board[wie][kol].hasMine=true;
           }
         }
    
      }
  }
  
}

void MinesweeperBoard::debug_display() const
{
  for(int wie=0;wie<=height-1;wie++)
  {
    for(int kol=0;kol<=width-1;kol++)
    {
      std::cout<<"[";
      if(board[wie][kol].hasMine==true) std::cout<<"M";
      else std::cout<<".";
      if(board[wie][kol].isRevealed==true) std::cout<<"o";
      else std::cout<<".";
      if(board[wie][kol].hasFlag==true ) std::cout<<"f";
      else std::cout<<".";
      std::cout<<"] ";
    }
    std::cout<<std::endl;
    
  }
}



//FUNKCJE ZWRACAJĄCE INFORMACJE O POLU

int MinesweeperBoard::getBoardWidth() const
{
  return width;
}

int MinesweeperBoard::getBoardHeight() const
{
  return height;
}

int MinesweeperBoard::getMineCount() const
{ 
  
  if(mode==EASY) return 0.1*(width*height);
  if(mode==NORMAL) return 0.2*(width*height);
  if(mode==HARD) return 0.3*(width*height);
  else return -1;
}


//int MinesweeperBoard::CountMines() const