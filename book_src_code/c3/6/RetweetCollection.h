/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef RetweetCollection_h
#define RetweetCollection_h

#include "Tweet.h"

class RetweetCollection {
public:
   RetweetCollection() 
      : empty_(true) {
   }

   bool isEmpty() const {
      return empty_;
   }

   void add(const Tweet& tweet) {
      empty_ = false;
   }

   unsigned int size() const {
      return isEmpty() ? 0 : 1;
   }

private:
   bool empty_;
};
#endif
