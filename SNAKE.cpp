#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup ()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Drawborder ()
{
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	char border = 219;
	char fruit = 229;
	system("cls");
	for (int i = 0; i < width + 2; i++)
	{
		SetConsoleTextAttribute (h,2);
		cout << border;
		SetConsoleTextAttribute (h,15);
	}
	cout << endl;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{	
			if (j == 0){
				SetConsoleTextAttribute (h,2);
				cout << border;
				SetConsoleTextAttribute (h,15);
			}
			if (i == y && j == x){
				SetConsoleTextAttribute (h,3 | FOREGROUND_INTENSITY);
				cout << "O";
				SetConsoleTextAttribute (h,15);
			}
			else if (i == fruitY && j == fruitX){
				SetConsoleTextAttribute (h,4 | FOREGROUND_INTENSITY);
				cout << fruit;
				SetConsoleTextAttribute (h,15);
			}
			else
			{
				bool print = false;

				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						SetConsoleTextAttribute (h,3 | FOREGROUND_INTENSITY);
						cout << "o";
						print = true;
						SetConsoleTextAttribute (h,15);
					}
				}
				if (!print)
					cout << " ";
			}
				
				
			if (j == width - 1){
				SetConsoleTextAttribute (h,2);
				cout << border;
				SetConsoleTextAttribute (h,15);
		}
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++){
		SetConsoleTextAttribute (h,2);
		cout << border;
		SetConsoleTextAttribute (h,15);
	}
	cout << endl;
	cout << "\nSCORE: " << score << endl;
	
}
void Input ()
{
	if (_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
			case 'A':
				dir = LEFT;
				break;
			case 'D':
				dir = RIGHT;
				break;
			case 'W':
				dir = UP;
				break;
			case 'S':
				dir = DOWN;
				break;
			case 'X':
				gameOver = true;
				break;
		}
	}
}

void gameover()
{
	
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<< "\t\tPress any key to go back.";
	getch();
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	nTail = 0;
	score = 0;
}

void Logic ()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prevX2, prevY2;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prevX2 = tailX[i];
		prevY2 = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prevX2;
		prevY = prevY2;
	}
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
	}
	if (x > width || x < 0 || y > height || y < 0)
		gameover();
	for (int i = 0; i < nTail; i++)
	if (tailX[i] == x && tailY[i] == y){
		gameover();
	}
	if (x == fruitX && y == fruitY)
	{
		score += 1;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

int main ()
{
	Setup();
	while (!gameOver)
	{
		Drawborder();
		Input();
		Logic();
		Sleep(10);
	}
	return 0;
}
