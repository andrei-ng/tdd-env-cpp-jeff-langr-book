/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Portfolio_h
#define Portfolio_h

#include <string>
#include <exception>

class InvalidPurchaseException: public std::exception {
};


class Portfolio {
public:
   Portfolio();
   bool IsEmpty() const;
   void Purchase(const std::string& symbol, unsigned int shareCounr);
   unsigned int ShareCount(const std::string& symbol) const;

private:
   unsigned int shareCount_;
};

#endif
