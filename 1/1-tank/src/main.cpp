#include <iostream>
#include <vector>
#include "tank.h"


class ShootingAdapter;
class Shoot;

int main()
{
    UTank a;

    UGun g;
    a["gun"] = g;

    MovableAdapter movable(a);
    Move moveCmd(movable);

    ShootingAdapter shooting(g);
    Shoot shootCmd(shooting);

    RotatingAdapter rotating(g);
    Rotate rotateCmd(rotating);

    {
        ShootingAdapter gunShooting(g);
        Shoot gunShootCmd(shooting);
    }

    std::vector<Command&> cmds = {
        moveCmd,
        rotateCmd,
        shootCmd
    };

    {
        MovableAdapter movable(a);
        Move moveCmd(movable);
        for(;;)
        {
            a["velocity"] = rand() % 5;
            moveCmd.execute();

            std::cout << std::any_cast<int>(a["position"]); // << std::endl;
            std::cin.get();
        }
    }

    return 0;
}