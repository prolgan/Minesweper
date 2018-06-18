#include <iostream>
#include "Game.h"
#include "Graphic.h"
#include <stdlib.h>
#include <ctime>
#include "Gameplay.cpp"
#include "Menu.h"
#include "Setting.h"
#include <fstream>
#include <cstdlib>
#include "Save.h"


using namespace std;

bool go_menu = true;

string lvl;


int Maxcustomx(){
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxWindow = GetLargestConsoleWindowSize(out_handle);
    int x = maxWindow.X;
    return x;
}

int Maxcutsomy(){
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD maxWindow = GetLargestConsoleWindowSize(out_handle);
    int y = maxWindow.Y;
    return y;
}



void Scr10x10(){

 if(lvl == "10x10"){

    system("mode con cols=41 lines=21");
 }
 if(lvl == "25x15"){
    system("mode con cols=101 lines=31");
 }
 if(lvl == "40x20"){
    system("mode con cols=161 lines=41");

 }
 if(lvl == "custom"){

    fullscreen();
 }

}





bool loadd = false;
bool check_menu(){


return go_menu;

}

char levelselect(){
    char izvele;
     do{
        system("cls");
        cout<<"1 - Easy"<<endl;
        cout<<"2 - Normal"<<endl;
        cout<<"3 - Hard"<<endl;
        cout<<"0 - Exit"<<endl;
        izvele = getch();
    }while(izvele != '1' && izvele !='3' && izvele != '2' && izvele != '0');

    return izvele;


}



void game10_10(buttons but,Game gg){

            if(loadd == true){

            gg = unsaveMenu();
            if(gg.lvl != "NONE");
            lvl = gg.lvl;


        }
        if(gg.lvl != "NONE"){

        time_t seconds;
        time_t start;

        go_menu = true;


             Scr10x10();


        if(loadd == false){
            gg.Create(gg);
            Graphic(gg);

      }
        start = time(NULL);

        cursoroff();
        Graphic(gg);
        play(but,gg);
        if(go_menu == true){
            if(checktowin(true)==true){
                if(loadd == false){
                    system("mode con cols=120 lines=30");
                    cout<<"WIN"<<endl;
                    seconds = time (NULL);
                    int sec = seconds - start;
                    cout<<"aiznema: "<<sec<<" sekundas"<<endl;
                    cout<<"Spiezat jebkuru burtu"<<endl;
                    char a;
                    a = getch();
                }else{
                    system("mode con cols=120 lines=30");
                    cout<<"WIN"<<endl;
                    cout<<"Spele ir lejupieladeta un laiks nav piejams"<<endl;
                    cout<<"Spiezat jebkuru burtu"<<endl;
                    char a;
                    a = getch();


                }



            }else{


                    system("mode con cols=120 lines=30");
               // }
            }
        }



        }
    loadd=false;
    gg.destruktor();
}


char sizechoose(){
    char izvele;

    do{
        system("cls");
        cout<<"1 - 10 x 10"<<endl;
        cout<<"2 - 25 x 15"<<endl;
        cout<<"3 - 40 x 20"<<endl;
        cout<<"4 - Custom mode"<<endl;
        cout<<"0 - Exit"<<endl;
        izvele = getch();
    }while(izvele != '1' && izvele !='0' && izvele != '3' && izvele != '2' && izvele != '4');

    return izvele;


}



