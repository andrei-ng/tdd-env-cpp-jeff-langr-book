/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Holding_h
#define Holding_h

#include "PurchaseRecord.h"

class Holding {
public:
   void Add(PurchaseRecord& record) {
      purchaseRecords_.push_back(record);
   }

   std::vector<PurchaseRecord> Purchases() const {
      return purchaseRecords_;
   }

   unsigned int ShareCount() const {
      return accumulate(purchaseRecords_.begin(), purchaseRecords_.end(), 0, 
         [] (int total, PurchaseRecord record) { 
             return total + record.ShareCount; });
   }

private:
   std::vector<PurchaseRecord> purchaseRecords_;
};
#endif
