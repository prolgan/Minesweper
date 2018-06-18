#include <iostream>
#include "Game.h"
#include <fstream>
#include <windows.h>
#include "Save.h"
#include "Graphic.h"
#include <stdio.h>
#include <conio.h>
using namespace std;

bool nosaukumuparbaude(string nosaukums){

    if(nosaukums == "0") return true;
    nosaukums = "saves/"+ nosaukums + ".save";
    bool parbaude;
    if(ifstream(nosaukums.c_str())==NULL){
        return false;
    }else{

        return true;
    }



}


void dirSave(){
    //sakum failu un mapes izveidosana
  if(CreateDirectory("saves", NULL)){
        CreateDirectory("saves",NULL);
     }
      fstream tmp;
      tmp.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);
      tmp.close();

}



void SaveGame(Game spele,string nosaukums){
        fstream tmp;

        tmp.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);
        tmp<<" "<<nosaukums<<" "<<spele.lvl<<" "<<spele.getx()<<" "<<spele.gety()<<" "<<spele.getbomb();

        tmp.close();


        nosaukums = "saves/"+nosaukums+".save";

        fstream fails;

        fails.open(nosaukums.c_str(), fstream::in | fstream::out | fstream::trunc);

        fails<<spele.getx()<<" "<<spele.gety()<<" "<<spele.getbomb()<<" "<<spele.lvl;

        for(int i = 0 ; i < spele.getx();i++){
            for (int j  = 0; j < spele.gety();j++){
                fails<<" "<<spele.gettable(i,j);
            }

        }

        for(int i = 0 ; i < spele.getx();i++){
            for (int j  = 0; j < spele.gety();j++){
                fails<<" "<<spele.getplayer(i,j);
            }

        }



        fails.close();
}



Game ReadGame(string nosaukums){

        nosaukums = "saves/"+ nosaukums + ".save";
        fstream fails;

        fails.open(nosaukums.c_str(), fstream::in | fstream::out | fstream::app);
        int x,y,bomb;
        fails>>x>>y>>bomb;
        Game spele(x,y);
        fails>>spele.lvl;
        spele.setx(x);
        spele.sety(y);
        spele.setbomb(bomb);

        char tmp;
        for(int i = 0 ; i < spele.getx();i++){
            for (int j  = 0; j < spele.gety();j++){
                fails>>tmp;
                spele.settable(i,j,tmp);
            }

        }

        for(int i = 0 ; i < spele.getx();i++){
            for (int j  = 0; j < spele.gety();j++){
                fails>>tmp;
                spele.setplayer(i,j,tmp);
            }

        }



    return spele;

}


void saveMenu(Game spele){

    string nos;
    system("cls");
    cout<<"Speles saglabasana"<<endl;
    cout<<"Ievadi speles nosaukumu"<<endl;
    cursoron();
    do{
        if(nosaukumuparbaude(nos) != false){
            cout<<"Tads speles nosaukums aiznemts"<<endl;
            cout<<"Ievadi nosaukumu velreiz"<<endl;
        }

    cin>>nos;
    }while(nosaukumuparbaude(nos));
    cursoroff();

    SaveGame(spele,nos);





}

