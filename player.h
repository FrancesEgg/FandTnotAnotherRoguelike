#pragma once
#include <iostream>
#include <array>
#include <cctype>
#include "entity.h"

using namespace std;

enum directions
{
    N = 1, //orth
    E,     //ast
    S,     //outh
    W      //est
};
//player would start at (2,4)
//                 0    1    2    3    4
char m1[5][5] = {{' ', '|', 'o', '|', ' '},  //0
                 {' ', '|', '*', '|', ' '},  //1
                 {' ', '|', '*', '|', ' '},  //2
                 {' ', '|', '*', '|', ' '},  //3
                 {' ', '|', '*', '|', ' '}}; //4

char m2[6][6] = {
    //player would start at (1,5)
    //Monster at (3,2)
    //Treasure at(4,4)
    //0    1    2    3    4    5
    {' ', ' ', ' ', ' ', ' ', ' '}, //0
    {'|', '|', '|', '|', '|', ' '}, //1
    {'|', '*', '*', 'M', '|', ' '}, //2
    {'|', '*', '|', '*', '|', '|'}, //3
    {'|', '*', '|', '*', '*', 'o'}, //4
    {'|', '*', '|', '|', '|', '|'}, //5
};

class player : public entity
{
public:
    struct coord
    {
        int x;
        int y;
    };
    player(coord, int, int, int);
    void investigate(player p);
    void move(char dir);
    coord getCoord();
    void setCoord(coord);
    int getLevel();
    void outputArray(player p);
    int getX();
    int getY();
    bool isDead(int h);

private:
    int level;
    coord coordinates;
};

player::player(coord c, int h, int d, int l)
{
    health = h;
    damage = d;
    level = l;
    setCoord(c);
}

void player::investigate(player p)
{
    if (getLevel() == 1)
    {
        cout << "You see a long stone hallway with a hole at the end. In the hole is a ladder." << endl;
    }
    else if (getLevel() == 2)
    {
        cout << "You are surrounded by stone walls. And to the side you see a map engraved in the stone: " << endl;
        outputArray(p);

        cout << endl;
    }
}

// void player::attack(entity e)
// {
//     e.setHealth(e.getHealth() - getDamage());
// }

bool player::isDead(int h)
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

int player::getX()
{
    return coordinates.x;
}

int player::getY()
{
    return coordinates.y;
}

player::coord player::getCoord()
{
    return coordinates;
}

void player::setCoord(coord c)
{
    coordinates = c;
    if (getLevel() == 1)
    {
        m1[c.y][c.x] = 'P';
    }
    else if (getLevel() == 2)
    {
        m2[c.y][c.x] = 'P';
    }
}

int player::getLevel()
{
    return level;
}

void player::move(char dir)
{
    if (level == 1)
    {
        switch (dir)
        {
        case 'N':
            if (coordinates.y >= 0 && (m1[coordinates.y - 1][coordinates.x] == '*' || m1[coordinates.y - 1][coordinates.x] == 'o'))
            {
                m1[coordinates.y][coordinates.x] = '*';
                coordinates.y--;
            }
            break;
        case 'E':
            if (coordinates.x < 5 && m1[coordinates.y][coordinates.x + 1] != '|')
            {
                m1[coordinates.y][coordinates.x] = '*';
                coordinates.x++;
            }
            break;
        case 'S':
            if (coordinates.y < 5 && m1[coordinates.y + 1][coordinates.x] != '|')
            {
                m1[coordinates.y][coordinates.x] = '*';
                coordinates.y++;
            }
            break;

        case 'W':
            if (coordinates.x >= 0 && m1[coordinates.y][coordinates.x - 1] != '|')
            {
                m1[coordinates.y][coordinates.x] = '*';
                coordinates.x--;
            }
            break;

        default:
            break;
        }
        if (m1[coordinates.y][coordinates.x] == 'o')
        {
            char choice;
            cout << "You are about to decend. Would you like to continue? (Y)es or (N)o: ";
            cin >> choice;
            choice = toupper(choice);
            if (choice == 'Y')
            {
                string decendMsg = "You decend. You cannot go back.";
                cout << decendMsg;
                level++;
            }
            else
            {
                cout << "perhaps not yet." << endl;
            }
        }
    }
    else if (level == 2)
    {
        switch (dir)
        {
        case 'N':
            if (coordinates.y >= 0 && m2[coordinates.y - 1][coordinates.x] != '|')
            {
                m2[coordinates.y][coordinates.x] = '*';
                coordinates.y--;
            }
            break;
        case 'E':
            if (m2[getY()][getX() + 1] == 'M')
            {
                cout << "you cannot move there! There is a monster!";
                //monster.attack();
                break;
            }
            else if (coordinates.x < 5 && m2[getY()][getX() + 1] != '|')
            {
                //coordinates.x--;
                m2[coordinates.y][coordinates.x] = '*';
                coordinates.x++;
            }
            break;
        case 'S':
            if (coordinates.y < 5 && m2[coordinates.y + 1][coordinates.x] != '|')
            {
                m2[coordinates.y][coordinates.x] = '*';
                coordinates.y++;
            }
            break;

        case 'W':
            if (coordinates.x >= 0 && m2[coordinates.y][coordinates.x - 1] != '|')
            {
                m2[coordinates.y][coordinates.x] = '*';
                coordinates.x--;
            }
            break;

        default:
            break;
        }
        if (m2[coordinates.y][coordinates.x] == 'o')
        {
            char choice;
            cout << "You are about to decend. Would you like to continue? (Y)es or (N)o: ";
            cin >> choice;
            choice = toupper(choice);
            if (choice == 'Y')
            {
                string decendMsg = "You decend. You cannot go back.";
                cout << decendMsg;
                level++;
            }
            else
            {
                cout << "perhaps not yet." << endl;
            }
        }
    }
    coord temp = {coordinates.x, coordinates.y};
    setCoord(temp);
}
void player::outputArray(player p)
{
    if (p.getLevel() == 1)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {

                cout << m1[i][j];
            }
            cout << endl;
        }
    }
    else if (p.getLevel() == 2)
    {
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {

                cout << m2[i][j];
            }
            cout << endl;
        }
    }
    cout << "\nHealth: " << getHealth() << endl;
}