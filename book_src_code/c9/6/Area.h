/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Area_h
#define Area_h

#include "Location.h"

class Area {
public:
   Area(const Location& location, double width, double height);
   Location upperLeft() const;
   Location upperRight() const;
   Location lowerRight() const;
   Location lowerLeft() const;
   bool inBounds(const Location&) const;

private:
   double left_;
   double right_;
   double top_;
   double bottom_;
};

#endif
