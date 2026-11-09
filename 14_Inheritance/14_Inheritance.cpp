#include <iostream>
using namespace std;

class Enemy {
protected:
    string name;
    int health;
    float strength;
    static const int maxHealth = 100;
public:
    Enemy():name("None"),health(maxHealth), strength(0){}
    Enemy(string name,float s):name(name),health(maxHealth), strength(s){}
    void Print()const {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Strength: " << strength << endl;
    }
    void DecreaseHealth(int value) {
        if (health - value < 0)
        {
            health = 0;
        }
        else {
            health -= value;

        }
    }
    void Fight(float damage) {
        cout << "Getting damage: " << damage << '%' << endl;
        DecreaseHealth(damage);
        cout << "Health after damage: " << health << "%" << endl;
    }
    float Attack() {
        cout << "Attacking with strenght: " << strength << "%" << endl;
        return strength;
    }
    bool IsAlive() const{
        return health > 0;
    }

};
class Dragon: public Enemy {
    float armor;
public:
    Dragon():armor(0),Enemy(){}
    Dragon(string n, float s, float a):armor(a),Enemy(n,s){}
    void Fight(int damage) {
        Enemy::Fight(damage - armor);
    }
    void Print()const {
        cout << "--------------Dragon-----------------" << endl;
        Enemy::Print();
        cout << "Armour: " << armor << endl;
    }

};

class Wizard : public Enemy {
    float turbo_attack;
public:
    Wizard():turbo_attack(0),Enemy()
    {

    }
    Wizard(string n,float s, float t):turbo_attack(t),Enemy(n,s)
    {

    }
    float AttackWithTurbopower() {
        cout << "Attacking with turbo power: " << turbo_attack << endl;
        return turbo_attack;
    }
    void Print()const {
        cout << "--------------Wizard-----------------" << endl;
        Enemy::Print();
        cout << "Turbo attack power: " << turbo_attack+strength << endl;
    }
};
int main()
{
    Dragon dragon("Vasya",5,2);
    Dragon boss("Boss",7,4);
    do
    {
        dragon.Fight(boss.Attack());
        boss.Fight(dragon.Attack());

        dragon.Print();
        boss.Print();
    } while (boss.IsAlive() && dragon.IsAlive());
   
    
}
