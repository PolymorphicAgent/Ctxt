#ifndef COLOR_TEXT_H
#define COLOR_TEXT_H
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include<Windows.h>
#endif
#include<string>
#include<iostream>
#include<cctype>
#define ST         std::string
#define black      0
#define dark_blue  1
#define dark_green 2
#define light_blue 3
#define dark_red   4
#define magenta    5
#define orange     6
#define light_gray 7
#define gray       8
#define blue       9
#define green     10
#define cyan      11
#define red       12
#define pink      13
#define yellow    14
#define white     15
void ctxt(ST s,const int textcolor,bool bold,bool underline,bool nlne);
#endif