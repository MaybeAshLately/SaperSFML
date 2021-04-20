#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Begining.h"
#include "MSSFMLView.h"
#include <vector>
#include <cerrno>
#include <cstring>


//KONSTRUKTOR
Begining::Begining()
{
   app_state=HELLO;

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
  txt2.setFont(font1);
  txt3.setFont(font1);
  txt4.setFont(font1);

  


field.setSize(sf::Vector2f(50,20));
field.setFillColor(sf::Color::White);
field.setOutlineThickness(1);
field.setOutlineColor(sf::Color::Black);


}

//--------------------
//RYSOWANIE APLIKACJI
//-----------------

//FUNKCJA WYWOŁUJĄCA FUNKCJE RYSUJĄCE WIDOK APLIKACJI W ZELŻNOŚCI OD ETAPIU NA JAKIM JEST APLIKACJA
void Begining::draw(sf::RenderWindow & win)
{
  if(app_state==HELLO)
  {
     display_of_hello_mode(win);
  }
  else if(app_state==CHOICE_OF_MODE)
  {
    display_of_choice_mode_mode(win);
  }
  else if(app_state==CHOICE_OF_BOARD)
  {
    display_of_choice_board(win);
  }
  else if(app_state==INSTRUCTIONS)
  {
    display_of_instructions(win);
    if(end) win.close();
  }
}


//wyświetlanie etapu powitalnego
void Begining::display_of_hello_mode(sf::RenderWindow & win)
{ 
    sf::RectangleShape start;
    start.setSize(sf::Vector2f(400,100));
    start.setPosition(200,250);
    start.setFillColor(sf::Color(220,59,10));
    start.setOutlineThickness(1);
    start.setOutlineColor(sf::Color::Black);
    txt1.setString("START");
    txt1.setPosition(240,230);
    txt1.setCharacterSize(100);
    win.draw(start);
    win.draw(txt1);
}


//Wyświetlanie trybu wyboryu poziomu gry
void Begining::display_of_choice_mode_mode(sf::RenderWindow & win)
{
    sf::RectangleShape icon1,icon2,icon3;

    icon1.setSize(sf::Vector2f(150,80));
    icon1.setFillColor(sf::Color::Blue);
    icon1.setOutlineThickness(1);
    icon1.setOutlineColor(sf::Color::Black);
  icon2=icon1;
  icon3=icon1;

    icon1.setPosition(100,250);
    icon2.setPosition(300,250);
    icon3.setPosition(500,250);
    txt1.setString("WYBIERZ POZIOM");
    txt1.setPosition(130,100);
    txt1.setCharacterSize(50);

    txt2.setString("EASY");
    txt2.setPosition(140,270);
    txt2.setCharacterSize(25);
    txt3.setString("NORMAL");
    txt3.setPosition(310,270);
    txt3.setCharacterSize(25);
    txt4.setString("HARD");
    txt4.setPosition(540,270);
    txt4.setCharacterSize(25);

    win.draw(txt1);   
    win.draw(icon1);
    win.draw(icon2);
    win.draw(icon3);
    win.draw(txt2);
    win.draw(txt3);
    win.draw(txt4);
}


//Wyświetlanie trybu wyboru planszy
void Begining::display_of_choice_board(sf::RenderWindow & win)
{
  txt1.setString("WYBIERZ ROZMIAR PLANSZY");
  txt1.setPosition(80,10);
  txt1.setCharacterSize(40);
  txt2.setString("MAX 100 X 100");
  txt2.setPosition(350,60);
  txt2.setCharacterSize(25);

  txt3.setString("WIERSZE:");
  txt3.setPosition(100,100);
  txt3.setCharacterSize(15);

  txt4.setString("KOLUMNY:");
  txt4.setPosition(600,100);
  txt4.setCharacterSize(15);

  sf::RectangleShape field_row,field_col,ready;

  ready.setSize(sf::Vector2f(260,50));
  ready.setFillColor(sf::Color::Red);
  ready.setPosition(sf::Vector2f(280,265));
  ready.setOutlineThickness(1);
  ready.setOutlineColor(sf::Color::Black);

  win.draw(txt1);
  win.draw(txt2);
  win.draw(txt3);
  win.draw(txt4);
  
  
  txt1.setFillColor(sf::Color::Black);
  txt1.setCharacterSize(30);
  txt1.setString(std::to_string(help_row));
  txt1.setCharacterSize(10);
  txt1.setPosition(135,205);
  field.setPosition(110,200);
  win.draw(field);
  win.draw(txt1);

  txt1.setString(std::to_string(help_col));
  txt1.setPosition(635,205);
  field.setPosition(610,200);
  win.draw(field);
  win.draw(txt1);
  
  txt1.setCharacterSize(20);
  field.setPosition(110,180);
  txt1.setString("++");
  txt1.setPosition(120,175);
  win.draw(field);
  win.draw(txt1);
  field.setPosition(110,220);
  txt1.setString("--");
  txt1.setPosition(125,215);
  win.draw(field);
  win.draw(txt1);

  field.setPosition(610,180);
  txt1.setString("++");
  txt1.setPosition(625,175);
  win.draw(field);
  win.draw(txt1);
  field.setPosition(610,220);
  txt1.setString("--");
  txt1.setPosition(625,215);
  win.draw(field);
  win.draw(txt1);
  
  txt1.setString("GOTOWE");
  txt1.setPosition(285,260);
  txt1.setCharacterSize(50);
  txt1.setFillColor(sf::Color::Black);
  win.draw(ready);
  win.draw(txt1);
  txt1.setFillColor(sf::Color::White);

  if(error)
  {
    ready.setPosition(280,380);
    txt2.setString("NIEPRAWIDLOWE DANE");
    txt2.setCharacterSize(18);
    txt2.setPosition(285,385);
    error=false;
    win.draw(ready);
    win.draw(txt2);
  }
 
}


