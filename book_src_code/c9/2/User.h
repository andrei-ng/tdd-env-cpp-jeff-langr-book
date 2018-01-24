/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef User_h
#define User_h
#include "Location.h"

class User {
public:
   User(const std::string& name, Location location) 
      : name_(name), location_(location) {}
   std::string name() { return name_; }
   Location location() { return location_; }

private:
   std::string name_;
   Location location_;
};
#endif
