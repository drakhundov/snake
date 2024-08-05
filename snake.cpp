#include <iostream>
#include <ctime>

#include <conio.h>

using namespace std;

#include "snake.h"
#include "config.h"

bool gameover;

int score;

Point fruit, snake[MAXSNAKE], _prev, tmp;
Direction dir;

int i, j, k;

void SetUp()
{
	gameover = false;

	score = 0;

	snake[0].x = width / 2;
	snake[0].y = height / 2;

	dir = STOP;

	srand(time(NULL));

	GenerateFruit();
}

void GenerateFruit()
{
	fruit.x = (rand() % width);
	fruit.y = (rand() % height);
}

void Draw()
{
	char ch;

	system("cls");

	for (i = 0; i <= width + 1; ++i)
	{
		cout << border_ch;
	}
	cout << endl;

	for (i = 0; i < height; ++i)
	{
		cout << border_ch;

		for (j = 0; j < width; ++j)
		{
			if (i == fruit.y && j == fruit.x)
			{
				ch = fruit_ch;
			}
			else if (i == snake[0].y && j == snake[0].x)
			{
				ch = snake_ch;
			}
			else
			{
				ch = ' ';

				for (k = 0; k <= score; ++k)
				{
					if (snake[k].x == j && snake[k].y == i)
					{
						ch = tail_ch;
					}
				}
			}

			cout << ch;
		}

		cout << border_ch << endl;
	}

	for (i = 0; i <= width + 1; ++i)
	{
		cout << border_ch;
	}
	cout << endl;

	cout << "Score: " << score;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'w':
			dir = UP;
			break;

		case 'x':
			gameover = true;
			break;
		}
	}
}

void Logic()
{
	_prev = snake[0];
	for (i = 1; i <= score; ++i)
	{
		tmp = snake[i];
		snake[i] = _prev;
		_prev = tmp;
	}

	for (i = 2; i <= score; ++i)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
			gameover = true;
	}

	switch (dir)
	{
	case LEFT:
		--snake[0].x;
		break;
	case RIGHT:
		++snake[0].x;
		break;
	case DOWN:
		++snake[0].y;
		break;
	case UP:
		--snake[0].y;
		break;
	}

	if (snake[0].x == fruit.x && snake[0].y == fruit.y)
	{
		// fruit eaten
		++score;
		GenerateFruit();
	}

	if (snake[0].x >= width)
	{
		snake[0].x = 0;
	}
	else if (snake[0].x < 1)
	{
		snake[0].x = width - 1;
	}
	else if (snake[0].y >= height)
	{
		snake[0].y = 0;
	}
	else if (snake[0].y < 1)
	{
		snake[0].y = height - 1;
	}
}
