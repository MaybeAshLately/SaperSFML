#ifndef ABCDEFGH
#define ABCDEFGH

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};

class MinesweeperBoard
{
  Field board[100][100];    // 100-elementowa tablica, 100-elementowych tablic typu Field 
  int width;                // rzeczywista szerokość planszy
  int height;               // rzeczywista wysokość planszy

  //--------------
  GameMode mode;

public:
  MinesweeperBoard();
  MinesweeperBoard(int width, int height, GameMode mode);

  void debug_display() const;

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  int CountMines(int row,int col) const;
};

#endif