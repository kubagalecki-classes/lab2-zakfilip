#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager()
    {
        x = new Resource;
    }
    ResourceManager(const ResourceManager& r)
    {   
        delete x;
        x = new Resource;
        *x = *r.x;
    }
    ResourceManager& operator=(const ResourceManager& r)
    {
        delete x;
        x = new Resource;
        *x = *r.x;
        return *this;
    }
    ResourceManager& operator=(ResourceManager&& r) noexcept
    {
        delete x;
        x = r.x;
        r.x = nullptr;
        return *this;
    }
    ResourceManager(ResourceManager&& r) noexcept
    {
        x = r.x;
        r.x = nullptr;
    }
    ~ResourceManager()
    {
        delete x;
        x = nullptr;
    }
    double get()
    {
        return x->get();
    }
private:
    Resource* x;
};
