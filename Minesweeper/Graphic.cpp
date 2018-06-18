#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "Game.h"
#include "Graphic.h"
using namespace std;


void atvertvisu(Game spele){


 int xsize = spele.getx();
    int ysize = spele.gety();
    int bombcount = spele.getbomb();
    string lvliz = spele.lvl;
    Game tmpgame(spele.getx(),spele.gety());









        system("cls");

        HANDLE hStdout;
        COORD destCoord;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        int corx = 0;
        int cory = 0;

        int mx;
        int my;

        SetConsoleCursorPosition(hStdout,destCoord);

        for (int i = 0; i<xsize;i++){
            for(int j = 0; j<ysize;j++){
                    destCoord.X = corx;
                    destCoord.Y = cory;
                    SetConsoleCursorPosition(hStdout,destCoord);
                    cout<<"+---";

                    cory = cory +1;
                    destCoord.X = corx;
                    destCoord.Y = cory;
                    SetConsoleCursorPosition(hStdout,destCoord);
                    cout<<"|";


                        if(spele.gettable(i,j)!= '*'){
                            if(spele.getplayer(i,j) == 'P'){
                                SetConsoleTextAttribute(hStdout, (WORD) ((0 << 4) | 4));
                                cout<<" P ";
                                SetConsoleTextAttribute(hStdout, (WORD) ((0 << 4) | 15));
                            }else{
                                color(spele.gettable(i,j),0);
                            }
                        }else{

                            if(spele.getplayer(i,j) == 'P'){
                                SetConsoleTextAttribute(hStdout, (WORD) ((0 << 4) | 2));
                                cout<<" P ";
                                SetConsoleTextAttribute(hStdout, (WORD) ((0 << 4) | 15));

                            }else{
                                SetConsoleTextAttribute(hStdout, (WORD) ((0 << 4) | 4));
                                cout<<" * ";
                                SetConsoleTextAttribute(hStdout, (WORD) ((0 << 4) | 15));
                            }

                        }







                    cory = cory +1;
                    destCoord.X = corx;
                    destCoord.Y = cory;
                    SetConsoleCursorPosition(hStdout,destCoord);


                corx = corx +4;
                destCoord.X = corx;
                cory = cory - 2;
                SetConsoleCursorPosition(hStdout,destCoord);

            }
             mx = corx;
             my = cory;
        cory = cory+2;
        corx = 0;



    }

    destCoord.X = corx;
    destCoord.Y = cory;
    SetConsoleCursorPosition(hStdout,destCoord);

    int i = 0;
    while(i<mx)
    {
        cout<<"+---";
        i= i+4;
    }
    cout<<"+";
    i = 0;
    while(i<my+2){
            destCoord.X=mx;
            destCoord.Y= i;
            SetConsoleCursorPosition(hStdout,destCoord);
        cout<<"+";
            destCoord.Y= i+1;
            SetConsoleCursorPosition(hStdout,destCoord);
        cout<<"|";
        i=i+2;
    }




    char a;
    a = getch();



}


void color(char cell,int t){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(cell == '-'){

            if(t == 8){
                SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 15));
            }
        cout<<"   ";
    }else{

        switch(cell){

           case'1': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 1));break;
           case'2': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 2));break;
           case'3': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 4));break;
           case'4': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 3));break;
           case'5': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 5));break;
           case'6': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 6));break;
           case'7': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 7));break;
           case'8': SetConsoleTextAttribute(hConsole, (WORD) ((t << 4) | 9));break;


            }
        cout<<" "<<cell<<" ";
    }

    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
}

int cursorx;
int cursory;

void startcursor(){

    cursorx = 0;
    cursory = 0;

}


