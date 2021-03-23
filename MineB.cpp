#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MineB.h"


MinesweeperBoard::MinesweeperBoard()
{
  width=5;
  height=3;
  stan_gry=RUNNING;

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


//GENERUJE POLE DO GRY Z ODPOWIEDNIĄ ILOŚCIĄ MIN W ZALEŻNOŚCI OD WPROWADZONEGO POZIOMU
MinesweeperBoard::MinesweeperBoard(const int width,const  int height, const GameMode mode):width(width),height(height),mode(mode)
{
  stan_gry=RUNNING;
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

//WYŚWIETLA PLANSZĘ (WSZYSTKO WIDOCZNE)
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
  else
  {
    int odp=0;
    odp=odp+width;

    if(height>=3)
    {
       if(height%2==0) odp=odp+(height/2)-1;
       else odp=odp+height/2;
    }
   

    if(width>=height) odp=odp+height-1;
    else odp=odp+width-1;

    return odp;
  }
  
}


//SPRAWDZA ILE MIN JEST NA SĄSIEDNICH POLACH
int MinesweeperBoard::CountMines(int row,int col) const
{
  if(board[row][col].isRevealed==false) return -1;
  
  if(getFieldInfo(row,col)=='#') return -1; 

  int countOfMines=0;

   //NA GÓRZE
  if(row-1>=0)
  {
    if(board[row-1][col].hasMine==true) countOfMines++;
  }
  


  //NA DOLE
  if(row+1<=height-1)
  {
    if(board[row+1][col].hasMine==true) countOfMines++;
  }
  
  
  //NA PRAWO
  if(col+1<=width-1)
  {
    if(board[row][col+1].hasMine==true) countOfMines++;
  }
  
  
  //NA LEWO
  if(col-1>=0)
  {
    if(board[row][col-1].hasMine==true) countOfMines++;
  }
  
 return countOfMines;
}


//SPRAWDZA CZY JEST FLAGA
bool MinesweeperBoard::HasFlag(int row, int col) const
{
  
  if(getFieldInfo(row,col)=='#') return false; 
  
  if(getFieldInfo(row, col)=='F') return true; //true jeśli jest zakryte i ma flagę

  return false;

}


//ZATYKA FLAGĘ
void MinesweeperBoard::toggleFlag(int row, int col)
{
 
  if(getFieldInfo(row,col)=='#') return; 
  if(board[row][col].isRevealed==true) return;
  if(stan_gry!=RUNNING) return;

  board[row][col].hasFlag=true;
}

//ODSŁANIA POLE
void MinesweeperBoard::revealField(int row, int col)
{
  if(getFieldInfo(row,col)=='#') return; 
  if(board[row][col].isRevealed==true) return;
  if(stan_gry!=RUNNING) return;
  if(board[row][col].hasFlag==true) return;

 

  if(board[row][col].hasMine==false) 
  {
    board[row][col].isRevealed=true;
    numberOfSteps++;
    stan_gry=getGameState();
    if(stan_gry==FINISHED_WIN) std::cout<<"WYGRAŁEŚ"<<std::endl;
  }
  else 
  {
    if((numberOfSteps==0)and(mode!=DEBUG))
    {
       board[row][col].hasMine=false;
       int wiersz,kolumna;
       bool czy_umieszczona=0;
      do
      {
        kolumna=rand()%width;
        wiersz=rand()%height;
       if(board[wiersz][kolumna].hasMine==false)
       {
         board[wiersz][kolumna].hasMine=true;
         czy_umieszczona=1;
       }     
      }while(czy_umieszczona==0);
       
       board[row][col].isRevealed=true;
    }
    else
    {
      board[row][col].isRevealed=true;
      stan_gry=FINISHED_LOSS;
      std::cout<<"PRZEGRAŁEŚ!"<<std::endl;
      return;
    }
  }


}

//SPRAWDZA CZY POLE ODKRYTE
bool MinesweeperBoard::IsRevealed(int row, int col) const
{
  
  if(getFieldInfo(row,col)=='#') return false; 

  if(board[row][col].isRevealed==false) return false;
  return true;
}

//ZWRACA stan_gry
GameState MinesweeperBoard::getGameState() const
{
  if(stan_gry==FINISHED_LOSS) return FINISHED_LOSS;
  
  for(int row=0;row<=height-1;row++)
  {
    for(int col=0;col<=width-1;col++)
    {
      if((board[row][col].isRevealed==false)&&(board[row][col].hasMine==false)) return RUNNING;

    }
    
  }

  
  return FINISHED_WIN;
}


//ZWRACA INFORMACJE O POLU
char MinesweeperBoard::getFieldInfo(int row, int col) const
{
  if((col>width-1)||(row>height-1)||(col<0)||(row<0)) return '#';

  if((board[row][col].isRevealed==false)&&(board[row][col].hasFlag==true)) return 'F';

  if((board[row][col].isRevealed==false)&&(board[row][col].hasFlag==false)) return '_';

  if((board[row][col].isRevealed==true)&&(board[row][col].hasMine==true)) return 'x';

  if((board[row][col].isRevealed==true)&&(CountMines(row, col)==0)) return ' ';
  else if(CountMines(row, col)!=0) return char(CountMines(row, col));

 
}