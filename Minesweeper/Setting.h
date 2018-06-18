#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED




class buttons{

public:
    int Button_up;
    int Button_down;
    int Button_left;
    int Button_right;
    int Button_open;
    int Button_flag;
    int Button_pause;



};


buttons settingLoad();
void settingSave(buttons);
buttons Settings(buttons);
buttons settingDefault();




#endif // SETTING_H_INCLUDED
