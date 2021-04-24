#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "MSSFMLView.h"
#include "Events.h"
#include "Begining.h"


int main()
{  
sf::RenderWindow window(sf::VideoMode(800, 600), "Saper");
window.setVerticalSyncEnabled(false);
window.setFramerateLimit(1);

sf::RenderWindow window_hello(sf::VideoMode(800, 600), "Saper");
window_hello.setVerticalSyncEnabled(false);
window_hello.setFramerateLimit(1);


 Begining saper_introduction;
 while (window_hello.isOpen())
    {
        sf::Event event;
        while (window_hello.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
              window_hello.close();
              window.close();
            }  
            else if(event.type == sf::Event::MouseButtonPressed)
               {
                 saper_introduction.mouse_button_pressed(event);
               }
            
        }
        window_hello.clear(sf::Color(115,220,10));
        saper_introduction.draw(window_hello);
        window_hello.display();    
    }

MinesweeperBoard board(saper_introduction.get_row_number(),saper_introduction.get_col_number(),saper_introduction.get_mode());
MSSFMLView view(board);
Events view_control(view,board);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)  window.close();
            else if(event.type == sf::Event::MouseButtonPressed)
               {
               view_control.mouse_button(event);
               }
        }
        
        window.clear(sf::Color(115,220,10));
        view.draw(window);
        window.display();  
    }
  return 0;
} 
