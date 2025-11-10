#include "pch.h"
#include "CppUnitTest.h"

// Our game function - will determine who wins
extern "C" {
    char* determineWinner(const char player1[], const char player2[]) {
        // Just return wrong for now so test fails
        return "Wrong";
    }
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RockPaperScissorsTests
{
    TEST_CLASS(RockPaperScissorsTests)
    {
    public:
        // Test that Rock should beat Scissors
        TEST_METHOD(TestPlayer1Wins_RockVsScissors)
        {
            // Call our function with Rock and Scissors
            char* result = determineWinner("Rock", "Scissors");

            // Check if it returns "Player1" - this will fail first
            Assert::AreEqual("Player1", result);
        }
    };
}