//Wyświetlanie instrukcji
void Begining::display_of_instructions(sf::RenderWindow & win)
{
  sf::RectangleShape agree;
  agree.setSize(sf::Vector2f(200,50));
  agree.setPosition(300,100);
  agree.setFillColor(sf::Color::Red);
  agree.setOutlineThickness(1);
  agree.setOutlineColor(sf::Color::Black);
  txt1.setCharacterSize(25);
  txt1.setPosition(325,110);
  txt1.setString("ROZUMIEM");
  win.draw(agree);
  win.draw(txt1);
  txt1.setFillColor(sf::Color::Black);
  txt1.setCharacterSize(15);
  txt1.setPosition(115,215);
  txt1.setString("1. ABY ODKRYC POLE UZYJ PRAWEGO PRZYCISKU MYSZKI");
  win.draw(txt1);
  txt1.setPosition(115,240);
  txt1.setString("2. ABY UMIESCIC/USUNAC FLAGE UZYJ LEWEGO PRZYCISKU MYSZKI");
  win.draw(txt1);
  txt1.setPosition(115,265);
  txt1.setString("3. NA ODKRYTYM POLU WYSWIETLI SIE ILOSC MIN NA SASIEDNICH POLACH");
  win.draw(txt1);
  txt1.setPosition(115,290);
  txt1.setString("4. PRZEGRASZ JESLI ODSLONISZ POLE Z MINA");
  win.draw(txt1);
  txt1.setPosition(115,315);
  txt1.setString("5. WYGRASZ JESLI ODSLONISZ WSZYSTKIE POLA BEZ MIN");
  win.draw(txt1);
  txt1.setFillColor(sf::Color::White);
}


//-----------------------------
//FUNKCJE OBSŁUGUJĄCE ZDARZENIA
//------------------------------


//FUNKCJA WYWOŁUJĄCA FUNKCJE OBSŁUGUJĄCE ZDARZENIE KLIKNIĘCIA MYSZKĄ W ZALEŻNOŚCI OD ETAPU W KTÓRYM JEST APLIKACJA 
void Begining::mouse_button_pressed(sf::Event event)
{
  if(app_state==HELLO)
  {
    start_game(event);
  }
  else if(app_state==CHOICE_OF_MODE)
  {
    choice_level(event);
  }
  else if(app_state==CHOICE_OF_BOARD)
  {
    choice_board(event);
  }
  else  //app_state==INSTRUCTIONS
  {
     instructions_agree(event);
  }
  
}

//Sprawdzanie czy grcz kliknął w "start"
void Begining::start_game(sf::Event event)
{
   int x=event.mouseButton.x;
   int y=event.mouseButton.y;

   if((x>=200)and(x<=600)and(y>=250)and(y<=350)) app_state=CHOICE_OF_MODE;
}

//Sprawdzanie jaki poziom gry kliknął gracz
void Begining::choice_level(sf::Event event)
{
  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
 
  if((x>=100)and(x<=350)and(y>=250)and(y<=330))
  {
    choosed_mode=EASY;
    app_state=CHOICE_OF_BOARD;
  } 
  else if((x>=300)and(x<=450)and(y>=250)and(y<=330)) 
  {
    choosed_mode=NORMAL;
    app_state=CHOICE_OF_BOARD;
  }
  else if((x>=500)and(x<=650)and(y>=250)and(y<=330)) 
  {
    choosed_mode=HARD;
    app_state=CHOICE_OF_BOARD;
  }
  
}

//Sprawdzanie czy przy wybieraniu planszy kliknięto "gotowe" czy zmianę wielkości
void Begining::choice_board(sf::Event event)
{
  int x=event.mouseButton.x;
  int y=event.mouseButton.y;

  if((x>=280)and(x<=540)and(y>=265)and(y<=315)) ready_was_pressed();
  else
  {
    was_pressed_number(event); 
  }

}

//Sprawdzanie czy kliknięto zmianę wielkości i jeśli tak modyfikacja zmiennej
void Begining::was_pressed_number(sf::Event event)
{
  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
  
  if((x>110)and(x<160)and(y>220)and(y<2400))
  {
    if(help_row!=0) help_row--;
  }
  else if((x>110)and(x<160)and(y>180)and(y<200))
  {
    if(help_row!=100) help_row++;
  }
  else if((x>610)and(x<660)and(y>180)and(y<200))
  {
    if(help_col!=100) help_col++;
  }
  else if((x>610)and(x<660)and(y>220)and(y<240))
  {
    if(help_col!=0) help_col--;
  }
}


//Sprawdzanie czy kliknieto "gotowe" i jeśli tak ustalenie rozmiaru planszy
void Begining::ready_was_pressed()
{
  if((help_col>0)and(help_row>0))
  {
    choosed_col=help_col;
    choosed_row=help_row;
    app_state=INSTRUCTIONS;
  }
  else
  {
    error=true; 
  }
}

//Sprawdza czy kliknieto w "rozumiem"
void Begining::instructions_agree(sf::Event event)
{
   int x=event.mouseButton.x;
   int y=event.mouseButton.y;
   if((x>=300)and(x<=500)and(y>=100)and(y<=150)) end=true;
}


//-------------------------------------
//FUNKCJE ZWRACJĄCE USTALONE INFORMACJE
//------------------------------------

//Wybrany poziom gry
GameMode Begining::get_mode() const
{
  return choosed_mode;
}
//wybrana ilość wierszy
int Begining::get_row_number() const
{
  return choosed_row;
}

//Wybrana ilość kolumn 
int Begining::get_col_number() const
{
  return choosed_col;
}




