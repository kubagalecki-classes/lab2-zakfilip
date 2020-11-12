#pragma once

#include "Resource.hpp"
using namespace std;

class ResourceManager
{
public:
	ResourceManager()
	{
		x = 0;
	}
	ResourceManager(ResourceManager& r)
	{
		x = r.get();
	}
	ResourceManager& operator=(ResourceManager& r)
	{
		delete x;
		x = r.get();
		return r;
	}
	ResourceManager& operator=(ResourceManager&& r)
	{
		delete x;
		x = r.x;
		r.x = nullptr;
		return *this;
	}
	ResourceManager(ResourceManager&& r)
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
