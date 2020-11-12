#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager()
    {
        x = new Resource;
    }
    ResourceManager(ResourceManager& r)
    {
        x = r.x;
    }
    ResourceManager& operator=(ResourceManager& r)
    {
        this->x = r.x;
        return r;
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
    }
    double get()
    {
        return x->get();
    }
private:
    Resource* x;
};
