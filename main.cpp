#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "MSSFMLView.h"





int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

    MinesweeperBoard board(7,4,DEBUG);
	MSSFMLView view(board);

  board.toggleFlag(1,1);
  board.revealField(1,2);

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
                if(event.mouseButton.button==0)
                {
                  //kliknięto prawym
                  //ustalić współrzędne 
                  //sprawdzić czy leżą w jakimś polu
                  //jeśli tak odkryć je 
                  int x=event.mouseButton.x;
                  int y=event.mouseButton.y;
                  //SPRÓBOWAĆ UTWORZYĆ KLASĘ DO OBSŁUGI EVENTÓW (TAK JAK NA WYKŁADZIE)
                
                }
               }
        }
        
        window.clear();
        view.draw(window);
        window.display();

       
    }

  return 0;
} 
