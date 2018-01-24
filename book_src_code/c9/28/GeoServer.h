/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef GeoServer_h
#define GeoServer_h

#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <memory>

#include "Location.h"
#include "Area.h"
#include "User.h"
#include "ThreadPool.h"

class GeoServerListener {
public:
   virtual void updated(const User& user)=0;
};

class GeoServerBase {
public:
   virtual Location virtualLocationOf(const std::string& user) const {
      throw 1;
   }
};

class GeoServer: public GeoServerBase {
public:
   virtual ~GeoServer() {}
   void track(const std::string& user);
   void stopTracking(const std::string& user);
   void updateLocation(const std::string& user, const Location& location);

   bool isTracking(const std::string& user) const;
   virtual Location virtualLocationOf(const std::string& user) 
      const override
      __attribute__((noinline));
   Location locationOf(const std::string& user) const;
   bool isDifferentUserInBounds(
         const std::pair<std::string, Location>& each,
         const std::string& user,
         const Area& box) const;
   void usersInBox(
         const std::string& user, double widthInMeters, double heightInMeters,
         GeoServerListener* listener) const;
   void useThreadPool(std::shared_ptr<ThreadPool> pool);

private:
   std::unordered_map<std::string, Location> locations_;

   std::unordered_map<std::string, Location>::const_iterator 
      find(const std::string& user) 
      const
      __attribute__((noinline));
   std::shared_ptr<ThreadPool> pool_;
   unsigned int i{0};
};
#endif