void SelectGame(buttons but){

    char izvele = sizechoose();
    if(izvele == '1'){
        char i = levelselect();
        if(i != '0'){
        lvl = "10x10";
        Game gg(10,10);
            if(i == '1'){
               gg.setbomb(10);
            }
            if(i == '2'){
               gg.setbomb(20);
            }
            if(i == '3'){
               gg.setbomb(30);
            }

            gg.setx(10);
            gg.sety(10);
            gg.lvl = lvl;




            game10_10(but,gg);
        }

    }

    if(izvele == '2'){
        char i = levelselect();
        if(i != '0'){
            lvl = "25x15";
            Game gg(15,25);
                if(i == '1'){
                   gg.setbomb(38);
                }
                if(i == '2'){
                   gg.setbomb(76);
                }
                if(i == '3'){
                   gg.setbomb(100);
                }

                gg.setx(15);
                gg.sety(25);
                gg.lvl = lvl;

                game10_10(but,gg);
        }
    }

    if(izvele == '3'){
        char i = levelselect();
        if(i != '0'){
            lvl = "40x20";
            Game gg(20,40);
                if(i == '1'){
                   gg.setbomb(80);
                }
                if(i == '2'){
                   gg.setbomb(160);
                }
                if(i == '3'){
                   gg.setbomb(300);
                }

                gg.setx(20);
                gg.sety(40);
                gg.lvl = lvl;

                game10_10(but,gg);
        }
    }

    if(izvele == '4'){
        int x,y;
        int maxx = Maxcustomx() / 4;
        int maxy = Maxcutsomy() / 2;
        lvl = "custom";
        do{
            system("cls");
            cout<<"CUSTOM"<<endl;
            cout<<"Max x - "<<maxx-2<<" Max y - "<<maxy-2<<endl;
            cout<<"Ievadi laukumu"<<endl;
            cout<<"x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;
        }while(x <1 || y <1 || y > maxy || x > maxx);
        int bomb;
        do{
            system("cls");
            cout<<"CUSTOM"<<endl;
            cout<<"Ievadi bomb skaitu"<<endl;
            cout<<"bomb: ";
            cin>>bomb;

        }while(x*y <bomb || bomb<1);

        Game gg(y,x);
        gg.setx(y);
        gg.sety(x);
        gg.setbomb(bomb);
        gg.lvl = lvl;

        game10_10(but,gg);

    }

}




bool fileparbaude(){

    bool parbaude;
    if(ifstream("settings.bin")==NULL){
        return false;
    }else{
        return true;
    }



}




bool gamemenu(buttons but,Game spele){

    system("mode con cols=120 lines=30");
    char izvele;
    bool exit_menu = true;
    do{
        system("cls");
        cout << "1 - spelet talak" <<endl;
        cout << "2 - saglabat spele"<<endl;
        cout << "3 - lejupieladet spele"<<endl;
        cout << "4 - settings"<<endl;
        cout << "5 - Exit to main menu"<<endl;
        cout << "0 - Exit from game"<<endl;
        izvele = getch();

    bool exit_menu = true;
    go_menu = true;
    switch(izvele){
        case '1':
            exit_menu = false;
            break;
        case '2':
            saveMenu(spele);
            break;
        case '3':
            loadd = true;
            game10_10(but,spele);
            exit_menu = false;
            go_menu =  false;
            break;
        case '4':
            but = Settings(but);
            settingSave(but);
            break;
        case '5':
            exit_menu = false;
            go_menu =  false;
            break;
        case '0':
            exit_menu = false;
            exit (0);
            break;


    }


    if(exit_menu == false){
            if(go_menu == false){
                return false;
            }else{
                return true;
            }

    }
    }while(exit_menu);






}




void mainmenu(){
    buttons but;
    loadd = false;



    void cursoron();

    char izvele;
    do{
    system("mode con cols=120 lines=30");
    if(fileparbaude() == true){

        but = settingLoad();
    }else{

       but = settingDefault();
    }
        system("cls");
        cout<<"1 - Jauna spele"<<endl;
        cout<<"2 - Lejupielaidet speli"<<endl;
        cout<<"3 - Settings"<<endl;
        cout<<"0 - Exit"<<endl;
        izvele = getch();


    if(izvele != '0'){
        if(izvele == '1'){
            loadd = false;
            SelectGame(but);


        }
        if(izvele == '2'){
            loadd = true;
            Game gg;
            game10_10(but,gg);

        }

        if(izvele == '3'){
            but = Settings(but);
            settingSave(but);
        }
    }

    }while(izvele !='0');

}


