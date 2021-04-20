#ifndef EVENTS_H
#define EVENTS_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "MineB.h"
#include "Mine_text.h"
#include "Mine_ctrl.h"
#include "MSSFMLView.h"

class Events
{
  MSSFMLView & view_control;
  MinesweeperBoard & board_control;

  int height;
  int width;
  int size_of_field;
  
  void funkcja();

  void left_button(sf::Event event);
  void right_button(sf::Event event);
 
  bool is_pressed_on_field(sf::Event event,int & pressed_row,int & pressed_col) const;
  
  public:
  explicit Events(MSSFMLView & view,MinesweeperBoard & board);

  void mouse_button(sf::Event event);
  

};

#endif