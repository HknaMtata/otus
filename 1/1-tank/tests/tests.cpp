#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "objects.h"
#include "adapters.h"
#include "commands.h"

TEST(Tank, accessToTankFields)
{
    UTank tank;

    // Movable
    ASSERT_NO_THROW(std::any_cast<Vector>(tank["position"]));
    ASSERT_NO_THROW(std::any_cast<Vector>(tank["velocity"]));
    // Rotating
    ASSERT_NO_THROW(std::any_cast<int>(tank["rotationAngle"]));
    // FuelConsumption
    ASSERT_NO_THROW(std::any_cast<unsigned>(tank["fuelConsumption"]));
    ASSERT_NO_THROW(std::any_cast<unsigned>(tank["fuelLevel"]));
}

TEST(Tank, adapters)
{
    UTank tank;

    EXPECT_NO_THROW(
        MovableAdapter movable(tank);
	    movable.getPosition();
	    movable.setPosition(Vector(0,0));
	    movable.getVelocity();
    );
 
    EXPECT_NO_THROW(
        RotatingAdapter rotating(tank);
        rotating.getVelocity();
	    rotating.setVelocity(Vector(0,0));
	    rotating.getRotationAngle();
    );

    EXPECT_NO_THROW(
        FuelConsumptionAdapter fuelConsumption(tank);
        fuelConsumption.getFuelConsumption();
	    fuelConsumption.setFuelLevel(4);
	    fuelConsumption.getFuelLevel();
    );
}

TEST(Tank, commands)
{
    UTank tank;

    tank["velocity"] = Vector(1, 1);

    Move moveCmd(std::make_shared<MovableAdapter>(tank));
    Rotate rotateCmd(std::make_shared<RotatingAdapter>(tank));
    CheckFuel checkFuelCmd(std::make_shared<FuelConsumptionAdapter>(tank));
    BurnFuel burnFuelCmd(std::make_shared<FuelConsumptionAdapter>(tank));

    EXPECT_NO_THROW(
        checkFuelCmd.execute();
        rotateCmd.execute();
        moveCmd.execute();
        burnFuelCmd.execute();
    );
}


// class ShootingAdapter;
// class Shoot;

// int main()
// {
//     UTank a;

//     UGun g;
//     a["gun"] = g;

//     MovableAdapter movable(a);
//     Move moveCmd(movable);

//     ShootingAdapter shooting(g);
//     Shoot shootCmd(shooting);

//     RotatingAdapter rotating(g);
//     Rotate rotateCmd(rotating);

//     {
//         ShootingAdapter gunShooting(g);
//         Shoot gunShootCmd(shooting);
//     }

//     std::vector<Command&> cmds = {
//         moveCmd,
//         rotateCmd,
//         shootCmd
//     };

//     {
//         MovableAdapter movable(a);
//         Move moveCmd(movable);
//         for(;;)
//         {
//             a["velocity"] = rand() % 5;
//             moveCmd.execute();

//             std::cout << std::any_cast<int>(a["position"]); // << std::endl;
//             std::cin.get();
//         }
//     }

//     return 0;
// }

// for(;;)
// {
//     try {
//         checkFuelCmd.execute();
//         rotateCmd.execute();
//         moveCmd.execute();
//         burnFuelCmd.execute();

//         std::cout << std::any_cast<Vector>(tank["position"]);
//         std::cin.get();
//     } catch (...) {
//         std::cout << "Приехали!" << std::any_cast<Vector>(tank["position"]);
//     }
// }