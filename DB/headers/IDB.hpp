#pragma once

#include <iostream>

class IDB
{
private:
    
public:
    virtual void Create() const = 0;
    virtual void Read() = 0;
    virtual void Update() const = 0;
    virtual void Delete() const = 0;
    virtual ~IDB() {};
};