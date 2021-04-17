#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "Array2D.h"

class MSSFMLView
{
	MinesweeperBoard & board;

  int size_of_field;
  int height,width;
  sf::RectangleShape r;

  sf::Font font1;
  sf::Text txt1;
  
  

public:
	explicit MSSFMLView(MinesweeperBoard & b);

	void draw (sf::RenderWindow & win);
};

#endif