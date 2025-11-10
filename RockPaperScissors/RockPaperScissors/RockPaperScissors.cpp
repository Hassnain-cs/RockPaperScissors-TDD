#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>  // Need this for strcmp function

// Our game function - will determine who wins
extern "C" {
    char* determineWinner(const char player1[], const char player2[]) {
        // Handle Rock cases
        if (strcmp(player1, "Rock") == 0) {
            if (strcmp(player2, "Scissors") == 0) return "Player1";
            if (strcmp(player2, "Paper") == 0) return "Player2"; // Rock loses to Paper
            if (strcmp(player2, "Rock") == 0) return "Wrong"; // Not handled yet
        }

        // Handle Scissors cases  
        if (strcmp(player1, "Scissors") == 0) {
            if (strcmp(player2, "Rock") == 0) return "Player2";
            if (strcmp(player2, "Scissors") == 0) return "Wrong"; // Not handled yet
            if (strcmp(player2, "Paper") == 0) return "Wrong"; // Not handled yet
        }

        // Handle Paper cases
        if (strcmp(player1, "Paper") == 0) {
            if (strcmp(player2, "Rock") == 0) return "Player1"; // Paper beats Rock
            if (strcmp(player2, "Scissors") == 0) return "Wrong"; // Not handled yet
            if (strcmp(player2, "Paper") == 0) return "Wrong"; // Not handled yet
        }

        // For everything else, return Wrong
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
            char* result = determineWinner("Rock", "Scissors");
            Assert::AreEqual("Player1", result);
        }

        // Test that Scissors should lose to Rock
        TEST_METHOD(TestPlayer2Wins_ScissorsVsRock)
        {
            char* result = determineWinner("Scissors", "Rock");
            Assert::AreEqual("Player2", result);
        }

        // Test that Paper should beat Rock
        TEST_METHOD(TestPlayer1Wins_PaperVsRock)
        {
            char* result = determineWinner("Paper", "Rock");
            Assert::AreEqual("Player1", result);
        }

        // Test that Rock should lose to Paper
        TEST_METHOD(TestPlayer2Wins_RockVsPaper)
        {
            char* result = determineWinner("Rock", "Paper");
            Assert::AreEqual("Player2", result);
        }

        // Test that Scissors should beat Paper
        TEST_METHOD(TestPlayer1Wins_ScissorsVsPaper)
        {
            char* result = determineWinner("Scissors", "Paper");
            Assert::AreEqual("Player1", result);
        }
    };
}