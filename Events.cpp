#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "MSSFMLView.h"
#include "Events.h"

Events::Events(MSSFMLView & view, MinesweeperBoard & board) : view_control(view), board_control(board)
{
   height=board_control.getBoardHeight();
   width=board_control.getBoardWidth();
  

  if(height>=width) size_of_field=600/height-10;
  else size_of_field=800/width-10;
}


void Events::mouse_button(sf::Event event)
{
   
   //LEWY
   if(event.mouseButton.button==0)
   {
     left_button(event);
   }
   else if(event.mouseButton.button==1)
   {
     right_button(event);
   }
}


//LEWY PRZYCISK- ODSŁANIANIE POLA
void Events::left_button(sf::Event event)
{
int pressed_row=-1;
int pressed_col=-1;

  if(is_pressed_on_field(event,pressed_row,pressed_col)==true)
  {
    board_control.revealField(pressed_row,pressed_col);
  }

}


//PRAWY PRZYCISK- ZATYKANIE/ODTYKANIE FLAGI
void Events::right_button(sf::Event event)
{  
  int pressed_row=-1;
  int pressed_col=-1;
  
  if(is_pressed_on_field(event,pressed_row,pressed_col)==true) 
  {
    board_control.toggleFlag(pressed_row,pressed_col);
  }
}



//FUNKCJA POMOCNICZA SPRAWDZAJĄCA CZY KLIKNIĘTE WSPÓŁRZĘDNE ZNAJDUJĄ SIĘ NA JAKIMŚ POLU
bool Events::is_pressed_on_field(sf::Event event,int & pressed_row,int & pressed_col)
{
    int x=event.mouseButton.x;
    int y=event.mouseButton.y;

  bool is_field_horizontal=false;
  bool is_field_vertical=false;

 

  for(int row=0;row<=height-1;row++)
  {
    int position=0+row*(600/height);
    if(y>=(position)and(y<=position+size_of_field))
    {
      is_field_vertical=true;
      pressed_row=row;
      
    }
    
  }

  for(int col=0;col<=width-1;col++)
  {
     
    int position=0+col*(800/width);
    if(x>=(position)and(x<=position+size_of_field))
    {
      is_field_horizontal=true;
      pressed_col=col;
      
    }
  }

  if((is_field_horizontal==true)and(is_field_vertical==true))
  {
    return true;
  }

  return false;
}