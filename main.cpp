#include <iostream>
#include <crt.h>
#include <SFML/Graphics.hpp>

using namespace std;

enum monsters {nobody,zombie, ghoul,vampire,necromancer,spectre,demon };
enum hero_class{warrior, mage, monk, rogue};
enum hero_race{human,dwarf,elf,hobbit,halfelf,naga};
enum hero_gender{male,female,other};
enum weapons{fist,knife,dagger,sword,axe,hammer};
enum armours{robe,tegiley,chainmall,brigand,cuirass,fullarmour};
enum helmets{no_helmet,cap,steelhelmet};
enum amulets{no_amulet,amuletofdoom,amuletoffire,amuletofsecondlife,amuletofwaterwalking};
enum stuffs{};
enum direction{dir_right,dir_left,dir_up,dir_down};
enum action{no_action, action_move,action_attack};

enum groundtype{wall,ground,mud,shallow_water,deep_water,quicksand,trap,found_trap,ladder_up,ladder_down};


struct cell {
 
    int x,y; //положение
    groundtype type; //тип клетки
    stuffs stuff[50]; //до 50 предметов, валяющихся
    monsters monster; //один монстр

};

struct hero {
    //Создадим Героя
    hero_class hclass;
    hero_race hrace;

    hero_gender hgender;

    weapons weapon;
    armours armour;
    helmets helmet;
    amulets amulet1,amulet2;

    vector<stuffs> stuff;

    int x,y;

    //Сила
    int str;
    //Ловкость
    int dex;
    //Стойкость
    int con;
    //Интеллект
    int intel;
    //Мудрость
    int wiz;
    //Харизма
    int cha;

    //Модификаторы героя
    //силы
    double str_m;
    //ловкости
    double dex_m;
    //стойкости
    double con_m;
    //интеллекта
    double int_m;
    //мудрости
    double wiz_m;
    //харизмы
    double cha_m;

    //Запас здоровья, Класс брони и все прочее
    int max_hp;
    int hp;
    int ac;
    int gold;


};


struct monster {
    //Создадим монстра
    monsters monster_type;

    stuffs stuff[50];

    int x,y;

    //Сила
    int str;
    //Ловкость
    int dex;
    //Стойкость
    int con;
    //Интеллект
    int intel;
    //Мудрость
    int wiz;
    //Харизма
    int cha;

    //Модификаторы героя
    //силы
    double str_m;
    //ловкости
    double dex_m;
    //стойкости
    double con_m;
    //интеллекта
    double int_m;
    //мудрости
    double wiz_m;
    //харизмы
    double cha_m;

    //Запас здоровья, Класс брони и все прочее
    int max_hp;
    int hp;
    int ac;


};

const int levelmapwidth=220;
const int levelmapheight=60;
cell levelmap[levelmapwidth][levelmapheight];



hero create_hero() {
    hero myhero;
    myhero.hclass=warrior;
    myhero.hrace=elf;
    myhero.x=1;
    myhero.y=1;
    return myhero;
}

//Подробно расписать движение героя. Поручить Аксеновой.
void move_hero(direction dir, hero *h) {
    if (dir==dir_right) { //направо
        if (levelmap[h->x+1][h->y].monster==nobody) {
        if (levelmap[h->x+1][h->y].type==ground) {h->x=h->x+1;}
        if (levelmap[h->x+1][h->y].type==mud) {h->x=h->x+1;}
        if (levelmap[h->x+1][h->y].type==shallow_water) {h->x=h->x+1;}
        if (levelmap[h->x+1][h->y].type==quicksand) {h->x=h->x+1;}
        if (levelmap[h->x+1][h->y].type==wall) { ;}
        if ((levelmap[h->x+1][h->y].type==deep_water) and (h->hrace!=naga) and ((h->amulet1!=amuletofwaterwalking) or (h->amulet2!=amuletofwaterwalking))) {;}
        }
        else {//attack();
        }}
    if (dir==dir_left) { //налево
        if (levelmap[h->x-1][h->y].monster==nobody) {
        if (levelmap[h->x-1][h->y].type==ground) {h->x=h->x-1;}
        if (levelmap[h->x-1][h->y].type==mud) {h->x=h->x-1;}
        if (levelmap[h->x-1][h->y].type==shallow_water) {h->x=h->x-1;}
        if (levelmap[h->x-1][h->y].type==quicksand) {h->x=h->x-1;}
        if (levelmap[h->x-1][h->y].type==wall) { ;}
        if ((levelmap[h->x-1][h->y].type==deep_water) and (h->hrace!=naga) and ((h->amulet1!=amuletofwaterwalking) or (h->amulet2!=amuletofwaterwalking))) {;}
            }
        else {//attack();
        }}
    if (dir==dir_up) { //вверх
        if (levelmap[h->x][h->y-1].monster==nobody) {
        if (levelmap[h->x][h->y-1].type==ground) {h->y=h->y-1;}
        if (levelmap[h->x][h->y-1].type==mud) {h->y=h->y-1;}
        if (levelmap[h->x][h->y-1].type==shallow_water) {h->y=h->y-1;}
        if (levelmap[h->x][h->y-1].type==quicksand) {h->y=h->y-1;}
        if (levelmap[h->x][h->y-1].type==wall) { ;}
        if ((levelmap[h->x][h->y-1].type==deep_water) and (h->hrace!=naga) and ((h->amulet1!=amuletofwaterwalking) or (h->amulet2!=amuletofwaterwalking))) {;}
            }
        else {//attack();
        }}
    if (dir==dir_down) { //вниз
        if (levelmap[h->x][h->y+1].monster==nobody) {
        if (levelmap[h->x][h->y+1].type==ground) {h->y=h->y+1;}
        if (levelmap[h->x][h->y+1].type==mud) {h->y=h->y+1;}
        if (levelmap[h->x][h->y+1].type==shallow_water) {h->y=h->y+1;}
        if (levelmap[h->x][h->y+1].type==quicksand) {h->y=h->y+1;}
        if (levelmap[h->x][h->y+1].type==wall) { ;}
        if ((levelmap[h->x][h->y+1].type==deep_water) and (h->hrace!=naga) and ((h->amulet1!=amuletofwaterwalking) or (h->amulet2!=amuletofwaterwalking))) {;}
            }
        else {//attack();
            }

    }
}

 //Подробно расписать движение монстра. Поручить Аристархову.
