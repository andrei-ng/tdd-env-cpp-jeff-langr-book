/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef PurchaseRecord_h
#define PurchaseRecord_h

#include "boost/date_time/gregorian/gregorian_types.hpp"

struct PurchaseRecord {
   PurchaseRecord(int shareCount, const boost::gregorian::date& date)
      : ShareCount(shareCount)
      , Date(date) {
   }
   int ShareCount;
   boost::gregorian::date Date;
};

#endif
