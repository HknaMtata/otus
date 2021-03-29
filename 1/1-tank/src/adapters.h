#pragma once

#include "UObject.h"
#include "interfaces.h"

class MovableAdapter : public IMovable
{
    UObject& m_obj;
public:
    MovableAdapter(UObject& obj)
        : m_obj(obj)
    {
    }
	Vector getPosition() const override
    {
        return std::any_cast<Vector>(m_obj["position"]);
    }
	void setPosition(const Vector& pos) override
    {
        m_obj["position"] = pos;
    }
	Vector getVelocity() const override
    {
        return std::any_cast<Vector>(m_obj["velocity"]);
    }
};

class RotatingAdapter : public IRotating
{
    UObject& m_obj;
public:
    RotatingAdapter(UObject& obj)
        : m_obj(obj)
    {
    }
	Vector getVelocity() const override
    {
        return std::any_cast<Vector>(m_obj["velocity"]);
    }
	void setVelocity(const Vector &velocity) override
    {
        m_obj["velocity"] = velocity;
    }
	int getRotationAngle() const override
    {
        return std::any_cast<int>(m_obj["rotationAngle"]);
    }
};

class FuelConsumptionAdapter : public IFuelConsumer
{
    UObject& m_obj;
public:
    FuelConsumptionAdapter(UObject& obj)
        : m_obj(obj)
    {
    }
    unsigned getFuelConsumption() const override
    {
        return std::any_cast<unsigned>(m_obj["fuelConsumption"]);
    }
	void setFuelLevel(const unsigned &fuelLevel) override
    {
        m_obj["fuelLevel"] = fuelLevel;
    }
	unsigned getFuelLevel() const override
    {
        return std::any_cast<unsigned>(m_obj["fuelLevel"]);
    }
};