void move_monster(direction dir, monster *m) {
    if (dir==dir_right) { //направо
        if (levelmap[m->x+1][m->y].monster==nobody) {
        if (levelmap[m->x+1][m->y].type==ground) {m->x=m->x+1;}

        if (levelmap[m->x+1][m->y].type==mud) {m->x=m->x+1;}
         if (levelmap[m->x+1][m->y].type==shallow_water) {m->x=m->x+1;}
          if (levelmap[m->x+1][m->y].type==quicksand) {m->x=m->x+1;}
        if (levelmap[m->x+1][m->y].type==wall) { ;}
        if ((levelmap[m->x+1][m->y].type==deep_water) ) {;}
        }

        else {//attack();
        }}

        if (dir==dir_left) { //налево
            if (levelmap[m->x-1][m->y].monster==nobody) {


            }
            if (levelmap[m->x-1][m->y].type==ground) {m->x=m->x-1;}

            if (levelmap[m->x-1][m->y].type==mud) {m->x=m->x-1;}
             if (levelmap[m->x-1][m->y].type==shallow_water) {m->x=m->x-1;}
              if (levelmap[m->x-1][m->y].type==quicksand) {m->x=m->x-1;}
            if (levelmap[m->x-1][m->y].type==wall) { ;}
            if ((levelmap[m->x-1][m->y].type==deep_water) ) {;}
            }
            else {//attack();
        }


            if (dir==dir_up) { //вверх
                if (levelmap[m->x][m->y+1].monster==nobody) {
                if (levelmap[m->x][m->y+1].type==ground) {m->y=m->y+1;}

                if (levelmap[m->x][m->y+1].type==mud) {m->y=m->y+1;}
                 if (levelmap[m->x][m->y+1].type==shallow_water) {m->y=m->y+1;}
                  if (levelmap[m->x][m->y+1].type==quicksand) {m->y=m->y+1;}
                if (levelmap[m->x][m->y+1].type==wall) { ;}
                if ((levelmap[m->x][m->y+1].type==deep_water)  ) {;}
                }
                else {//attack();
                }}

                if (dir==dir_down) { //вниз
                    if (levelmap[m->x][m->y-1].monster==nobody) {
                    if (levelmap[m->x][m->y-1].type==ground) {m->y=m->y-1;}

                    if (levelmap[m->x][m->y-1].type==mud) {m->y=m->y-1;}
                     if (levelmap[m->x][m->y-1].type==shallow_water) {m->y=m->y-1;}
                      if (levelmap[m->x][m->y-1].type==quicksand) {m->y=m->y-1;}
                    if (levelmap[m->x][m->y-1].type==wall) { ;}
                    if ((levelmap[m->x][m->y-1].type==deep_water)  ) {;}
                    }
         else {//attack();
        }}

}

//подробно расписать атаку. Шанько
void attack_monster(hero *h, monster *m ) {



    if (rand()%20+1+h->str_m>m->ac) {
        m->hp=m->hp-(rand()%6+1+h->str_m);

        cout<<"вы попали"<<endl;
        cout<<"Здоровье гоблина = "<<m->hp<<endl;}
    else{cout<<"вы не попали"<<endl;}
    if (m->hp<=0) {cout<<"Вы его убили"<<endl;}

}


void find_monster_on_xy () {

}

