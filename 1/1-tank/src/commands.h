#pragma once

#include <memory>
#include "command.h"
#include "interfaces.h"

class Move : public Command
{
    std::shared_ptr<IMovable> m_interface;
public:
    Move(std::shared_ptr<IMovable> interface) : m_interface(interface)
    {
    }
    void execute() override
    {
        m_interface->setPosition(
            m_interface->getPosition() + m_interface->getVelocity()
        );
    }
};

class Rotate : public Command
{
    std::shared_ptr<IRotating> m_interface;
public:
    Rotate(std::shared_ptr<IRotating> interface) : m_interface(interface)
    {
    }
    void execute() override
    {
        m_interface->setVelocity(
            m_interface->getVelocity().rotate(m_interface->getRotationAngle())
        );
    }
};

class BurnFuel : public Command
{
    std::shared_ptr<IFuelConsumer> m_interface;
public:
    BurnFuel(std::shared_ptr<IFuelConsumer> interface) : m_interface(interface)
    {
    }
    void execute() override
    {
        m_interface->setFuelLevel(
            m_interface->getFuelLevel() - m_interface->getFuelConsumption() 
        );
    }
};

class CheckFuel : public Command
{
    std::shared_ptr<IFuelConsumer> m_interface;
public:
    CheckFuel(std::shared_ptr<IFuelConsumer> interface) : m_interface(interface)
    {
    }
    void execute() override
    {
        if(m_interface->getFuelLevel() < m_interface->getFuelConsumption())
            throw;
    }
};
