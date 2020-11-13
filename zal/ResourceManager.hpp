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
        x = r.x;
    }
    ResourceManager& operator=(const ResourceManager& r)
    {
        if (&r == this)
            return *this;
        this->x = r.x;
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
        x = nullptr;
        delete x;
    }
    double get()
    {
        return x->get();
    }
private:
    Resource* x;
};
