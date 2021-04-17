#include "MSSFMLView.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"

#include <vector>
#include <cerrno>
#include <cstring>



MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) 
{

  height=board.getBoardHeight();
  width=board.getBoardWidth();

  if(height>=width) size_of_field=600/height-10;
  else size_of_field=800/width-10;

 //---------------
  
 

   std::vector < std::string > fontSearchPath {
        "../resources/RomanSD.ttf",
        "C:/Windows/Fonts/RomanSD.ttf",
        "/usr/share/fonts/truetype/msttcorefonts/RomanSD.ttf"
    };
   bool fontLoaded=false;
   for(auto file: fontSearchPath)
   {
     fontLoaded=font1.loadFromFile(file);
     if(fontLoaded) break;
     std::cerr<<"CZCIONKA SIĘ NIE ŁADUJE!!!!"<<std::endl;
     abort();
   }
  
  txt1.setFont(font1);
  
 
  

}

void MSSFMLView::draw (sf::RenderWindow & win)
{
	// tu robimy rysowanie planszy na podstawie zawartości "board"
	
  
  for(int row=0;row<=height-1;row++)
  {
    for(int col=0;col<=width-1;col++)
    {
      
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
      else if((board.getFieldInfo(row,col)!='x')and(board.IsRevealed(row,col)==true))
      {
        
        
        r.setFillColor( sf::Color::Green );
        txt1.setString(std::to_string(board.CountMines(row,col)));
        txt1.setPosition(0+col*(800/width)+size_of_field/4,0+row*(600/height)-size_of_field/5);
        txt1.setCharacterSize(size_of_field);
        
      }
      

     
      win.draw(r);
     win.draw(txt1);
	    
    }
    
  }


  
}

