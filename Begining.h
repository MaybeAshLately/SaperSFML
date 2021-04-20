#ifndef WINDOW_H
#define WINDOW_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MineB.h"
#include <cstring>

enum Mode_of_window{HELLO, CHOICE_OF_MODE, CHOICE_OF_BOARD,INSTRUCTIONS};



class Begining
{
  
  Mode_of_window app_state;
  void display_of_hello_mode(sf::RenderWindow & win);
  void display_of_choice_mode_mode(sf::RenderWindow & win);
  void display_of_choice_board(sf::RenderWindow & win);
  void display_of_instructions(sf::RenderWindow & win);

  sf::Font font1;
  sf::Text txt1,txt2,txt3,txt4;

  int choosed_row;
  int choosed_col;
  GameMode choosed_mode;

  sf::RectangleShape field;

  int help_row=0,help_col=0;
  bool error=false;
  bool end=false;

  void ready_was_pressed();
  void was_pressed_number(sf::Event event);
  void start_game(sf::Event event);
  void choice_level(sf::Event event);
  void choice_board(sf::Event event);
  void ready_was_pressed(sf::Event event);
  void instructions_agree(sf::Event event);


  public:

  Begining();
  void draw(sf::RenderWindow & win);
  void mouse_button_pressed(sf::Event event);
  

  GameMode get_mode() const;
  int get_row_number() const;
  int get_col_number() const;

  

};
#endif