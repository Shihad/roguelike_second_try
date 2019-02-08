#include <iostream>
//Определяем цвета
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define GREY 7
#define DKGREY 60
#define LTRED 61
#define LTGREEN 62
#define LTYELLOW 63
#define LTBLUE 64
#define LTMAGENTA 65
#define LTCYAN 66
#define WHITE 67

void clrscr(); //очистка экрана

void gotoxy(int x,int y); //переход в точку x,y

void textcolor(int color); //цвет шрифта. Либо числа 0-7, 60-67, либо по вышеприведенной таблице

void textbackground(int color); //цвет фона. Либо числа 0-7, 60-67, либо по вышеприведенной таблице

void textblink(); //мигающий текст

void textbold(); //жирный шрифт

void textitalic(); //курсив

void textreset(); //сброс настроек шрифта

