/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Tweet_h
#define Tweet_h

#include <string>

class Tweet {
public:
   Tweet(const std::string& message="", const std::string& user="") 
      : message_(message)
      , user_(user) {
   }

   bool operator==(const Tweet& rhs) const {
      return message_ == rhs.message_ &&
         user_ == rhs.user_;
   }

   bool operator!=(const Tweet& rhs) const {
      return !(*this == rhs);
   }

   bool operator<(const Tweet& rhs) const {
      if (user_ == rhs.user_)
         return message_ < rhs.message_;
      return user_ < rhs.user_;
   }

private:
   std::string message_;
   std::string user_;
};
#endif
