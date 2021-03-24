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
  GameState stan_gry;
  int numberOfSteps=0;
  bool czy_na_planszy(int row, int col) const;

public:
  MinesweeperBoard();
  MinesweeperBoard(int width, int height, GameMode mode);

  void debug_display() const;

  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  int CountMines(int row,int col) const;

  bool HasFlag(int row, int col) const;

  void toggleFlag(int row, int col);

  void revealField(int row, int col);

  bool IsRevealed(int row, int col) const;

  GameState getGameState() const;

  char getFieldInfo(int row, int col) const;
};

#endif