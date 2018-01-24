/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef FileUtil_h
#define FileUtil_h

#include <ios>
#include <istream>
#include <fstream>
#include <functional>

class FileUtil {
public:
   virtual std::streamsize size(const std::string& name) {
      std::ifstream stream{name, std::ios::in | std::ios::binary};
      stream.seekg(0, std::ios::end);
      return stream.tellg();
   }

   std::streamsize execute(
         const std::string& name, 
         std::function<std::streamsize (std::istream&)> func) {
      std::ifstream stream{name, std::ios::in | std::ios::binary};
      return func(stream);
   }
};
#endif
