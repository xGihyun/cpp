#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 90

using namespace std;

HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int notePos[4] = {44, 49, 54, 59};
int notePos2[2] = {54, 59};
int notePos3[2] = {44, 49};
int noteX;
int noteY = 0;
int note2X;
int note2Y = 0;
int note3X;
int note3Y = 0;
int note4X;
int note4Y = 0;
int combo = 0;
int score = 0;
int keyX = 44;
int keyY = 22;
int key2X = 49;
int key2Y = 22;
int key3X = 54;
int key3Y = 22;
int key4X = 59;
int key4Y = 22;
int color = 8;
int color2 = 1;
int color3 = 1;
int color4 = 8;
bool fall = false;

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
	char brdr = 186;
	for(int i=0; i<SCREEN_HEIGHT; i++){
		for(int j=25; j<27; j++){
			gotoxy(17+j,i); cout<<brdr; //LEFT BORDER
			gotoxy(WIN_WIDTH-j,i); cout<<brdr; //RIGHT BORDER
		}
	} 

}

void drawNote(){
    char note = 219;
        gotoxy(noteX, noteY);    cout<<"     ";
        gotoxy(noteX, noteY + 1);cout<<"     ";
        gotoxy(noteX, noteY + 2);
            for (int i = 0; i < 5; i++){
                 cout<<note;
        }

}

void eraseNote(){
        gotoxy(noteX, noteY);    cout<<"     ";
        gotoxy(noteX, noteY + 1);cout<<"     ";
        gotoxy(noteX, noteY + 2);cout<<"     ";

}

void drawNote2(){
    char note = 219;
        gotoxy(note2X, note2Y);    cout<<"     ";
        gotoxy(note2X, note2Y + 1);cout<<"     ";
        gotoxy(note2X, note2Y + 2);
            for (int i = 0; i < 5; i++){
                 cout<<note;
        }

}

void eraseNote2(){
        gotoxy(note2X, note2Y);    cout<<"     ";
        gotoxy(note2X, note2Y + 1);cout<<"     ";
        gotoxy(note2X, note2Y + 2);cout<<"     ";

}

void drawNote3(){
    char note = 219;
        gotoxy(note3X, note3Y);    cout<<"     ";
        gotoxy(note3X, note3Y + 1);cout<<"     ";
        gotoxy(note3X, note3Y + 2);
            for (int i = 0; i < 5; i++){
                 cout<<note;
        }

}

void eraseNote3(){
        gotoxy(note3X, note3Y);    cout<<"     ";
        gotoxy(note3X, note3Y + 1);cout<<"     ";
        gotoxy(note3X, note3Y + 2);cout<<"     ";

}

void drawNote4(){
    char note = 219;
        gotoxy(note4X, note4Y);    cout<<"     ";
        gotoxy(note4X, note4Y + 1);cout<<"     ";
        gotoxy(note4X, note4Y + 2);
            for (int i = 0; i < 5; i++){
                 cout<<note;
        }

}

void eraseNote4(){
        gotoxy(note4X, note4Y);    cout<<"     ";
        gotoxy(note4X, note4Y + 1);cout<<"     ";
        gotoxy(note4X, note4Y + 2);cout<<"     ";

}

void drawKey(){
    char key = 178;
	SetConsoleTextAttribute (h,color);
        gotoxy(keyX, keyY);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(keyX, keyY+1);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(keyX, keyY+2);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(keyX, keyY+3);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
		
    SetConsoleTextAttribute (h,15);
}
void drawKey2(){
    char key = 178;
	SetConsoleTextAttribute (h,color2);
		gotoxy(key2X, key2Y);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key2X, key2Y+1);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key2X, key2Y+2);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key2X, key2Y+3);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
    
    SetConsoleTextAttribute (h,15);
}
void drawKey3(){
    char key = 178;
	SetConsoleTextAttribute (h,color3);
		gotoxy(key3X, key3Y);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key3X, key3Y+1);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key3X, key3Y+2);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key3X, key3Y+3);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
    
    SetConsoleTextAttribute (h,15);
}
void drawKey4(){
    char key = 178;
	SetConsoleTextAttribute (h,color4);
		gotoxy(key4X, key4Y);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key4X, key4Y+1);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key4X, key4Y+2);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
        gotoxy(key4X, key4Y+3);
            for (int i = 0; i < 5; i++){
                 cout<<key;
            }
    SetConsoleTextAttribute (h,15);
}

void updateCombo(){
	gotoxy(WIN_WIDTH - 11, 5);cout<<"Combo: "<<combo<<"      "<<endl;
}

void updateScore(){
	gotoxy(40, 28);cout<<"Score: "<<score<<endl;
}

void noteFall(){
	noteY++;
	if (noteY == 24){

		eraseNote();
		noteY = 0;
		noteX = notePos[rand()%4]; //RANDOMIZE NOTE'S POSITION
		combo = combo - combo;
        updateCombo();
	}
    
}

