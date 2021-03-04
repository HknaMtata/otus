#pragma once

#include <iostream>

#include <string>
#include <any>
#include <map>

typedef int /*std::pair<int, int>*/ Vector;

class UObject
{
public:
    virtual const std::any& operator[](const std::string&) const = 0;
    virtual std::any& operator[](const std::string&) = 0;
};

class Command
{
public:
    virtual void execute() = 0;
};

class UGun : public UObject
{
    std::map<std::string, std::any> m_staff;
public:
    UGun()
    {
        // Rotating
        m_staff["position"] = 0;
        m_staff["velocity"] = 0;
    }
    const std::any& operator[](const std::string& key) const override
    {
        return m_staff.at(key);
    }
    std::any& operator[](const std::string& key) override
    {
        return m_staff.at(key);
    }
};

class UTank : public UObject
{
    std::map<std::string, std::any> m_staff;
public:
    UTank()
    {
        // Movable
        m_staff["position"] = 0;
        m_staff["velocity"] = 0;
        // FuelConsumption
        m_staff["fuelConsumption"] = 1;
    }
    const std::any& operator[](const std::string& key) const override
    {
        return m_staff.at(key);
    }
    std::any& operator[](const std::string& key) override
    {
        return m_staff.at(key);
    }
};



class IMovable
{
public:
	virtual Vector getPosition() const = 0;
	virtual void setPosition(Vector) = 0;
	virtual Vector getVelocity() const = 0;
};

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
	void setPosition(Vector pos) override
    {
        m_obj["position"] = pos;
    }
	Vector getVelocity() const override
    {
        return std::any_cast<Vector>(m_obj["velocity"]);
    }
};

class Move : public Command
{
    IMovable& m_interface;
public:
    Move(IMovable& interface)
        : m_interface(interface)
    {
    }
    void execute() override
    {
        m_interface.setPosition(m_interface.getPosition() + m_interface.getVelocity());
    }
};



class IRotating
{
public:
	virtual void setRotationDirection(Vector) = 0;
	virtual Vector getRotationDirection() const = 0;
	virtual Vector getAngularVelocity() const = 0;
};

class RotatingAdapter : public IRotating
{
    UObject& m_obj;
public:
    RotatingAdapter(UObject& obj)
        : m_obj(obj)
    {
    }
	Vector getRotationDirection() const override
    {
        return std::any_cast<Vector>(m_obj["rotationDirection"]);
    }
	void setRotationDirection(Vector rotationDirection) override
    {
        m_obj["rotationDirection"] = rotationDirection;
    }
	Vector getAngularVelocity() const override
    {
        return std::any_cast<Vector>(m_obj["angularVelocity"]);
    }
};

class Rotate : public Command
{
    IRotating& m_interface;
public:
    Rotate(IRotating& interface)
        : m_interface(interface)
    {
    }
    void execute() override
    {
        std::cout << __func__ << std::endl;
        m_interface.setRotationDirection((m_interface.getRotationDirection() + m_interface.getAngularVelocity()));
    }
};