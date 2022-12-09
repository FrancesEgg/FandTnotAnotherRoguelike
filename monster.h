#pragma once
#include <iostream>
#include "entity.h"

using namespace std;

enum monsterName
{
    snake,
    bat,
    zombie,
    wolf
};

class monster : public entity
{
public:
    monster(int h, int d);
    bool shouldAttack(player p);
    bool dead(int);

    monsterName name;
};

monster::monster(int h, int d)
{
    health = h;
    damage = d;
}

bool monster::shouldAttack(player p)
{
    if (p.getX() == 2 && p.getY() == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool monster::dead(int h)
{
    if (h <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}