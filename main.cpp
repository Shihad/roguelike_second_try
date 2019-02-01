#include <iostream>

using namespace std;

enum monsters {nobody,zombie, ghoul,vampire,necromancer,spectre,demon };
enum hero_class{warrior, mage, monk, rogue};
enum hero_race{human,dwarf,elf,hobbit,half_elf};
enum hero_gender{male,female};
enum weapons{fist,knife,dagger,sword,axe,hammer};
enum armours{robe,tegiley,chainmall,brigand,cuirass,fullarmour};
enum helmets{nonhelmet,cap,steelhelmet};
enum amulets{noamulet,amuletofdoom,amuletoffire};
enum stuffs{};
enum inventary{rope,potion_maxhp,potion_hp};
enum groundtype{wall,ground,mud,shallow_water,deep_water,quicksand,trap,found_trap,ladder_up,ladder_down};


struct cell {

    int x,y; //положение
    groundtype type; //тип клетки
    int stuff[50];
    monsters monster;

};

struct hero {
    //Создадим Героя
    hero_class hclass;
    hero_race hrace;

    weapons weapon;
    armours armour;
    helmets helmet;
    amulets amulet1,amulet2;
    inventary inv[50];
    int move(int x,int y){
                 int move_left=x-1;
                 int move_right=x+1;
                 int move_up=y+1;
                 int move_down=y-1;
                 return move;

                   }

    stuffs stuff[50];


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

    int x,y;
    int atack;



};

hero create_hero() {
    hero myhero;
    myhero.hclass=warrior;
    myhero.hrace=elf;
    myhero.hgender=female;
    return myhero;
}



int main(int argc, char *argv[])
{
    hero hero1;
    hero1=create_hero();
    hero.x=3;
    hero.y=2;


    cell map[10][10];

    map[5][5].monster=zombie;

    for (int i=0;i<10;i++) {
        map[0][i].type=wall;
        map[9][i].type=wall;
        map[i][0].type=wall;
        map[i][9].type=wall;
    }
    cin>>move;
    while(map[j][i]=shallow_water,ground,mud,quicksand){
    if(move=w){
        move_up;
    }
    if(move=s){
        move_down;
    }
    if(move=a){
        move_left;
    }
    if(move=d){
        move_right;
    }
}



    for (int j=1;j<9;j++ ) {
        for (int i=1;i<9;i++) {
            map[i][j].type==rand()%2;

        }
    }

    map[5][5].type=ground;
    for (int j=0;j<10;j++ ) {
        for (int i=0;i<10;i++) {
            if ((map[i][j].type==0) and (map[i][j].monster==nobody)) {cout<<" ";}
            if (map[i][j].type==1) {cout<<"#";}


            if (map[i][j].monster==zombie) {cout<<"Z";}
        }
        cout<<endl;
    }



    cout << "Hello World!" << endl;
    return 0;
}
