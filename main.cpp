#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

// to powinno być w osobnych plikach !

class MinesweeperBoard
{

};

class MSSFMLView
{
	MinesweeperBoard & board;
public:
	explicit MSSFMLView(MinesweeperBoard & b);

	void draw (sf::RenderWindow & win);
};

MSSFMLView::MSSFMLView(MinesweeperBoard & b) : board(b) {}

void MSSFMLView::draw (sf::RenderWindow & win)
{
	// tu robimy rysowanie planszy na podstawie zawartości "board"
	
	sf::RectangleShape r;
	r.setSize ( sf::Vector2f(10, 10) ) ;
	r.setFillColor ( sf::Color::Red );
	r.setPosition(100,100);
	win.draw(r);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(1);

    MinesweeperBoard board;
	MSSFMLView view(board);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        
        window.clear();
        view.draw(window);
        window.display();
    }

  return 0;
} 
