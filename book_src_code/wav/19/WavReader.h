/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef WavReader_h
#define WavReader_h

#include <string>
#include <fstream>
#include <memory>
#include <boost/filesystem.hpp>

#include "WavDescriptor.h"
#include "FileUtil.h"
#include "rlog/StdioNode.h"
#include "rlog/RLogChannel.h"

bool hasExtension(const std::string& text, const std::string& substring);

struct FormatSubchunkHeader;

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

class WavReader {
public:
   WavReader(
         const std::string& source, 
         const std::string& dest,
         std::shared_ptr<WavDescriptor> descriptor=0);
   // ...
   virtual ~WavReader();
   void open(const std::string& name, bool trace);
   void list(
         const boost::filesystem::path& dir, 
         const std::string &filename, 
         std::vector<boost::filesystem::path>& found) const;
   void listAll() const;
   void publishSnippets();

   void writeSamples(std::ostream* out, char* data, 
         uint32_t startingSample, 
         uint32_t samplesToWrite, 
         uint32_t bytesPerSample,
         uint32_t channels=1);

   uint32_t dataLength(
         uint32_t samples, 
         uint32_t bytesPerSample,
         uint32_t channels) const;

   void writeSnippet(
         const std::string& name, std::istream& file, std::ostream& out,
         FormatSubchunk& formatSubchunk,
         DataChunk& dataChunk,
         char* data);

   void useFileUtil(std::shared_ptr<FileUtil>);

private:
   rlog::StdioNode log{STDERR_FILENO};

   void readAndWriteHeaders(
         const std::string& name,
         std::istream& file,
         std::ostream& out,
         FormatSubchunk&,
         FormatSubchunkHeader&);
   void read(
         std::istream& file,
         DataChunk&);
   char* readData(std::istream& file, int32_t length);

   void seekToEndOfHeader(std::ifstream& file, int headerLength);
   std::string toString(int8_t* c, unsigned int size);

   rlog::RLogChannel* channel;

   std::string source_;
   std::string dest_;
   std::shared_ptr<WavDescriptor> descriptor_;
   std::shared_ptr<FileUtil> fileUtil_;
};

#endif  
