#pragma once
#include "Resource.hpp"
class ResourceManager
{
public:
  ResourceManager()
  {
    resource_ptr = new Resource();
  }
  ~ResourceManager()
  {
    delete resource_ptr;
  }
  ResourceManager(const ResourceManager& other)
  {
    resource_ptr = new Resource(*other.resource_ptr);
  }
  ResourceManager& operator=(const ResourceManager& other)
  {
    if (this != &other) {
      delete resource_ptr;
      resource_ptr = new Resource(*other.resource_ptr);
    }
    return *this;
  }
  double getResourceValue() const
  {
    return (*resource_ptr).tab[Resource::get_index];
  }
  double get()
  {
    return (*resource_ptr).get();
  }
private:
  Resource* resource_ptr;
};