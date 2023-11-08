#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include "IDB.hpp"

class HTTP : public IDB
{
public:
    HTTP() {};

    void Create() const;
    void Read() const;
    void Update() const;
    void Delete() const;

    ~HTTP() {};
};
