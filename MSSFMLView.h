#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "Array2D.h"

enum View_mode {GAME, LOST, WIN};

struct Flag
{
   sf::RectangleShape base;
   sf::RectangleShape stick;
   sf::CircleShape triangle;
};

struct Bomb
{
   sf::CircleShape circle;
   sf::RectangleShape rectangle;
   sf::RectangleShape fuse;
};

class MSSFMLView
{
	MinesweeperBoard & board;

  int size_of_field;
  int height,width;
  sf::RectangleShape r;
  sf::Font font1;
  sf::Text txt1;
  
  Flag flag_icon;
  void locate_flag(sf::Vector2f pozycja,Flag & flag_icon);

  Bomb bomb_icon;
  void locate_bomb(sf::Vector2f pozycja,Bomb & bomb_icon);

  View_mode mode;

  void display_of_lost(sf::RenderWindow & win);
  void display_of_win(sf::RenderWindow & win);

 void draw_of_fields(int row, int col, sf::RenderWindow & win);

public:
	explicit MSSFMLView(MinesweeperBoard & b);

	void draw (sf::RenderWindow & win);
};

#endif