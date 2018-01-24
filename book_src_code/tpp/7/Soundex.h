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
   Soundex() {
      codes_['b'] = "1";
      codes_['c'] = "2";
   }
   // ...

   std::string encode(const std::string& word) const {
      std::string code("");
      code += head(word) + encodeTail(word);
      return zeroPad(code);
   }

   char head(const std::string& word) const {
      return word[0];
   }

   std::string encodeTail(const std::string& word) const {
      if (word[1] == 0) return "";
     return codes_[static_cast<size_t>(word[1])];
   }
   // ...

   std::string zeroPad(const std::string& code) const {
      return code + (hasEncodedCharacters(code) ? "00" : "000");
   }

   bool hasEncodedCharacters(const std::string& code) const {
      return code[1] != 0;
   }

private:
   std::string codes_[128];
};

#endif
