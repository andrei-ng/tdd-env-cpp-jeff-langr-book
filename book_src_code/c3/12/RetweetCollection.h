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
#include <set>

class RetweetCollection {
public:
   RetweetCollection() 
      : size_(0) {
   }

   bool isEmpty() const {
      return 0 == size();
   }

   void add(const Tweet& tweet) {
      tweets.insert(tweet);
      ++size_;
   }

   unsigned int size() const {
      return tweets.size();
   }

   void remove(const Tweet& tweet) {
      --size_;
   }

private:
   unsigned int size_;
   std::set<Tweet> tweets;
};
#endif
