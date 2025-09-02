#include "ctxt.h"
#include <string>
ST subSpaces(ST st){
    for(int i=0;i<st.size();i++){
        if((char)st[i]==' '){
            st[i]='_';
        }
    }
    R st;
}
void ctxt(ST s,const int textcolor,bool bold, bool underline,bool nlne){
    int backgroundcolor;
    if(underline)s=subSpaces(s);
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD default_colors=0;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))default_colors=csbi.wAttributes;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),black<<4|textcolor);
#elif defined(__linux__)
    ST t,b;
    switch(textcolor) {
        case  0: t="30";break;//black      0
        case  1: t="34";break;//dark_blue  1
        case  2: t="32";break;//dark_green 2
        case  3: t="36";break;//light_blue 3
        case  4: t="31";break;//dark_red   4
        case  5: t="35";break;//magenta    5
        case  6: t="33";break;//orange     6
        case  7: t="37";break;//light_gray 7
        case  8: t="90";break;//gray       8
        case  9: t="94";break;//blue       9
        case 10: t="92";break;//green     10
        case 11: t="96";break;//cyan      11
        case 12: t="91";break;//red       12
        case 13: t="95";break;//pink      13
        case 14: t="93";break;//yellow    14
        case 15: t="97";break;//white     15
        default: t="97";
    }
    switch(backgroundcolor) {
        case  0: b= "40"; break;//black      0
        case  1: b= "44"; break;//dark_blue  1
        case  2: b= "42"; break;//dark_green 2
        case  3: b= "46"; break;//light_blue 3
        case  4: b= "41"; break;//dark_red   4
        case  5: b= "45"; break;//magenta    5
        case  6: b= "43"; break;//orange     6
        case  7: b= "47"; break;//light_gray 7
        case  8: b="100"; break;//gray       8
        case  9: b="104"; break;//blue       9
        case 10: b="102"; break;//green     10
        case 11: b="106"; break;//cyan      11
        case 12: b="101"; break;//red       12
        case 13: b="105"; break;//pink      13
        case 14: b="103"; break;//yellow    14
        case 15: b="107"; break;//white     15
        default: b= "40";
    }
    if(bold==false){
        if(underline==false)O<<"\033["+t+";"+b+"m";
        else O<<"\033["+t+";"+b+";4"+"m";
    }
    else{
        if(underline==false)O<<"\033[1;"+t+";"+b+"m";
        else O<<"\033[1;"+t+";"+b+";4"+"m";
    }
#endif
    O<<s;if(nlne==true)O<<"\n";
#if defined(_WIN32)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),default_colors);
#elif defined(__linux__)
    O<<"\033[0;24m";//reset color
#endif
}