#include <iostream>
using namespace std;

#include "snake.h"
#include "conio.h"

int main()
{
	SetUp();

	while (!gameover)
	{
		Draw();
		Input();
		Logic();
	}

	return 0;
}
