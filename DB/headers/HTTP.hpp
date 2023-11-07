#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include "IDB.hpp"

class HTTP : private IDB
{
private:
    
public:
    HTTP() {};

    void Create() const;
    void Read() const;
    void Update() const;
    void Delete() const;

    ~HTTP() {};
};
