#include "CppUTest/TestHarness.h"

#include <fstream>
#include <sstream>

#include "StreamUtil.h"

using namespace std;

TEST_GROUP(StreamUtil_Size) {
};

TEST(StreamUtil_Size, AnswersNumberOfBytesWrittenToStream) {
   istringstream readFrom{"abcdefg"};

   CHECK_EQUAL(7, StreamUtil::size(readFrom));
}

