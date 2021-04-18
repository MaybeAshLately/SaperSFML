#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "MSSFMLView.h"
#include "Events.h"
#include "Begining.h"


//DO ZROBIENIA
//1. Wyświetlić wybrane wymiary (wyświetlić napisy nad kolumnami)
//2. WYŚWIETLENIE SAMOUCZKA, zamknięcie samouczka= zamknięcie okna
//3 WE WŁAŚCIWEJ KLASIE DODAĆ WIDOK PRZEGRANEJ I WYGRANEJ
//7. CODE REVIEW, PRZEJRZEĆ FUNKCJE

//OPCJONALINE- BOMBY NA EKRANIE POWITALNYM
int main()
{
  
	sf::RenderWindow window(sf::VideoMode(800, 600), "Saper gra");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

  sf::RenderWindow window_hello(sf::VideoMode(800, 600), "Saper wprowadzenie");
  window_hello.setVerticalSyncEnabled(false);
  window_hello.setFramerateLimit(1);

int number_of_row=-1;
int number_of_col=-1;
GameMode mode=DEBUG;

 Begining saper_introduction;
 while (window_hello.isOpen())
    {
    
     
        sf::Event event;
        while (window_hello.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)  window_hello.close();
            else if(event.type == sf::Event::MouseButtonPressed)
               {
                 saper_introduction.mouse_button_pressed(event);
               }
            
        }
        
        window_hello.clear();
        saper_introduction.draw(window_hello);
        window_hello.display();    
    }

number_of_col=saper_introduction.get_col_number();
number_of_row=saper_introduction.get_row_number();
mode=saper_introduction.get_mode();


MinesweeperBoard board(number_of_row,number_of_col,mode); 
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
