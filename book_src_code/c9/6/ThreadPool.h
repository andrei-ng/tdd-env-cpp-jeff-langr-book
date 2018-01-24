/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef ThreadPool_h
#define ThreadPool_h

#include <string>
#include <deque>
#include <thread>
#include <memory>

#include "Work.h"

class ThreadPool {
public:
   virtual ~ThreadPool() {
      if (workThread_)
         workThread_->join();
   }

   void start() {
      workThread_ = std::make_shared<std::thread>(&ThreadPool::worker, this);
   }
   // ...
   bool hasWork() {
      return !workQueue_.empty();
   }

   void add(Work work) {
      workQueue_.push_front(work); 
   }

   Work pullWork() {
      auto work = workQueue_.back();
      workQueue_.pop_back();
      return work;
   }

private:
   void worker() {
      while (!hasWork())
         ;
      pullWork().execute();
   }

   std::deque<Work> workQueue_;
   std::shared_ptr<std::thread> workThread_;
};

#endif
