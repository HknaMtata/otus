#pragma once

#include <map>
#include <any>

#include "UObject.h"
#include "vector2d.h"

class UTank : public UObject
{
    std::map<std::string, std::any> m_staff;
public:
    UTank()
    {
        // Movable
        m_staff["position"] = Vector();
        m_staff["velocity"] = Vector();
        // Rotating
        m_staff["rotationAngle"] = static_cast<int>(0);
        // FuelConsumption
        m_staff["fuelConsumption"] = static_cast<unsigned>(1);
        m_staff["fuelLevel"] = static_cast<unsigned>(100);
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