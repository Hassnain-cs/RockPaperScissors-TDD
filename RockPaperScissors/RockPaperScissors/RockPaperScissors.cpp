#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>

// Our complete Rock-Paper-Scissors game function
extern "C" {

    // Helper function to validate moves
    int isValidMove(const char move[]) {
        const char* validMoves[] = { "Rock", "Paper", "Scissors" };
        for (int i = 0; i < 3; i++) {
            if (strcmp(move, validMoves[i]) == 0) {
                return 1; // Move is valid
            }
        }
        return 0; // Move is invalid
    }

    // Main function to determine the winner
    char* determineWinner(const char player1[], const char player2[]) {
        // Validate both inputs first
        if (!isValidMove(player1) || !isValidMove(player2)) {
            return "Invalid";
        }

        // Check for draw condition
        if (strcmp(player1, player2) == 0) {
            return "Draw";
        }

        // Check Player1 win conditions
        if ((strcmp(player1, "Rock") == 0 && strcmp(player2, "Scissors") == 0) ||
            (strcmp(player1, "Paper") == 0 && strcmp(player2, "Rock") == 0) ||
            (strcmp(player1, "Scissors") == 0 && strcmp(player2, "Paper") == 0)) {
            return "Player1";
        }

        // If not invalid, not draw, and not Player1 win, then Player2 wins
        return "Player2";
    }
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RockPaperScissorsTests
{
    TEST_CLASS(RockPaperScissorsTests)
    {
    public:
        // Win/Lose condition tests
        TEST_METHOD(TestPlayer1Wins_RockVsScissors)
        {
            char* result = determineWinner("Rock", "Scissors");
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(TestPlayer2Wins_ScissorsVsRock)
        {
            char* result = determineWinner("Scissors", "Rock");
            Assert::AreEqual("Player2", result);
        }

        TEST_METHOD(TestPlayer1Wins_PaperVsRock)
        {
            char* result = determineWinner("Paper", "Rock");
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(TestPlayer2Wins_RockVsPaper)
        {
            char* result = determineWinner("Rock", "Paper");
            Assert::AreEqual("Player2", result);
        }

        TEST_METHOD(TestPlayer1Wins_ScissorsVsPaper)
        {
            char* result = determineWinner("Scissors", "Paper");
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(TestPlayer2Wins_PaperVsScissors)
        {
            char* result = determineWinner("Paper", "Scissors");
            Assert::AreEqual("Player2", result);
        }

        // Draw condition tests
        TEST_METHOD(TestDraw_RockVsRock)
        {
            char* result = determineWinner("Rock", "Rock");
            Assert::AreEqual("Draw", result);
        }

        // Invalid input tests
        TEST_METHOD(TestInvalidInput_BananaVsRock)
        {
            char* result = determineWinner("Banana", "Rock");
            Assert::AreEqual("Invalid", result);
        }
    };
}