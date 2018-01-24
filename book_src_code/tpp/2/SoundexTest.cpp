#include "CppUTest/TestHarness.h"

#include "Soundex.h"

TEST_GROUP(SoundexEncoding) {};

TEST(SoundexEncoding, AppendsZerosToWordForOneLetterWord) {
   Soundex soundex;

   auto encoded = soundex.encode("A");

   CHECK_EQUAL("A000", encoded);
}
