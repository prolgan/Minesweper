#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Game.h"
#include "Graphic.h"
#include "Setting.h"
#include "Menu.h"
using namespace std;




    Game spele;



void unloadgame(Game sp){

    spele = sp;

}


Game loadgame(){
    Game sp(spele.getx(),spele.gety());
    sp.setx(spele.getx());
    sp.sety(spele.gety());
    sp.lvl = spele.lvl;
    sp.setbomb(spele.getbomb());




    for (int i = 0; i<spele.getx();i++){
                for(int j = 0; j<spele.gety();j++){
                    sp.settable(i,j,spele.gettable(i,j));
                }
            }

            for (int i = 0; i<spele.getx();i++){
                for(int j = 0; j<spele.gety();j++){
                    sp.setplayer(i,j,spele.getplayer(i,j));
                }
            }









return spele;
}



void Opensell(int x,int y){

    int xsize = spele.getx();
    int ysize = spele.gety();


    if((spele.gettable(x,y) == '-') && (spele.getplayer(x,y) == '-') && (x<=xsize-1) && (x>=0) && (y<=ysize-1) && (y>=0)){
        spele.setplayer(x,y,NULL);
        if((x<xsize) && (x>=0) && (y-1<ysize) &&(y-1>=0)){
             Opensell(x,y-1);

        }
         if(x-1<xsize && x-1>=0 &&y<ysize &&y>=0){
             Opensell(x-1,y);

        }
         if(x<xsize && x>=0 && y+1<ysize && y+1>=0){
             Opensell(x,y+1);

        }
         if(x+1<xsize && x+1>=0 && y<ysize && y>=0){
             Opensell(x+1,y);

        }
         if(x-1<xsize && x-1>=0 && y-1<ysize &&y-1>=0){
             Opensell(x-1,y-1);

        }
         if(x+1<xsize && x+1>=0 && y+1<ysize &&y+1>=0){
             Opensell(x+1,y+1);

        }
         if(x+1<xsize && x+1>=0 && y-1<ysize &&y-1>=0){
             Opensell(x+1,y-1);

        }
         if(x-1<xsize && x-1>=0 && y+1<ysize &&y+1>=0){
             Opensell(x-1,y+1);

        }
    }else{

        if((spele.gettable(x,y) != '*') && (spele.getplayer(x,y) == '-') && (x<xsize) && (x>=0) && (y<ysize) && (y>=0)){
            spele.setplayer(x,y,NULL);

        }
    }





}


bool checktowin(bool plays){

        if(plays == false){
            return true;
        }else{
        int bombTrue = 0;
        for (int i = 0; i<spele.getx();i++){
                for(int j = 0; j<spele.gety();j++){
                    if(spele.gettable(i,j) == '*' && spele.getplayer(i,j) == 'P')
                    {
                        bombTrue++;
                    }
                }
            }

            if(spele.getbomb() == bombTrue){
                return true;
            }else{
                return false;
            }

        }
}



void play(buttons but,Game spele){
    startcursor();
    cursorgraphic(0,0,spele);
    int xiz = 0;
    int yiz = 0;

    unloadgame(spele);

    bool plays = true;
    int i;
    while(plays){

        if(check_menu() == false){
            break;

        }else{
            unloadgame(spele);
            if(checktowin(plays)==true){
                break;
            }
        }


        do{
        int xsize = spele.getx();
        int ysize = spele.gety();

             i = getch();



        if(i == but.Button_up || i == but.Button_left || i == but.Button_down || i == but.Button_right){

           if(i==but.Button_up){
                if(xiz>0){
                    xiz = xiz - 1;
                }
           }
            if(i == but.Button_down){
                if(xiz<xsize-1){
                    xiz = xiz + 1;
                }
            }
            if(i == but.Button_left){
                if(yiz>0){
                    yiz = yiz - 1;
                }
            }

            if(i== but.Button_right){
                if(yiz<ysize-1){
                    yiz = yiz + 1;
                }
            }




            cursorgraphic(xiz,yiz,spele);





        }

          if(i== but.Button_pause){
                plays = gamemenu(but,spele);
                if(plays == true){
                    Scr10x10();
                    Graphic(spele);
                    but = settingLoad();
                }else{
                    break;
                }
            }

            if(i == but.Button_open){
                break;
            }

        }while(i != but.Button_flag);

        if(i==but.Button_open){
            if(spele.gettable(xiz,yiz) == '*'){
                plays = false;
                atvertvisu(spele);
            }else{

                if(spele.gettable(xiz,yiz) != '-'){
                        if(spele.getplayer(xiz,yiz) != 'P'){
                            spele.setplayer(xiz,yiz,NULL);

                    }
                }else{
                    if(spele.getplayer(xiz,yiz) != 'P'){
                        unloadgame(spele);
                        Opensell(xiz,yiz);
                        spele = loadgame();
                    }
                }

          }
      }

      if(i ==  but.Button_flag){
        if(spele.getplayer(xiz,yiz) != NULL){
                if(spele.getplayer(xiz,yiz) == 'P'){
                    spele.setplayer(xiz,yiz,'-');
                }else{
                    spele.setplayer(xiz,yiz,'P');

            }

        }

      }



        Graphic(spele);
        cursorgraphic(xiz,yiz,spele);
    }





}
