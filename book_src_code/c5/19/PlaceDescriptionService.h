/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef PlaceDescriptionService_h
#define PlaceDescriptionService_h

#include <string>
#include <memory>
#include "Address.h"
#include "AddressExtractor.h"
#include "Http.h"

template<typename HTTP>
class PlaceDescriptionServiceTemplate {
public:
   // ...
   std::string summaryDescription(
         const std::string& latitude, const std::string& longitude) {
      auto request = createGetRequestUrl(latitude, longitude);
      auto response = get(request);
      return summaryDescription(response);
   }

   // mocks in tests need the reference
   HTTP& http() {
      return http_;
   }
private:
   // ...
   std::string summaryDescription(const std::string& response) const {
      AddressExtractor extractor;
      auto address = extractor.addressFrom(response);
      return address.summaryDescription();
   }

   std::string get(const std::string& url) {
      http_.initialize();
      return http_.get(url);
   }
   // ...

   std::string createGetRequestUrl(
         const std::string& latitude, const std::string& longitude) const {
      std::string server{"http://open.mapquestapi.com/"};
      std::string document{"nominatim/v1/reverse"};
      return server + document + "?" +
             keyValue("format", "json") + "&" +
             keyValue("lat", latitude) + "&" +
             keyValue("lon", longitude);
   }

   std::string keyValue(
         const std::string& key, const std::string& value) const {
      return key + "=" + value;
   }

   HTTP http_;
};
class Http;
typedef PlaceDescriptionServiceTemplate<Http> PlaceDescriptionService;

#endif
