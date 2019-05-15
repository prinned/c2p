#include <iostream>
#include <vector>
#include <random>
#include <string>
using std::cout;

class Warrior{
private:
    std::string name;
    int HP;
    int damage;
    int DV;
    int PV;

    static int totalWarriors;

    friend class Battle;
public:
    std::string getName(){return name;}
    int getDamage(){return damage;}
    int getDV(){return DV;}
    int getHP(){return HP;}
    Warrior(std::string name, int HP, int damage, int DV, int PV);
    void setAll(std::string name, int HP, int damage, int DV);
    Warrior();
};

int Warrior::totalWarriors = 0;

Warrior::Warrior(std::string name, int HP, int damage, int DV, int PV){
    this -> name = name;
    this -> damage = damage;
    this -> HP = HP;
    this -> DV = DV;
    this -> PV = PV;
    totalWarriors++;
}

Warrior::Warrior(){
    this -> name = "Random Guy";
    this -> damage = 20;
    this -> HP = 100;
    this -> DV = 10;
    this -> PV = 5;
    totalWarriors++;
}

void Warrior::setAll(std::string name, int HP, int damage, int DV){
    this -> name = name;
    this -> damage = damage;
    this -> HP = HP;
    this -> DV = DV;
    this -> PV = PV;
}

class Battle : public Warrior{
public:
    static void fight(Warrior fighter1, Warrior fighter2);
    static void hit(Warrior& hitter, Warrior& hittee);
};

void Battle::hit(Warrior& hitter, Warrior& hittee){
    if ( rand() % (10+ hittee.DV) < 10 ){ //if a random number from 0 to (10 + DV) is less than 10 
        int damage_inflicted = (hittee.PV - hitter.damage > 0) ? 0: (hittee.PV - hitter.damage); // reduce hp by (damage - PV)
        hittee.HP += damage_inflicted;
        cout<<hitter.name<<" has struck "<<hittee.name<<" reducing his HP by "<<damage_inflicted<<" hitpoints!\n"
            <<hittee.name<<" now has "<<hittee.HP<<" hitpoints!\n";
    }else{
        cout<<hitter.name<<" misses!\n"
            <<hittee.name<<" still has "<<hittee.HP<<" hitpoints!\n";
    }
}

void Battle::fight(Warrior fighter1, Warrior fighter2){
    while ( fighter1.HP > 0 && fighter2.HP > 0 ) {
        Battle::hit(fighter1,fighter2); //"Battle::" was unneeded but added for understandability(?)
        if (fighter2.HP <= 0){
            break;
        }
        Battle::hit(fighter2,fighter1); //again, "Battle::" was unnecessary
        char i = std::cin.get();
    }
    cout<<((fighter1.HP > 0)? fighter1.name:fighter2.name)<<" has won!";
}

int main(){
    //name, hp, damage, dv, pv
    Warrior vivek("vivek", 1, 10, 1000, 0); 
    Warrior lasya("screw loose", 100, 100, 0, 1000);
    Battle::fight(vivek,lasya);
    return 0;
}