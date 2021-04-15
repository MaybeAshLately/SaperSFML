#include "MSSFMLView.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"

#include <vector>



MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) {}

void MSSFMLView::draw (sf::RenderWindow & win)
{
	// tu robimy rysowanie planszy na podstawie zawartości "board"
	
 
 
  int height,width;
  height=board.getBoardHeight();
  width=board.getBoardWidth();
  
  //DEFINIOWANIE OPTYMALNEGO ROZMIARU POLA W ZALEŻNOŚCI OD WYMIARÓW UTWORZONEJ PLANSZY
  int size_of_field;
  if(height>=width) size_of_field=600/height-10;
  else size_of_field=800/width-10;

  for(int row=0;row<=height-1;row++)
  {
    for(int col=0;col<=width-1;col++)
    {
      sf::RectangleShape r;
	    r.setSize ( sf::Vector2f(size_of_field,size_of_field) ) ;
	    r.setFillColor ( sf::Color::Blue );
	    r.setPosition(0+col*(800/width),0+row*(600/height));

      
      if(board.getFieldInfo(row,col)=='F')
      {
        r.setFillColor (sf::Color::Yellow);
      }
      else if(board.getFieldInfo(row,col)=='x')
      {
        r.setFillColor (sf::Color::Red);
      }
      

     
      win.draw(r);
	    
    }
    
  }

 
  
}

