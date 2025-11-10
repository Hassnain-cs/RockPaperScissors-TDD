#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>  // Need this for strcmp function

// Our game function - will determine who wins
extern "C" {
    char* determineWinner(const char player1[], const char player2[]) {
        // Check if player1 has Rock and player2 has Scissors
        if (strcmp(player1, "Rock") == 0 && strcmp(player2, "Scissors") == 0) {
            return "Player1";  // Rock beats Scissors
        }

        // For everything else, still return Wrong
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

            // Check if it returns "Player1" - this should pass now
            Assert::AreEqual("Player1", result);
        }

        // Test that Scissors should lose to Rock
        TEST_METHOD(TestPlayer2Wins_ScissorsVsRock)
        {
            // Call our function with Scissors and Rock
            char* result = determineWinner("Scissors", "Rock");

            // Check if it returns "Player2" - this will fail first
            Assert::AreEqual("Player2", result);
        }
    };
}