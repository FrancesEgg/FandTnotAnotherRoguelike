#pragma once
#include <iostream>

using namespace std;

class entity
{
public:
    entity();
    entity(int health, int damage);
    int attack(entity);
    int getHealth();
    int getDamage();
    void takeDamage(int);
    void setDamage(int);
    void setHealth(int);

protected:
    int health, damage;
};

entity::entity()
{
    setHealth(10);
    setDamage(5);
}

entity::entity(int health, int damage)
{
    setHealth(health);
    setDamage(damage);
}
//a is the attacker and v is the victim
int entity::attack(entity v)
{
    v.takeDamage(getDamage());
    return v.health;
}

int entity::getHealth()
{
    return health;
}

int entity::getDamage()
{
    return damage;
}

void entity::takeDamage(int d)
{
    this->health -= d;
    setHealth(health);
}

void entity::setDamage(int d)
{
    this->damage = d;
}

void entity::setHealth(int h)
{
    this->health = h;
}