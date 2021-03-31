#ifndef ABCD
#define ABCD

class MSTextController
{
   int width; 
   int height;
   MinesweeperBoard &board;
   MSBoardTextView &board_text;

   public:
   explicit MSTextController(MinesweeperBoard & board, MSBoardTextView & board_text);
   void play();
};

#endif