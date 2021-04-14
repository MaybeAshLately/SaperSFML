#ifndef ABCD
#define ABCD
#include "Array2D.h"

class MSTextController
{
   int width; 
   int height;
   MinesweeperBoard &board;
   MSBoardTextView &board_text;

   void reveal_field();
   void put_flag();
   bool are_flags();
   void remove_flag();

   public:
   explicit MSTextController(MinesweeperBoard & board, MSBoardTextView & board_text);
   void play();
};

#endif