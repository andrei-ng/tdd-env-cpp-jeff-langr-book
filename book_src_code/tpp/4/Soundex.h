/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Soundex_h
#define Soundex_h

class Soundex {
public:
   std::string encode(const std::string& word) const {
      std::string code("");
      code += word[0];
      if (word[1])
         code += "100";
      else
         code += "000";
      return code;
   }
};
#endif
