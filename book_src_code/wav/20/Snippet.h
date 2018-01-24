/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef Snippet_h
#define Snippet_h

using namespace std;

class Snippet {
public:
   Snippet(shared_ptr<FileUtil> fileUtil,
      shared_ptr<WavDescriptor> descriptor,
      const std::string& dest,
      rlog::RLogChannel* channel) 
      : fileUtil_(fileUtil)
      , descriptor_(descriptor)
      , dest_(dest) 
      , channel_(channel) { }
// ...

   uint32_t dataLength(
         uint32_t samples, 
         uint32_t bytesPerSample,
         uint32_t channels
         ) const {
      return samples * bytesPerSample * channels;
   }

private:
   shared_ptr<FileUtil> fileUtil_;
   shared_ptr<WavDescriptor> descriptor_;
   const string dest_;
   rlog::RLogChannel* channel_;
};

#endif
