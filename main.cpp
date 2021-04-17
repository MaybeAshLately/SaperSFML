#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "MSSFMLView.h"
#include "Events.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

    MinesweeperBoard board(7,4,DEBUG);
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
                //Prawy-0-odkrycie pola
                //lewy-1-obsługa flag
               view_control.mouse_button(event);
               }
        }
        
        window.clear();
        view.draw(window);
        window.display();

       
    }

  return 0;
} 
