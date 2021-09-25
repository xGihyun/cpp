#include<iostream>
#include<conio.h>
#include<time.h>
#include<windows.h>

using namespace std;

int cubeY = 0;
int cubeX = 2;
int spikeX = 0;
int spikePos = 74;
int gameover = 0;

enum eDirection {STOP = 0, LEFT, RIGHT};
eDirection dir;

void gotoxy(int x, int y){
    COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*void score(){
    
    system("cls"); 
    gameover = 0;
    gotoxy(3, 2); cout<<"SCORE: ";
        
}*/

void floor(){ //FLOOR
    char f = 219;
    for (int i = 0; i < 79; i++){
        gotoxy(1+i, 1); cout<<f;
    	gotoxy(1+i, 25); cout<<f;
        }
}

void drawCube(){ //CUBE DRAWING
    char cube = 219;
    gotoxy(cubeX, 19 - cubeY);cout<<"        ";
    gotoxy(cubeX, 20 - cubeY);cout<<"        ";
    gotoxy(cubeX, 21 - cubeY);
        for (int i = 0; i < 8; i++){
            cout<<cube;
        }
    gotoxy(cubeX, 22 - cubeY);
        for (int i = 0; i < 8; i++){
            cout<<cube;
        }
    gotoxy(cubeX, 23 - cubeY);
        for (int i = 0; i < 8; i++){
            cout<<cube;
        }
    gotoxy(cubeX, 24 - cubeY);
        for (int i = 0; i < 8; i++){
            cout<<cube;
        }
    
}

void eraseCube(){
    gotoxy(cubeX - 1, 20 - cubeY);cout<<" ";
    gotoxy(cubeX - 1, 21 - cubeY);cout<<" ";
    gotoxy(cubeX - 1, 22 - cubeY);cout<<" ";
    gotoxy(cubeX - 1, 23 - cubeY);cout<<" ";
    gotoxy(cubeX - 1, 24 - cubeY);cout<<" ";
    gotoxy(cubeX + 8, 20 - cubeY);cout<<" ";
    gotoxy(cubeX + 8, 21 - cubeY);cout<<" ";
    gotoxy(cubeX + 8, 22 - cubeY);cout<<" ";
    gotoxy(cubeX + 8, 23 - cubeY);cout<<" ";
    gotoxy(cubeX + 8, 24 - cubeY);cout<<" ";
}

void cubeJump(int jump = 0){
    if (jump == 0){
        cubeY = 0;
    }
    else if (jump == 2){
        cubeY--;
    }
    else {
        cubeY++;
    }

    char c = 219;
    
            gotoxy(cubeX - 1, 25 - cubeY);
            if (jump == 0){
                for(int i =0; i < 9; i++){
                    cout<<c;
                }
            } 
            else{
            cout<<"           ";
            }
    Sleep(5);
}

void logic(){
    switch(dir){
        case LEFT:
			if( cubeX > 1 ){
				cubeX--;
                eraseCube();
            }
            break;
        
		case RIGHT:
            if( cubeX < 72 ){
				cubeX++;
                eraseCube();
            }
            break;
        
    }
    //SPIKES
    char s = 219;

    gotoxy(spikePos + 3 - spikeX, 22);
        for(int i = 0; i < 2; i++){
            cout<<s;
        }
    gotoxy(spikePos + 2 - spikeX, 23);
        for(int i = 0; i < 4; i++){
            cout<<s;
        }
    gotoxy(spikePos + 1 - spikeX, 24);
        for(int i = 0; i < 6; i++){
            cout<<s;
        }
    gotoxy(spikePos + 5 - spikeX, 22);
        for(int i = 0; i < 2; i++){
            cout<<" ";
        }
    gotoxy(spikePos + 6 - spikeX, 23);
        for(int i = 0; i < 4; i++){
            cout<<" ";
        }
    gotoxy(spikePos + 7 - spikeX, 24);
        for(int i = 0; i < 6; i++){
            cout<<" ";
        }

    spikeX++;

    if (spikeX == 73) {
        spikeX = 0;
        
    }

}

void input(){
    
    if (kbhit())
	{
		switch(getch())
		{
			case 'a':
            case 'A':
				dir = LEFT;
				break;

			case 'd':
            case 'D':
				dir = RIGHT;
				break;
            
            case 32:
                int i;
                while(i < 20) {
                        drawCube();
                        eraseCube();
                        logic();
                        cubeJump(1);
                
                        i++;
    
                        }
                    while(i > 9) {
                        drawCube();
                        eraseCube();
                        logic();
                        cubeJump(2);
                
                        i--;
        	            }
                default:
                break;
	    }
    }
}

void play(){
    drawCube();
    system("cls");
    floor();

    while(1){
			drawCube();
            eraseCube();
            input();
            logic();
            cubeJump();
            
    }
    Sleep(5);  
}

int main() {
    
    do{
		system("cls");
        {
        HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute (h,4 | FOREGROUND_INTENSITY);
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |";
        gotoxy(36,6); cout<<"| ";
		gotoxy(10,7); cout<<" -------------------------- ";
        SetConsoleTextAttribute (h,15 | FOREGROUND_INTENSITY);
        gotoxy(20,6); cout<<"CUBE JUMP";  
        }
        HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute (h,15 | FOREGROUND_INTENSITY);
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if(op=='1') play();
		
		
	}while(1);
    
	return 0;
}