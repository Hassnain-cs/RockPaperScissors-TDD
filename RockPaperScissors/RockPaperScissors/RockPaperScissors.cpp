#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>  // Need this for strcmp function

// Our game function - will determine who wins
extern "C" {

    // Helper function to check if a move is valid
    int isValidMove(const char move[]) {
        return strcmp(move, "Rock") == 0 ||
            strcmp(move, "Paper") == 0 ||
            strcmp(move, "Scissors") == 0;
    }

    char* determineWinner(const char player1[], const char player2[]) {
        // First check if both moves are the same (will handle Draw properly later)
        if (strcmp(player1, player2) == 0) {
            return "Wrong"; // Will change to "Draw" in next tests
        }

        // Check all Player1 win conditions
        if ((strcmp(player1, "Rock") == 0 && strcmp(player2, "Scissors") == 0) ||
            (strcmp(player1, "Paper") == 0 && strcmp(player2, "Rock") == 0) ||
            (strcmp(player1, "Scissors") == 0 && strcmp(player2, "Paper") == 0)) {
            return "Player1";
        }

        // If not Player1 win and not Draw, then Player2 wins
        return "Player2";
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

        // Test that Paper should lose to Scissors
        TEST_METHOD(TestPlayer2Wins_PaperVsScissors)
        {
            char* result = determineWinner("Paper", "Scissors");
            Assert::AreEqual("Player2", result);
        }

        // Test that same moves should result in Draw
        TEST_METHOD(TestDraw_RockVsRock)
        {
            char* result = determineWinner("Rock", "Rock");
            Assert::AreEqual("Draw", result);
        }
    };
}