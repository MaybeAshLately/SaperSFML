#ifndef ABC
#define ABC
#include "Array2D.h"

class MSBoardTextView
{
MinesweeperBoard &board_text; 
int width;
int height;
public:

explicit MSBoardTextView(MinesweeperBoard & board);

void display() const;

};

#endif