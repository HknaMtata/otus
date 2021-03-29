#pragma once

#include <any>
#include <string>

class UObject
{
public:
    virtual const std::any& operator[](const std::string&) const = 0;
    virtual std::any& operator[](const std::string&) = 0;
};