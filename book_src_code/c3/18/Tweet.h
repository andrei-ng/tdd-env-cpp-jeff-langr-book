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
#include <stdexcept>
#include <iostream>

class InvalidUserException: public std::invalid_argument {
public:
   InvalidUserException(const std::string& user) 
      : std::invalid_argument(user) {}
};

class Tweet {
public:
   static const std::string NULL_USER;
   Tweet(const std::string& message="", 
         const std::string& user=Tweet::NULL_USER) 
      : message_(message)
      , user_(user) {
      if (!isValid(user_)) throw InvalidUserException(user_);
   }

   bool isValid(const std::string& user) const {
      return '@' == user[0];
   }

   std::string user() const {
      return user_;
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
