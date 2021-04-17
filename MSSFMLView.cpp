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
  

  //UTWORZENIE IKONKI FLAGI O ODPOWIEDNICH WYMIARACH W ZALEŻNOŚCI OD WYMIARÓW PÓL
 flag_icon.base.setSize(sf::Vector2f(size_of_field/2,size_of_field/10));
 flag_icon.base.setFillColor(sf::Color(159,96,0));

 flag_icon.stick.setSize(sf::Vector2f(size_of_field/10,size_of_field/2));
 flag_icon.stick.setFillColor(sf::Color(159,96,0));

 flag_icon.triangle.setRadius(size_of_field/6);
 flag_icon.triangle.setPointCount(3);
 flag_icon.triangle.setFillColor(sf::Color::White);
 flag_icon.triangle.setRotation(90);
 flag_icon.triangle.setOutlineThickness(1);
 flag_icon.triangle.setOutlineColor(sf::Color::Black);


 bomb_icon.circle.setRadius(size_of_field/4);
 bomb_icon.circle.setFillColor(sf::Color::Black);

 bomb_icon.rectangle.setSize(sf::Vector2f(size_of_field/10,size_of_field/10));
 bomb_icon.rectangle.setFillColor(sf::Color::Black);
 bomb_icon.rectangle.setRotation(45);

 bomb_icon.fuse.setSize(sf::Vector2f(size_of_field/20,size_of_field/5));
 bomb_icon.fuse.setRotation(45);
 bomb_icon.fuse.setFillColor(sf::Color(205,137,2));
 bomb_icon.fuse.setOutlineThickness(1);
 bomb_icon.fuse.setOutlineColor(sf::Color::Black);

 

  

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
        sf::Vector2f pozycja=r.getPosition();
        locate_flag(pozycja,flag_icon);
      }
      else if(board.getFieldInfo(row,col)=='x')
      {
        r.setFillColor (sf::Color::Red);
         sf::Vector2f pozycja=r.getPosition();
        locate_bomb(pozycja,bomb_icon);
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
     if(board.getFieldInfo(row,col)=='F')
     {
       win.draw(flag_icon.base);
       win.draw(flag_icon.stick);
       win.draw(flag_icon.triangle);
	    
     }
     else if(board.getFieldInfo(row,col)=='x')
     {
       win.draw(bomb_icon.circle);
      win.draw(bomb_icon.rectangle);
      win.draw(bomb_icon.fuse);
     }
     
    }
    
  }


  
}

void MSSFMLView::locate_flag(sf::Vector2f pozycja,Flag & flag_icon)
{
   flag_icon.base.setPosition(pozycja.x+size_of_field/4,pozycja.y+size_of_field*0.7);
   flag_icon.stick.setPosition(pozycja.x+size_of_field*0.45,pozycja.y+size_of_field*0.3);
   flag_icon.triangle.setPosition(pozycja.x+size_of_field*0.7+size_of_field/10,pozycja.y+size_of_field*0.3);
}


void MSSFMLView::locate_bomb(sf::Vector2f pozycja,Bomb & bomb_icon)
{
  bomb_icon.circle.setPosition(pozycja.x+size_of_field/4,pozycja.y+size_of_field/4);
  bomb_icon.rectangle.setPosition(pozycja.x+size_of_field*0.7,pozycja.y+size_of_field*0.25);
  bomb_icon.fuse.setPosition(pozycja.x+size_of_field*0.85,pozycja.y+size_of_field*0.13);
}