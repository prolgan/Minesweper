#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
using namespace std;

class Game{

private:
    int bomb;
    int x, y;
    int sec;
    char **table;
    char **player;

public:
    Game();
    Game(int,int);
    ~Game();

    void setbomb(int);
    void setx(int);
    void sety(int);
    int getbomb();
    int getx();
    int gety();

    string lvl;

    char gettable(int,int);
    char getplayer(int,int);

    void settable(int,int,char);
    void setplayer(int,int,char);

    void destruktor();

    void Create(Game);

};








#endif // GAME_H_INCLUDED
