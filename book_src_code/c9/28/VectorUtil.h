/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef VectorUtil_h
#define VectorUtil_h

#include <vector>
#include <functional>
#include <algorithm>

template<typename TFrom, typename TTo> std::vector<TTo> Collect(
      const std::vector<TFrom>& source,
      std::function<TTo(TFrom)> func) {
   std::vector<TTo> results;
   std::transform(source.begin(), source.end(), std::back_inserter(results), func);
   return results;
}

#endif
