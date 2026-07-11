#pragma once

#include "Export.h"

namespace fe
{

class FE_API Script
{
public:

    virtual void OnStart() {}
    virtual void OnUpdate() {}
    virtual void OnTickUpdate() {}

    virtual ~Script() {}
};

}