#pragma once

#include <libpq-fe.h>
#include <iostream>
#include "IDB.hpp"

class DB : public IDB
{
public:
    DB() {};
    void Create();
    void Read();
    void Update();
    void Delete();
    ~DB() {};
};

