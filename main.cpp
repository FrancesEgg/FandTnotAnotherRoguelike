#include <iostream>
#include <array>
#include <cctype>
#include "entity.h"
#include "player.h"
#include "monster.h"

using namespace std;

int main()
{
    player::coord normal = {2, 4};

    player p(normal, 15, 10, 1);
    monster m(5, 5);

    while (p.getLevel() == 1)
    {
        char choice;
        p.outputArray(p);
        cout << "Make a choice: \n(N)orth\n(E)ast\n(S)outh\n(W)est\n(I)nvestigate\n(A)ttack\n";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'N' || choice == 'E' || choice == 'S' || choice == 'W')
        {
            p.move(choice);
        }
        else if (choice == 'A')
        {
            cout << "there's nothing to attack on this floor" << endl;
        }
        else if (choice == 'I')
        {
            p.investigate(p);
        }
    }
    player::coord temp = {1, 5};
    p.setCoord(temp);
    char choice;
    while (p.getLevel() == 2)
    {

        choice = ' ';
        p.outputArray(p);
        cout << "Make a choice: \n(N)orth\n(E)ast\n(S)outh\n(W)est\n(I)nvestigate\n(A)ttack\n";
        cin >> choice;
        choice = toupper(choice);
        if (m.shouldAttack(p) == true && m.dead(m.getHealth()) == false)
        {
            p.setHealth(m.attack(p));
            if (p.isDead(p.getHealth()) == true)
            {
                cout << "The monster slayed you";
                break;
            }
        }
        if (choice == 'N' || choice == 'E' || choice == 'S' || choice == 'W')
        {
            p.move(choice);
        }
        else if (choice == 'A')
        {
            m.setHealth(p.attack(m));
            if (m.getHealth() <= 0)
            {
                m2[2][3] = '*';
                cout << "killed a monster";
            }
        }
        else if (choice == 'I')
        {
            p.investigate(p);
        }
    }

    return 0;
}
