/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef WavStructs_h
#define WavStructs_h

#include <stdint.h>

struct FormatSubchunk {
   uint16_t formatTag;
   uint16_t channels;
   uint32_t samplesPerSecond;
   uint32_t averageBytesPerSecond;
   uint16_t blockAlign;
   uint16_t bitsPerSample;
};

struct DataChunk {
   uint32_t length;
};

#endif
