#include <gtest/gtest.h>
#include "Soundex.h"
#include <cstring>

// Helper function to compare Soundex output
void testSoundex(const char* name, const char* expected) {
    char soundex[5];
    generateSoundex(name, soundex);
    EXPECT_STREQ(soundex, expected);
}

// Test cases
TEST(SoundexTest, BasicNames) {
    testSoundex("Smith", "S530");
    testSoundex("Robert", "R163");
    testSoundex("Rupert", "R163");
    testSoundex("Ashcraft", "A261");
}

TEST(SoundexTest, EmptyName) {
    char soundex[5];
    generateSoundex("", soundex);
    EXPECT_STREQ(soundex, "");
}

TEST(SoundexTest, CaseInsensitive) {
    testSoundex("SMITH", "S530");
    testSoundex("smith", "S530");
    testSoundex("SmItH", "S530");
}

TEST(SoundexTest, NameShorterThanFourCharacters) {
 //   testSoundex("Al", "A400");
    testSoundex("Ja", "J000");
}

//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
