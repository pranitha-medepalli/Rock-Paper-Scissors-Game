#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int userScore = 0;
int computerScore = 0;

    char playAgain;
// Function to clear the screen
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Array of choices
    string choices[] = {"Rock", "Paper", "Scissors"};
    do {
        clearScreen(); // Clear the screen before each round

        // Print game title
        cout << "\033[1;32m"; // Green color
        cout << "============================" << endl;
        cout << "   Rock Paper Scissors" << endl;
        cout << "============================" << endl;
        cout << "\033[0m"; // Reset color

        // User's choice
        int userChoice;
        cout << "Enter your choice" << endl;
        cout << "0: Rock, 1: Paper, 2: Scissors: ";
        cin >> userChoice;

        if (userChoice < 0 || userChoice > 2) {
            cout << "Invalid choice! Please enter a number between 0 and 2." << endl;
            return 1;
        }

        // Computer's choice
        int computerChoice = rand() % 3;

        clearScreen(); // Clear the screen before displaying results

        // Print choices
        cout << "You chose: " << choices[userChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        // Determine the winner
        if (userChoice == computerChoice) {
            cout << "\033[1;33m"; // Yellow color
            cout << "It's a tie!" << endl;
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            cout << "\033[1;32m"; // Green color
            cout << "You win!" << endl;
            userScore++;
        } else {
            cout << "\033[1;31m"; // Red color
            cout << "Computer wins!" << endl;
            computerScore++;
        }

        // Display score
        cout << "\033[1;36m"; // Cyan color
        cout << "Score - You: " << userScore << " Computer: " << computerScore << endl;
        cout << "\033[0m"; // Reset color

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    clearScreen(); // Clear the screen before exiting

    // Print final score
    cout << "\033[1;32m"; // Green color
    cout << "Thanks for playing! Final score - You: " << userScore << " Computer: " << computerScore << endl;
    cout << "\033[0m"; // Reset color

    return 0;
}