void noteFall2(){     
    note2Y++;
    if (note2Y == 24){
        
		eraseNote2();
		note2Y = 0;
        note2X = notePos[rand()%2]; //RANDOMIZE NOTE'S POSITION
		combo = combo - combo;
        updateCombo();
	}
    
}

void hitNote()
{
    if (kbhit())
    {
        switch(getch())
        {
            case 'd':
            case 'D':
                if (color < 14)
                {
                    color += 7;
                    if (noteX == keyX && noteY + 2 == keyY || noteY + 1 == keyY || noteY == keyY || noteY + 2 == keyY - 1 || noteY + 1 == keyY - 1 || noteY == keyY - 1)
                    {
                        
                            eraseNote();
                        noteY = 0;
                        noteX = notePos[rand()%4];
                        combo++;
                        updateCombo();
                        score+=10;
                        updateScore();
                            if (combo > 10){
                                score+=100;
                                updateScore();
                            }
                            if (combo > 15){
                                score+=1000;
                                updateScore();
                            } 
                        
                            
                    }
                    if (note2X == keyX && note2Y + 2 == keyY || note2Y + 1 == keyY || note2Y == keyY || note2Y + 2 == keyY - 1 || note2Y + 1 == keyY - 1 || note2Y == keyY - 1)
                    {
                            eraseNote2();
                        note2Y = 0;
                        note2X = notePos[rand()%2];
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
            break;

            case 'f':
            case 'F':
                if (color2 <11)
                {
                    color2 += 10;
                    if (noteX == key2X && noteY + 2 == key2Y || noteY + 1 == key2Y || noteY == key2Y || noteY + 2 == key2Y - 1 || noteY + 1 == key2Y - 1 || noteY == key2Y - 1)
                    {
                        
                            eraseNote();
                        noteY = 0;
                        noteX = notePos[rand()%4];
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
                    if (note2X == key2X && note2Y + 2 == key2Y || note2Y + 1 == key2Y || note2Y == key2Y || note2Y + 2 == key2Y - 1 || note2Y + 1 == key2Y - 1 || note2Y == key2Y - 1)
                    {
                            eraseNote2();
                        note2Y = 0;
                        note2X = notePos[rand()%2];
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
                    
            break;

            case 'j':
            case 'J':
                if (color3 <11)
                {
                    color3 += 10;
                    if (noteX == key3X && noteY + 2 == key3Y || noteY + 1 == key3Y || noteY == key3Y || noteY + 2 == key3Y - 1 || noteY + 1 == key3Y - 1 || noteY == key3Y - 1)
                    {
                        
                            eraseNote();
                        noteY = 0;
                        noteX = notePos[rand()%4];
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
                    if (note2X == key3X && note2Y + 2 == key3Y || note2Y + 1 == key3Y || note2Y == key3Y || note2Y + 2 == key3Y - 1 || note2Y + 1 == key3Y - 1 || note2Y == key3Y - 1)
                    {
                            eraseNote2();
                        note2Y = 0;
                        note2X = notePos[rand()%2];
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
                    
            break;

            case 'k':
            case 'K':
                if (color4 <14)
                {
                    color4 += 7;
                    if (noteX == key4X && noteY + 2 == key4Y || noteY + 1 == key4Y || noteY == key4Y || noteY + 2 == key4Y - 1 || noteY + 1 == key4Y - 1 || noteY == key4Y - 1)
                    {
                        
                        
                            eraseNote();
                        noteY = 0;
                        noteX = notePos[rand()%4];
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
                    if (note2X == key4X && note2Y + 2 == key4Y || note2Y + 1 == key4Y || note2Y == key4Y || note2Y + 2 == key4Y - 1 || note2Y + 1 == key4Y - 1 || note2Y == key4Y - 1)
                    {
                            eraseNote2();
                        note2Y = 0;
                        note2X = notePos[rand()%2];
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
            default:
            break;       
        }
            
    }
    else if (!kbhit()){
            color = 8;
            color2 = 1;
            color3 = 1;
            color4 = 8;
    }

}

void instructions(){
	
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Hit notes using 'D', 'F', 'J', or 'K'. ";
	cout<<"\n Press 'Escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}

void play(){
	
	combo = 0;
    score = 0;
    noteY = 0;
    noteX = notePos[rand()%4];
    note2Y = 0;
    note2X = notePos[rand()%2];
    

	system("cls"); 
	drawBorder(); 
	updateCombo();
	updateScore();

	gotoxy(WIN_WIDTH - 10, 2);cout<<"MANIA!";
	gotoxy(51, 5);cout<<"START!";
	getch();
	gotoxy(51, 5);cout<<"      ";
	
	while(1){
		drawKey();
        drawKey2();
        drawKey3();
        drawKey4();
		hitNote();
        drawNote();
        drawNote2();
        Sleep(5);
		noteFall();
        noteFall2();
        
	}
	
}

int main(){
    setcursor(0,0); 
	srand( (unsigned)time(NULL)); 
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |         MANIA!         | "; 
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
