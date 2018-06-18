#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Game.h"
#include "Graphic.h"
#include "Save.h"
using namespace std;


void Game::setbomb(int bomb){
    this->bomb = bomb;
}
void Game::setx(int x){
    this->x = x;
}
void Game::sety(int y){
    this->y= y;
}
int Game::getbomb(){
    return this->bomb;
}
int Game::getx(){
    return this->x;
}
int Game::gety(){
    return this->y;
}

char Game::gettable(int x ,int y){
    return table[x][y];
}
char Game::getplayer(int x,int y){
    return player[x][y];
}

void Game::settable(int x,int y ,char cell){
    table[x][y] = cell;
}
void Game::setplayer(int x ,int y ,char cell){
    player[x][y] = cell;
}

Game::Game(int x,int y){

    this->player =new char *[x];
    this->table =new char *[x];

    for(int i = 0;i <x;i++){
        player[i] =new char[y];
    }
     for(int i = 0;i <x;i++){
        table[i] =new char[y];
    }

    this->x = x;
    this->y = y;

}
Game ::Game(){

    player = NULL;
    table = NULL;
    x,y = 0;

}

void Game::destruktor(){

    for(int i = 0;i <x;i++){
       delete [] player[i];
    }
     for(int i = 0;i <x;i++){
        delete [] table[i];
    }


    delete [] player;
    delete [] table;

}

Game::~Game(){
/*
   for(int i = 0;i <x;i++){
       delete [] player[i];
    }
     for(int i = 0;i <x;i++){
        delete [] table[i];
    }


    delete [] player;
    delete [] table;
*/
}



void Game::Create(Game lvl)
{



    setbomb(lvl.getbomb());
    setx(lvl.getx());
    sety(lvl.gety());



    srand(time(0));


     for (int i = 0; i<getx();i++){
            for(int j = 0; j<gety();j++){
                    settable(i,j,'-');
        }
    }





       for (int i = 0; i<getx();i++){
            for(int j = 0; j<gety();j++){
                    setplayer(i,j,'-');
        }
    }



    int rX,rY;
    for (int i = 0;i<getbomb();i++){



            rX = rand() % getx();
            rY = rand() % gety();
            if(gettable(rX,rY) == '*'){
               bool bombcheck = true;
               while(bombcheck){
                    rX = rand() % getx();
                    rY = rand() % gety();
                    if(gettable(rX,rY) != '*'){
                        settable(rX,rY,'*');
                        bombcheck = false;
                    }else{
                        continue;
                    }
               }
            }else{
                 settable(rX,rY,'*');
            }
    }




    int a = getx();
    int b = gety();
   for (int i = 0; i<a;i++){
        for(int j = 0; j<b;j++){

            int counter = 0;
            if(gettable(i,j) != '*'){
                counter = 0;

                        if(i+1 >= 0 && i+1<= a-1){
                                if(gettable(i+1,j) == '*'){
                                    counter++;
                    }

                }
                    if(i+1 >= 0 && i+1<= a-1){
                            if(j+1 >=0 && j+1 <=b-1){
                                if(gettable(i+1,j+1) == '*'){
                                counter++;
                            }
                    }

                }
                if(i+1 >= 0 && i+1<= a-1){
                            if(j-1 >=0 && j-1 <=b-1){
                                if(gettable(i+1,j-1) == '*'){
                                    counter++;
                            }
                    }
                }

                if(j+1 >=0 && j+1 <=b-1){
                    if(gettable(i,j+1) == '*'){
                        counter++;
                    }

                }
                if(j-1 >=0 && j-1 <=b-1){
                    if(gettable(i,j-1) == '*'){
                        counter++;
                        }

                }
                if(i-1 >=0 && i-1 <=a-1){
                    if(gettable(i-1,j) == '*'){
                        counter++;
                        }

                }
                if(i-1 >= 0 && i-1<= a-1){
                            if(j+1 >=0 && j+1 <=b-1){
                                if(gettable(i-1,j+1) == '*'){
                        counter++;
                            }
                    }

                }
                if(i-1 >= 0 && i-1<= a-1){
                            if(j-1 >=0 && j-1 <=b-1){
                                if(gettable(i-1,j-1) == '*'){
                        counter++;
                            }
                    }

                }

                    char tmp = NULL;

                     switch(counter){

                        case 1: tmp = '1';break;
                        case 2: tmp = '2';break;
                        case 3: tmp = '3';break;
                        case 4: tmp = '4';break;
                        case 5: tmp = '5';break;
                        case 6: tmp = '6';break;
                        case 7: tmp = '7';break;
                        case 8: tmp = '8';break;

                     }

                     if(tmp != NULL){
                        settable(i,j,tmp);
                     }

        }



        }

    }


}





