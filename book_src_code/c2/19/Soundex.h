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

#include <string>
#include <unordered_map>
// ...

class Soundex
{
public:
   static const size_t MaxCodeLength{4};

   std::string encode(const std::string& word) const {
      return zeroPad(head(word) + encodedDigits(word));
   }

private:
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }

   std::string encodedDigits(const std::string& word) const {
      if (word.length() > 1) return encodedDigit(word[1]);
      return "";
   }

   std::string encodedDigit(char letter) const {
      const std::unordered_map<char,std::string> encodings {
         {'b', "1"},
         {'c', "2"},
         {'d', "3"}
      };
      return encodings.find(letter)->second;
   }

   std::string zeroPad(const std::string& word) const {
      auto zerosNeeded = MaxCodeLength - word.length();
      return word + std::string(zerosNeeded, '0');
   }
};

#endif