void cursorgraphic(int i,int j,Game spele){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD destCoord;

    destCoord.X = (cursory*4)+1;
    destCoord.Y = (cursorx*2)+1;

    SetConsoleCursorPosition(hConsole,destCoord);
    SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
    if(spele.getplayer(cursorx,cursory) == 'P'){

        cout<<" P ";

    }

    if(spele.getplayer(cursorx,cursory) == '-'){

        cout<<" x ";

    }

    if(spele.getplayer(cursorx,cursory) == NULL){

        color(spele.gettable(cursorx,cursory),0);

    }

    destCoord.X = (j*4)+1;
    destCoord.Y = (i*2)+1;

    SetConsoleCursorPosition(hConsole,destCoord);

    if(spele.getplayer(i,j) == 'P'){
        SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 15));
        cout<<" P ";
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
    }

    if(spele.getplayer(i,j) == '-'){
        SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 15));
        cout<<" x ";
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
    }

    if(spele.getplayer(i,j) == NULL){

        color(spele.gettable(i,j),8);

    }






    cursorx = i;
    cursory = j;


}




void Graphic(Game spele){
    int xsize = spele.getx();
    int ysize = spele.gety();
    int bombcount = spele.getbomb();
    string lvliz = spele.lvl;
    Game tmpgame(spele.getx(),spele.gety());









        system("cls");

        HANDLE hStdout;
        COORD destCoord;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
        int corx = 0;
        int cory = 0;

        int mx;
        int my;

        SetConsoleCursorPosition(hStdout,destCoord);

        for (int i = 0; i<xsize;i++){
            for(int j = 0; j<ysize;j++){
                    destCoord.X = corx;
                    destCoord.Y = cory;
                    SetConsoleCursorPosition(hStdout,destCoord);
                    cout<<"+---";

                    cory = cory +1;
                    destCoord.X = corx;
                    destCoord.Y = cory;
                    SetConsoleCursorPosition(hStdout,destCoord);
                    cout<<"|";


                if(spele.getplayer(i,j) != '-' && spele.getplayer(i,j) != 'P'){


                        color(spele.gettable(i,j),0);



                }else{

                      if(spele.getplayer(i,j) == 'P'){

                            cout <<" P ";

                        }else{
                            cout<<" x ";
                        }
                    //}
                }


                    cory = cory +1;
                    destCoord.X = corx;
                    destCoord.Y = cory;
                    SetConsoleCursorPosition(hStdout,destCoord);


                corx = corx +4;
                destCoord.X = corx;
                cory = cory - 2;
                SetConsoleCursorPosition(hStdout,destCoord);

            }
             mx = corx;
             my = cory;
        cory = cory+2;
        corx = 0;



    }

    destCoord.X = corx;
    destCoord.Y = cory;
    SetConsoleCursorPosition(hStdout,destCoord);

    int i = 0;
    while(i<mx)
    {
        cout<<"+---";
        i= i+4;
    }
    cout<<"+";
    i = 0;
    while(i<my+2){
            destCoord.X=mx;
            destCoord.Y= i;
            SetConsoleCursorPosition(hStdout,destCoord);
        cout<<"+";
            destCoord.Y= i+1;
            SetConsoleCursorPosition(hStdout,destCoord);
        cout<<"|";
        i=i+2;
    }


}



void cursoroff(){
    HANDLE hStdout;
    CONSOLE_CURSOR_INFO cursorinfo;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdout ,&cursorinfo);
    cursorinfo.bVisible = false;
    SetConsoleCursorInfo(hStdout ,&cursorinfo);

}


void cursoron(){
    HANDLE hStdout;
    CONSOLE_CURSOR_INFO cursorinfo;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdout ,&cursorinfo);
    cursorinfo.bVisible = true;
    SetConsoleCursorInfo(hStdout ,&cursorinfo);

}


void fullscreen(){

    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxWindow = GetLargestConsoleWindowSize(out_handle);
    SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
    SMALL_RECT minWindow = { 0, 0, 0, 0 };
    SetConsoleWindowInfo(out_handle, true, &minWindow);
    SetConsoleScreenBufferSize(out_handle, maxWindow);
    SetConsoleWindowInfo(out_handle, true, &srctWindow);

}
