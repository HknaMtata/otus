#pragma once

#include <map>
#include "vector2d.h"

class IMovable
{
public:
	virtual Vector getPosition() const = 0;
	virtual void setPosition(const Vector&) = 0;
	virtual Vector getVelocity() const = 0;
};

class IRotating
{
public:
	virtual Vector getVelocity() const = 0;
	virtual void setVelocity(const Vector&) = 0;
	virtual int getRotationAngle() const = 0;
};

class IFuelConsumer
{
public:
	virtual unsigned getFuelConsumption() const = 0;
	virtual void setFuelLevel(const unsigned&) = 0;
	virtual unsigned getFuelLevel() const = 0;
};