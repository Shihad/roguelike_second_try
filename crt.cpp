#include "crt.h"


void clrscr() { //функция очистки экрана
    std::cout << "\e[H"; //возвращаемся в нулевую строку
    std::cout << "\e[2J"; //очищаем экран
}

void gotoxy(int x, int y) {
    std::cout << "\e["<<y<<";"<<x<<"H";
}

void textcolor(int color)
{
    std::cout << "\e["<<30+color<<"m";
}

void textbackground(int color)
{
    std::cout << "\e["<<40+color<<"m";
}

void textreset()
{
    std::cout << "\e[0m";
}

void textblink()
{
       std::cout << "\e[5m";
}

void textbold()
{
    std::cout << "\e[1m";
}

void textitalic()
{
    std::cout << "\e[3m";
}
