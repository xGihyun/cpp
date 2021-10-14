#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

int playerX = 40, playerY = 10;
int enemyX = 70, enemyY = 10;
bool enemyAtk;
bool playerAtk;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);

enum eDirection {STOP = 0, LEFT, RIGHT, eLEFT, eRIGHT};
eDirection dir;

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void drawPlayer()
{
    char p = 219;
    
		SetConsoleTextAttribute (h,15);	//PLAYER
			gotoxy(playerX - 1, playerY + 2);
				for(int i = 0; i<7; i++){
					cout<<p;
				}

			gotoxy(playerX - 1, playerY + 3);
				for(int i = 0; i<7; i++){
					cout<<p;
				}
			
			gotoxy(playerX - 1, playerY + 4);
				for(int i = 0; i<7; i++){
					cout<<p;
				}

			SetConsoleTextAttribute (h,0); //EYES
				gotoxy(playerX + 2, playerY + 3);cout<<p;
				gotoxy(playerX + 4, playerY + 3);cout<<p;
			SetConsoleTextAttribute (h,15);

            gotoxy(playerX - 2, playerY + 2);cout<<" ";
			gotoxy(playerX + 6, playerY + 2);cout<<" ";
			gotoxy(playerX - 2, playerY + 3);cout<<" ";
			gotoxy(playerX + 6, playerY + 3);cout<<" ";
			gotoxy(playerX - 2, playerY + 4);cout<<" ";
			gotoxy(playerX + 6, playerY + 4);cout<<" ";
}

void drawEnemy()
{
    char p = 219;
    
		SetConsoleTextAttribute (h,4);	//ENEMY
			gotoxy(enemyX - 1, enemyY + 2);
				for(int i = 0; i<7; i++){
					cout<<p;
				}

			gotoxy(enemyX - 1, enemyY + 3);
				for(int i = 0; i<7; i++){
					cout<<p;
				}
			
			gotoxy(enemyX - 1, enemyY + 4);
				for(int i = 0; i<7; i++){
					cout<<p;
				}

			SetConsoleTextAttribute (h,0); //EYES
				gotoxy(enemyX, enemyY + 3);cout<<p;
				gotoxy(enemyX + 2, enemyY + 3);cout<<p;
			SetConsoleTextAttribute (h,15);

            gotoxy(enemyX - 2, enemyY + 2);cout<<" ";
			gotoxy(enemyX + 6, enemyY + 2);cout<<" ";
			gotoxy(enemyX - 2, enemyY + 3);cout<<" ";
			gotoxy(enemyX + 6, enemyY + 3);cout<<" ";
			gotoxy(enemyX - 2, enemyY + 4);cout<<" ";
			gotoxy(enemyX + 6, enemyY + 4);cout<<" ";
}

void enemyAttack()
{
        if(enemyAtk = true)
        {
            gotoxy(46, 9);cout<<"                               ";
            gotoxy(49, 9);cout<<"                               ";
            gotoxy(49, 9);cout<<"The enemy attacks!";

            if(enemyX > playerX + 7)
            {
                dir = eLEFT;
            }
            else{
                dir = eRIGHT;
            }
            
        }
}

void logic()
{
    bool con, econ;
    con = false; //CONDITION FOR PLAYER ATK ANIMATION
    econ = false; //CONDITION FOR ENEMY ATK ANIMATION

    if(kbhit())
    {
        gotoxy(43, 5); cout<<"Do you wish to Fight(F) or Run(R)?";

            switch(getch())
            {
                case 'F':
                case 'f':
                    gotoxy(43, 5); cout<<"                                  ";
                    gotoxy(47, 5); cout<<"The battle has begun!";
                    gotoxy(49, 7); cout<<"What will you do?";

                    gotoxy(50, 20); cout<<"A to Attack";
                    gotoxy(50, 21); cout<<"S to Special Attack";
                    gotoxy(50, 22); cout<<"H to Heal";
                    gotoxy(50, 23); cout<<"R to Run Away";

                        switch(getch())
                        {
                            case 'A':
                            case 'a':
                                gotoxy(46, 9);cout<<"You have chosen to attack!";
                                    dir = RIGHT;
                            break;

                            case 'S':
                            case 's':
                                    dir = RIGHT;
                                gotoxy(43, 9);cout<<"You have chosen to special attack!";

                            break;
                        }

                    break;

                case 'R':
                case 'r':
                    gotoxy(40, 5); cout<<"                                  ";
                    gotoxy(40, 5); cout << "You have decided to run!";
                    break;
            }
    }

    switch(dir)
    {
        case RIGHT:
        playerAtk = true;
        con = true;
            if(playerX < enemyX - 7)
            {
                playerX++;
            }
            else{
                dir = LEFT;
            }
                 
            break;

        case LEFT:
        con = false;
        enemyAtk = false;
            if(playerX > 40)
            {
                playerX--;
                if(playerX == 40)
                {
                    enemyAtk = true;
                    enemyAttack();
                }
                
            }
            break;
        
        case eLEFT:
            econ = true;
                enemyX--;
                if(enemyX < playerX + 7)
                {
                    dir = eRIGHT;
                }
                
            break;

        case eRIGHT:
            playerAtk = false;
            econ = false;
                if(enemyX < 71)
                {
                    enemyX++;
                }
                
            break;
                
    }

}

void play()
{
    system("cls");

    while(1)
    {
        drawPlayer();
        drawEnemy();
        logic();

        Sleep(5);
    }
}

int main()
{
    setcursor(0,0);
    play();

    return 0;
}