void dzestMenu(){
    char a;
    do{
    system("cls");
    cout<<"1 - Speles list"<<endl;
    cout<<"2 - Meklet pec nosaukuma"<<endl;
    cout<<"0 - Iziet"<<endl;

    a =getch();
    string nosaukums;

    if(a == '1'){
        int i = 1;
        int x;
        int y;
        int bomb;
        string lvl;
                system("cls");
                fstream tmp;
                tmp.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);

                while(!tmp.eof()){

                    tmp>>nosaukums>>lvl>>x>>y>>bomb;

                    cout <<i<<". "<<nosaukums<<" Speles uzstadijumi: "<<lvl<<" "<<x<<"x"<<y<<" Bomb skaits: "<<bomb<<endl;
                    i++;
                }


                tmp.close();
                int b;
                Game spele;
                do{
                    cout <<"izveles spele"<<endl;
                    cout <<"0 - Iziet"<<endl;
                    cin >>b;
                    if(b == 0) break;
                }while(b > i-1 || b < 0);

                 if(b != 0){
                    fstream tmpa;
                    tmpa.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);
                    i= 1;
                    while(i <= b){

                        tmpa>>nosaukums>>lvl>>x>>y>>bomb;
                        i++;
                    }
                    tmpa.close();
                 }



    }

    if(a=='2'){
        system("cls");
        Game spele;
        cursoron();
        do{
                cout<<"Ievadi nosaukumu"<<endl;
                cout<<"0 - Iziet"<<endl;
                cin>>nosaukums;
        }while(nosaukumuparbaude(nosaukums) != true);
        cursoroff();
    }

    if(nosaukums != "0"){
        string nos;
        string lvl;
        int x;
        int y;
        int bomb;
        fstream fail;
        fail.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);
        fstream newfail;
        newfail.open("saves/0.txt",fstream::in | fstream::out | fstream::trunc);
        do{
            fail>>nos>>lvl>>x>>y>>bomb;
            if(nos != nosaukums){
                newfail<<" "<<nos<<" "<<lvl<<" "<<x<<" "<<y<<" "<<bomb;
            }
        }while(!fail.eof());
        fail.close();
        newfail.close();

        remove("saves/all_game_saves.txt");
        rename("saves/0.txt","saves/all_game_saves.txt");
        nosaukums = "saves/" + nosaukums +".save";
        remove(nosaukums.c_str());
        a = '0';
    }


    }while(a != '0');


}


Game unsaveMenu(){
    char a;
    //parbaude vai ir kada saglabata spele
    fstream f;
    f.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);

    long file_size;
    f.seekg(0, ios::end);
    file_size = f.tellg();

    f.close();
    if (file_size != 0) {
        do{
            system("cls");
            cout<<"1 - Speles list"<<endl;
            cout<<"2 - Meklet pec nosaukuma"<<endl;
            cout<<"3 - Dzest speli"<<endl;
            cout<<"0 - Iziet"<<endl;
            a = getch();
            string nosaukums;
            string lvl;

            int x,y,bomb;
            if(a == '1'){
                int i = 1;
                system("cls");
                fstream tmp;
                tmp.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);

                while(!tmp.eof()){

                    tmp>>nosaukums>>lvl>>x>>y>>bomb;

                    cout <<i<<". "<<nosaukums<<" Speles uzstadijumi: "<<lvl<<" "<<x<<"x"<<y<<" Bomb skaits: "<<bomb<<endl;
                    i++;
                }


                tmp.close();
                int b;
                Game spele;
                do{
                    cout <<"izveles spele"<<endl;
                    cout <<"0 - Iziet"<<endl;
                    cin >>b;
                    if(b == 0) break;
                }while(b > i-1 || b < 0);

                 if(b != 0){
                    fstream tmpa;
                    tmpa.open("saves/all_game_saves.txt",fstream::in | fstream::out | fstream::app);
                    i= 1;
                    while(i <= b){

                        tmpa>>nosaukums>>lvl>>x>>y>>bomb;
                        i++;
                    }



                    tmpa.close();

                    spele = ReadGame(nosaukums);
            }else{

                spele.lvl="NONE";
            }
            return spele;

            }

            if(a == '2'){
                system("cls");
                string nos;
                Game spele;
                cursoron();
                do{
                    cout<<"Ievadi nosaukumu"<<endl;
                    cout<<"0 - Iziet"<<endl;
                    cin>>nos;
                }while(nosaukumuparbaude(nos) != true);
                cursoroff();
                if(nos != "0"){

                    spele = ReadGame(nos);


                }else{
                    spele.lvl = "NONE";
                }

                return spele;



            }

            if(a == '3'){

                dzestMenu();
                Game spele;
                spele.lvl = "NONE";
                return spele;
            }

            if(a == '0'){
                Game spele;
                spele.lvl = "NONE";
                return spele;

            }

        }while(a != '0');



    }else{
        system("cls");
        cout<<"Jums nav saglabatas speles"<<endl;
        cout<<"Spiezat jebkuru burtu"<<endl;
        a = getch();
        Game spele;
        spele.lvl = "NONE";
        return spele;

    }


}