//Подробно расписать подбор предметов. Поручить Дорджееву
void take_loot (hero *h){
    for (int i;i<50;i++){
        if (levelmap[h->x][h->y].stuff[i]!=0){
            for (int g;g<50;g++){
                if (h->stuff[g]==0){
                    h->stuff[g]=static_cast<stuffs>(levelmap[h->x][h->y].stuff[i]);
                    levelmap[h->x][h->y].stuff[i]=static_cast<stuffs>(0);
                    break;
                }
            }
        }
    }



    }


void create_map(){
    for (int i=0;i<levelmapheight;i++) {
        levelmap[0][i].type=wall;
        levelmap[levelmapwidth-1][i].type=wall;
    }

    for (int i=0;i<levelmapwidth;i++) {
        levelmap[0][i].type=wall;
        levelmap[levelmapheight-1][i].type=wall;
    }

    for (int i=1;i<levelmapheight-1;i++) {
        for (int j=1;j<levelmapwidth-1;j++) {
            levelmap[j][i].type=static_cast<groundtype>(rand()%4);
        }
    }

}

void draw_levelmap() {
    clrscr();
    for (int j=0;j<levelmapheight;j++ ) {
        for (int i=0;i<levelmapwidth;i++) {

            if ((levelmap[i][j].type==ground) and (levelmap[i][j].monster==nobody)) {
                textbackground(BLACK);
                cout<<" ";
                textreset();}
            if (levelmap[i][j].type==wall) {
                textbackground(RED);
                textcolor(WHITE);
                cout<<"#";
                textreset();
            }
            if (levelmap[i][j].type==mud) {
                textbackground(GREEN);
                textcolor(LTGREEN);
                cout<<"0";
                textreset();
            }
            if (levelmap[i][j].type==shallow_water) {
                textbackground(LTBLUE);
                textcolor(BLUE);
                cout<<"~";
                textreset();
            }
            if (levelmap[i][j].type==deep_water) {
                textbackground(BLUE);
                textcolor(BLACK);
                cout<<"~";
                textreset();
            }




            if (levelmap[i][j].monster==zombie) {
                textcolor(CYAN);
                cout<<"Z";
                textreset();}

        }
        cout<<endl;
    }
}

void draw_levelmap_g(sf::RenderWindow *window) {
       window->clear();
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(32.0,32.0));

for (int j=0;j<levelmapheight;j++ ) {
    for (int i=0;i<levelmapwidth;i++) {

        if ((levelmap[i][j].type==ground) and (levelmap[i][j].monster==nobody)) {
            rectangle.setFillColor(sf::Color::White);
        }
        if (levelmap[i][j].type==wall) {
            rectangle.setFillColor(sf::Color::Black);;
        }
        if (levelmap[i][j].type==mud) {
            rectangle.setFillColor(sf::Color::Green);
        }
        if (levelmap[i][j].type==shallow_water) {
            rectangle.setFillColor(sf::Color::Cyan);
        }
        if (levelmap[i][j].type==deep_water) {
            rectangle.setFillColor(sf::Color::Blue);
        }




        if (levelmap[i][j].monster==zombie) {
           }


        rectangle.setPosition(i*32,j*32);
        window->draw(rectangle);



}


 }}

void draw_hero_g (sf::RenderWindow *window, int x, int y) {
    sf::CircleShape hero;
    hero.setRadius(16);
    hero.setFillColor(sf::Color::Magenta);
    hero.setPosition(x*32,y*32);
    window->draw(hero);

}


void draw_monster_g (sf::RenderWindow *window, int x, int y) {
    sf::CircleShape m;
    m.setRadius(8);
    m.setFillColor(sf::Color::Red);
    m.setPosition(x*32+8,y*32+8);
    window->draw(m);

}


int main(int argc, char *argv[])
{
   

    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML works!");

    

    hero player;
    player.x=5;
    player.y=3;
    create_map();

    monster monstro[50];
    for (int i=0;i<50;i++) {
        monstro[i].x=rand()%50;
        monstro[i].y=rand()%50;
    }



    while (window.isOpen())
    {
        sf::Event event;


        while (window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed) or ((event.KeyPressed == sf::Keyboard::Escape)))
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
           move_hero(dir_left, &player );
        }
    }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
           move_hero(dir_right, &player );
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
           move_hero(dir_up, &player );
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
           move_hero(dir_down, &player );
        }

        draw_levelmap_g(&window);
        draw_hero_g(&window,player.x,player.y);

        for (int i=0;i<50;i++) {
            draw_monster_g(&window,monstro[i].x,monstro[i].y);
        }


        for (int i=0;i<50;i++) {
            int t=rand()%4;
            if (t==0) move_monster(dir_right,&monstro[i]);

            if (t==1) move_monster(dir_left,&monstro[i]);

            if (t==2) move_monster(dir_up,&monstro[i]);

            if (t==3) move_monster(dir_down,&monstro[i]);
        }

        draw_levelmap();

    window.display();


    }

  //
  // draw_hero(player.x,player.y);



    return 0;
}
