#include "point.h"
#include "direction.h"

#define MAXSNAKE 100

void SetUp();
void Draw();
void Input();
void Logic();
void GenerateFruit();

extern bool gameover;

extern int score;

extern Point fruit, snake[MAXSNAKE],
	_prev, tmp; // to calculate snake movement

extern Direction dir;

extern int i, j, k; // iterators
