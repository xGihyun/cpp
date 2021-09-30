#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 90

using namespace std; 
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int fruitY = 0;
int fruitX = 24;
int fruitPos[8] = {24, 29, 34, 39, 44, 49, 54, 59};
int fruitColP[7] = {4, 5, 12, 13, 14, 15}; //COLOR RANDOMIZER
int fruitCol = fruitColP[rand()%6]; //COLOR
int playerX = -1 + WIN_WIDTH/2;;
int playerY = 22;	
int combo = 0;
int score = 0;
bool sprint;


enum eDirection {STOP = 0, LEFT, RIGHT, LEFT2, RIGHT2};
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
void drawBorder(){  
	char brdr = 219;
	for(int i=0; i<SCREEN_HEIGHT; i++){
		for(int j=0; j<22; j++){
			gotoxy(2+j,i); cout<<brdr; //left border
			gotoxy(WIN_WIDTH-j,i); cout<<brdr; //right border
		}
	} 
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(SCREEN_WIDTH,i); cout<<brdr;
	} 
}

void drawPlayer(){
	char p = 219; //ASCII STUFF
	char s = 220;
	char u = 223;

	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h,9);
		gotoxy(playerX, playerY + 1);    
			for(int i = 0; i<5; i++){
				cout<<s;
			}
		gotoxy(playerX - 1, playerY + 1);cout<<p;
		gotoxy(playerX + 5, playerY + 1);cout<<p;
		gotoxy(playerX - 3, playerY + 1);cout<<"  ";
		gotoxy(playerX + 7, playerY + 1);cout<<"  ";

	SetConsoleTextAttribute (h,15);
		gotoxy(playerX, playerY + 2);
			for(int i = 0; i<5; i++){
				cout<<p;
			} 
    	gotoxy(playerX+1, playerY + 3);
			for(int i = 0; i<3; i++){
				cout<<u;
			}
		gotoxy(playerX, playerY + 3);  cout<<" ";
		gotoxy(playerX+4, playerY + 3);cout<<" ";
}
void erasePlayer(){
	
	gotoxy(playerX, playerY);    cout<<"       ";
	gotoxy(playerX, playerY + 1);cout<<"       ";
    gotoxy(playerX, playerY + 2);cout<<"       ";
	gotoxy(playerX, playerY + 3);cout<<"       ";
}

void movePlayer(){
	
		if(kbhit()){

			switch(getch()){
				case 'a':
				case 'A':
					dir = LEFT;
					break;
				case 'd':
				case 'D':
					dir = RIGHT;
					break;
				case 'k':
				case 'K':
					dir = LEFT2;
					break;
				case 'l':
				case 'L':
					dir = RIGHT2;
					default:
					break;
			}
		}
		
			switch(dir){
				
				case LEFT:
					playerX--;
					break;
				case RIGHT:
					playerX++;
					break;
				case LEFT2:
					playerX-=2;
					break;
				case RIGHT2:
					playerX+=2;
					break;
			}

			/*char ch = getch();
			if( ch=='a' || ch=='A' ){ //GO LEFT
				if( playerX > 25 )
					playerX -= move;
			}
			if( ch=='d' || ch=='D' ){ //GO RIGHT
				if( playerX < 64 )
					playerX += move;
						
			} */
	
}

void drawFruit(){
	char f = 219;
	char g = 177;
	char d = 223;
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute (h,10);
		
		gotoxy(fruitX, fruitY - 1);cout<<"     ";
		gotoxy(fruitX, fruitY);cout<<" ";
		gotoxy(fruitX+4, fruitY);cout<<" ";
		gotoxy(fruitX+1, fruitY);    
			for(int i = 0; i<3; i++){
				cout<<g;
			} 
	SetConsoleTextAttribute (h,fruitCol);
		gotoxy(fruitX, fruitY+1);  
			for(int i = 0; i<5; i++){
				cout<<f;
			}
		gotoxy(fruitX+1, fruitY+2);
			for(int i = 0; i<3; i++){
				cout<<f;
			}
		gotoxy(fruitX, fruitY+2);cout<<d;
		gotoxy(fruitX+4, fruitY+2);cout<<d;
	SetConsoleTextAttribute (h,15);
}

void eraseFruit(){
		
		gotoxy(fruitX, fruitY - 1);cout<<"     "; 
		gotoxy(fruitX, fruitY);    cout<<"     ";  
		gotoxy(fruitX, fruitY+1);  cout<<"     "; 
		gotoxy(fruitX, fruitY+2);  cout<<"     "; 
}

void fruitfall(){
	fruitY++;
	if (fruitY == 25){
		eraseFruit();
		fruitY = 0;
		fruitX = 25 + rand()%45; //RANDOMIZE FRUIT'S POSITION
		fruitCol = fruitColP[rand()%6];
	}
	
}

void updateCombo(){
	gotoxy(WIN_WIDTH + 7, 5);cout<<"Combo: "<<combo<<"      "<<endl;
}

void updateScore(){
	gotoxy(40, 28);cout<<"Score: "<<score<<endl;
}

void fruitCatch(){ //COLLISION || CATCHING THE FRUIT
	if( fruitY == playerY - 1)
	{
		if (fruitX == playerX-5 || fruitX == playerX-4 || fruitX == playerX-3 || fruitX == playerX-2 || fruitX == playerX-1 || fruitX == playerX || fruitX == playerX+1 || fruitX == playerX+2 || fruitX == playerX+3 || fruitX == playerX+4 || fruitX == playerX+5)
		{
		eraseFruit();
		fruitY = 0;
		fruitX = fruitPos[rand()%8];
		fruitCol = fruitColP[rand()%6];
		combo++;
		updateCombo();
		score+=10;
		updateScore();
			if (combo > 10){
				score+=100;
				updateScore();
				if (combo > 15){
					score+=1000;
					updateScore();
				}
			}
		}
	}
	if (fruitY > playerY + 1){
		combo = combo - combo;
		updateCombo();
	}
}

/*void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
}*/

void instructions(){
	
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Catch Fruits by moving left or right. ";
	cout<<"\n\n Press 'A' to move left";
	cout<<"\n Press 'D' to move right";
	cout<<"\n Press 'Escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}

void play(){
	playerX = -1 + WIN_WIDTH/2;
	combo = 0;

	system("cls"); 
	
	updateCombo();
	updateScore();

	gotoxy(WIN_WIDTH + 7, 2);cout<<"CATCH!";
	gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
	gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
	gotoxy(WIN_WIDTH + 7, 13);cout<<"-------- ";
	gotoxy(WIN_WIDTH + 2, 14);cout<<" A Key - Left";
	gotoxy(WIN_WIDTH + 2, 15);cout<<" D Key - Right"; 
	
	gotoxy(35, 5);cout<<"Press any key to start";
	getch();
	gotoxy(35, 5);cout<<"                      ";
	
	while(1){
		movePlayer();
		drawPlayer();
		drawFruit();
		fruitCatch();
		Sleep(15);
		fruitfall();
		erasePlayer();
	}
	
}

int main()
{
	setcursor(0,0); 
	srand( (unsigned)time(NULL)); 
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |         CATCH!         | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') play();
		else if( op=='2') instructions();
		else if( op=='3') exit(0);
		
	}while(1);
	
	return 0;
}