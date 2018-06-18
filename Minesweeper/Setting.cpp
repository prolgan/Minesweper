#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "Setting.h"
using namespace std;




buttons settingLoad(){
    buttons but;
    fstream fails;
    fails.open("settings.bin",fstream::in |fstream::out | fstream::app);

    fails >> but.Button_up>>but.Button_down>>but.Button_right>>but.Button_left>>but.Button_open>>but.Button_flag>>but.Button_pause;

    fails.close();

    return but;
}


void settingSave(buttons but){

    fstream fails;
    fails.open("settings.bin",fstream::in |fstream::out | fstream::trunc);
    fails << but.Button_up<<" "<<but.Button_down<<" "<<but.Button_right<<" "<<but.Button_left<<" "<<but.Button_open<<" "<<but.Button_flag<<" "<<but.Button_pause;
    fails.close();
}


buttons settingDefault(){
    buttons but;
    fstream fails;
    fails.open("settings.bin",fstream::in |fstream::out | fstream::trunc);
    but.Button_up='w';
    but.Button_down='s';
    but.Button_left='a';
    but.Button_right='d';
    but.Button_open='r';
    but.Button_flag='f';
    but.Button_pause = 27;

    fails << but.Button_up<<" "<<but.Button_down<<" "<<but.Button_right<<" "<<but.Button_left<<" "<<but.Button_open<<" "<<but.Button_flag<<" "<<but.Button_pause;

    fails.close();

    return but;

}



string butoncout(int buton){

    string text;






    switch(buton){

        case 13: text = "Enter";break;
        case 8: text ="Backspace";break;
        case 32: text ="Space";break;
        case 9: text = "Tab";break;
        case 27: text = "Esc";break;

        default:
                text = char(buton);

            break;
        }

    return(text);




}


buttons Settings(buttons but){
    char izvele;
    do{
        system("cls");
        cout<<"1 - UP - "<<butoncout(but.Button_up)<<endl;
        cout<<"2 - DOWN - "<<butoncout(but.Button_down)<<endl;
        cout<<"3 - LEFT - "<<butoncout(but.Button_left)<<endl;
        cout<<"4 - RIGHT - "<<butoncout(but.Button_right)<<endl;
        cout<<"5 - OPEN - "<<butoncout(but.Button_open)<<endl;
        cout<<"6 - FLAG - "<<butoncout(but.Button_flag)<<endl;
        cout<<"7 - PAUSE - "<<butoncout(but.Button_pause)<<endl;
        cout<<"8 - DEFAULT SETTINGS"<<endl;
        cout<<"0 - EXIT"<<endl;
        izvele = getch();

    int poga;
    if(izvele != '0'){
        if(izvele != '7'){
            cout<<"Ievadi nomainitu pogu"<<endl;
            poga = getch();
        }
        if(izvele == '1'){
                bool par = true;
                do{
                if(poga != but.Button_down){
                    if(poga !=but.Button_right){
                        if(poga !=but.Button_left){
                            if(poga != but.Button_open){
                                if(poga !=but.Button_flag){
                                        if(poga != but.Button_pause){
                                    but.Button_up = poga;
                                    par = false;
                                    }
                                }

                            }
                        }
                    }
                }

                    if(par == true){
                        cout <<endl;
                        cout<<"Poga ir aiznemta"<<endl;
                        cout<<"Ievadi nomainitu pogu"<<endl;
                        poga = getch();
                    }
                }while(par);
        }

        if(izvele == '2'){
                bool par = true;
                do{cout<<"1 - Spelet"<<endl;
                if(poga != but.Button_up){
                    if(poga !=but.Button_right){
                        if(poga !=but.Button_left){
                            if(poga != but.Button_open){
                                if(poga !=but.Button_flag){
                                    if(poga != but.Button_pause){
                                        but.Button_down = poga;
                                        par = false;
                                    }
                                }

                            }
                        }
                    }
                }

                    if(par == true){
                        cout <<endl;
                        cout<<"Poga ir aiznemta"<<endl;
                        cout<<"Ievadi nomainitu pogu"<<endl;
                        poga = getch();
                    }
                }while(par);
        }


    if(izvele == '4'){
                bool par = true;
                do{
                if(poga != but.Button_down){
                    if(poga !=but.Button_up){
                        if(poga !=but.Button_left){
                            if(poga != but.Button_open){
                                if(poga !=but.Button_flag){
                                        if(poga != but.Button_pause){
                                    but.Button_right = poga;
                                    par = false;
                                    }

                                }
                            }
                        }
                    }
                }
                    if(par == true){
                        cout <<endl;
                        cout<<"Poga ir aiznemta"<<endl;
                        cout<<"Ievadi nomainitu pogu"<<endl;
                        poga = getch();
                    }
                }while(par);
        }


            if(izvele == '3'){
                bool par = true;
                do{
                if(poga != but.Button_down){
                    if(poga !=but.Button_right){
                        if(poga !=but.Button_up){
                            if(poga != but.Button_open){
                                if(poga !=but.Button_flag){
                                        if(poga != but.Button_pause){
                                    but.Button_left = poga;
                                    par = false;
                                    }

                                }
                            }
                        }
                    }
                }
                    if(par == true){
                        cout <<endl;
                        cout<<"Poga ir aiznemta"<<endl;
                        cout<<"Ievadi nomainitu pogu"<<endl;
                        poga = getch();
                    }
                }while(par);
        }


            if(izvele == '5'){
                bool par = true;
                do{
                if(poga != but.Button_down){
                    if(poga !=but.Button_right){
                        if(poga !=but.Button_left){
                            if(poga != but.Button_up){
                                if(poga !=but.Button_flag){
                                        if(poga != but.Button_pause){
                                    but.Button_open = poga;
                                    par = false;
                                    }

                                }
                            }
                        }
                    }
                }
                    if(par == true){
                        cout <<endl;
                        cout<<"Poga ir aiznemta"<<endl;
                        cout<<"Ievadi nomainitu pogu"<<endl;
                        poga = getch();
                    }
                }while(par);
        }

            if(izvele == '6'){
                bool par = true;
                do{
                if(poga != but.Button_down){
                    if(poga !=but.Button_right){
                        if(poga !=but.Button_left){
                            if(poga != but.Button_open){
                                if(poga !=but.Button_up){
                                        if(poga != but.Button_pause){
                                    but.Button_flag = poga;
                                    par = false;
                                    }

                                }
                            }
                        }
                    }
                }



                    if(par == true){
                        cout <<endl;
                        cout<<"Poga ir aiznemta"<<endl;
                        cout<<"Ievadi nomainitu pogu"<<endl;
                        poga = getch();
                    }
                }while(par);
        }

        if(izvele == '7'){
            bool par = true;
            do{
                if(poga != but.Button_down){
                    if(poga !=but.Button_right){
                        if(poga !=but.Button_left){
                            if(poga != but.Button_open){
                                if(poga !=but.Button_up){
                                        if(poga != but.Button_flag){
                                    but.Button_pause = poga;
                                    par = false;
                                    }

                                }
                            }
                        }
                    }
                }
                 if(par == true){
                        cout <<endl;
                        cout<<"Poga ir aiznemta"<<endl;
                        cout<<"Ievadi nomainitu pogu"<<endl;
                        poga = getch();
                    }
                }while(par);

            }




           if(izvele == '8'){
                but = settingDefault();
           }

    }





    }while(izvele != '0' );

    return but;
}

