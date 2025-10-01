#include "ctxt.h"

#include<iostream>
#include<cctype>

std::string subSpaces(std::string st){
    for(int i=0;i<st.size();i++){
        if((char)st[i]==' '){
            st[i]='_';
        }
    }
    return st;
}
void ctxt(std::string s,const int textcolor,bool bold, bool underline,bool nlne){
    int backgroundcolor;
    if(underline)s=subSpaces(s);
#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    WORD default_colors=0;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))default_colors=csbi.wAttributes;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),black<<4|textcolor);
#elif defined(__linux__)
    std::string t,b;
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
        if(underline==false)std::cout<<"\033["+t+";"+b+"m";
        else std::cout<<"\033["+t+";"+b+";4"+"m";
    }
    else{
        if(underline==false)std::cout<<"\033[1;"+t+";"+b+"m";
        else std::cout<<"\033[1;"+t+";"+b+";4"+"m";
    }
#endif
    std::cout<<s;if(nlne==true)std::cout<<"\n";
#if defined(_WIN32)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),default_colors);
#elif defined(__linux__)
    std::cout<<"\033[0;24m";//reset color
#endif
}

void demo(){
    ctxt("This is black text on black background",black,false,false,true);
    ctxt("This is dark blue text on black background",dark_blue,false,false,true);
    ctxt("This is dark green text on black background",dark_green,false,false,true);
    ctxt("This is light blue text on black background",light_blue,false,false,true);
    ctxt("This is dark red text on black background",dark_red,false,false,true);
    ctxt("This is magenta text on black background",magenta,false,false,true);
    ctxt("This is orange text on black background",orange,false,false,true);
    ctxt("This is light gray text on black background",light_gray,false,false,true);
    ctxt("This is gray text on black background",gray,false,false,true);
    ctxt("This is blue text on black background",blue,false,false,true);
    ctxt("This is green text on black background",green,false,false,true);
    ctxt("This is cyan text on black background",cyan,false,false,true);
    ctxt("This is red text on black background",red,false,false,true);
    ctxt("This is pink text on black background",pink,false,false,true);
    ctxt("This is yellow text on black background",yellow,false,false,true);
    ctxt("This is white text on black background",white,false,false,true);

    ctxt("This is bold black text on black background",black,true,false,true);
    ctxt("This is bold dark blue text on black background",dark_blue,true,false,true);
    ctxt("This is bold dark green text on black background",dark_green,true,false,true);
    ctxt("This is bold light blue text on black background",light_blue,true,false,true);
    ctxt("This is bold dark red text on black background",dark_red,true,false,true);
    ctxt("This is bold magenta text on black background",magenta,true,false,true);
    ctxt("This is bold orange text on black background",orange,true,false,true);
    ctxt("This is bold light gray text on black background",light_gray,true,false,true);
    ctxt("This is bold gray text on black background",gray,true,false,true);
    ctxt("This is bold blue text on black background",blue,true,false,true);
    ctxt("This is bold green text on black background",green,true,false,true);
    ctxt("This is bold cyan text on black background",cyan,true,false,true);
    ctxt("This is bold red text on black background",red,true,false,true);
    ctxt("This is bold pink text on black background",pink,true,false,true);
    ctxt("This is bold yellow text on black background",yellow,true,false,true);
    ctxt("This is bold white text on black background",white,true,false,true);
    ctxt("This is underlined black text on black background",black,false,true,true);
    ctxt("This is underlined dark blue text on black background",dark_blue,false,true,true);
    ctxt("This is underlined dark green text on black background",dark_green,false,true,true);
    ctxt("This is underlined light blue text on black background",light_blue,false,true,true);
    ctxt("This is underlined dark red text on black background",dark_red,false,true,true);
    ctxt("This is underlined magenta text on black background",magenta,false,true,true);
    ctxt("This is underlined orange text on black background",orange,false,true,true);
    ctxt("This is underlined light gray text on black background",light_gray,false,true,true);
    ctxt("This is underlined gray text on black background",gray,false,true,true);
    ctxt("This is underlined blue text on black background",blue,false,true,true);
    ctxt("This is underlined green text on black background",green,false,true,true);
    ctxt("This is underlined cyan text on black background",cyan,false,true,true);
    ctxt("This is underlined red text on black background",red,false,true,true);
    ctxt("This is underlined pink text on black background",pink,false,true,true);
    ctxt("This is underlined yellow text on black background",yellow,false,true,true);
    ctxt("This is underlined white text on black background",white,false,true,true);
    ctxt("This is bold and underlined black text on black background",black,true,true,true);
    ctxt("This is bold and underlined dark blue text on black background",dark_blue,true,true,true);
    ctxt("This is bold and underlined dark green text on black background",dark_green,true,true,true);
    ctxt("This is bold and underlined light blue text on black background",light_blue,true,true,true);
    ctxt("This is bold and underlined dark red text on black background",dark_red,true,true,true);
    ctxt("This is bold and underlined magenta text on black background",magenta,true,true,true);
    ctxt("This is bold and underlined orange text on black background",orange,true,true,true);
    ctxt("This is bold and underlined light gray text on black background",light_gray,true,true,true);
    ctxt("This is bold and underlined gray text on black background",gray,true,true,true);
    ctxt("This is bold and underlined blue text on black background",blue,true,true,true);
    ctxt("This is bold and underlined green text on black background",green,true,true,true);
    ctxt("This is bold and underlined cyan text on black background",cyan,true,true,true);
    ctxt("This is bold and underlined red text on black background",red,true,true,true);
    ctxt("This is bold and underlined pink text on black background",pink,true,true,true);
    ctxt("This is bold and underlined yellow text on black background",yellow,true,true,true);
    ctxt("This is bold and underlined white text on black background",white,true,true,true);
    std::cout<<"\n";}