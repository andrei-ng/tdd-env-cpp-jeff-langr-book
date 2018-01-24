#include <string>

class Soundex
{
public:
   std::string encode(const std::string& word) const {
      return word;
   }
};

#include "gmock/gmock.h"    

using ::testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");

   ASSERT_THAT(encoded, Eq("A")); 
}

