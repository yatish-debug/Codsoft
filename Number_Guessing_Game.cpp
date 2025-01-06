#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to get a valid input from the user
int getValidInput() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number: ";
        } else {
            return input;
        }
    }
}

// Function to start the number guessing game
void startGame(int lower, int upper) {
    int randomNumber = rand() % (upper - lower + 1) + lower; // Generate a random number
    int guess, numberOfGuesses = 0;
    int hintCounter = 0;

    cout << "I have selected a number between " << lower << " and " << upper << ". Try to guess it!" << endl;
    
    do {
        cout << "Enter your guess: ";
        guess = getValidInput(); // Get a valid guess from the user
        numberOfGuesses++;

        // Provide hints if the number of guesses exceeds a certain threshold
        if (numberOfGuesses > 5 && hintCounter == 0) {
            if (randomNumber % 2 == 0)
                cout << "Hint: The number is even." << endl;
            else
                cout << "Hint: The number is odd." << endl;
            hintCounter++;
        }

        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number " << randomNumber << " in " << numberOfGuesses << " attempts!" << endl;
        }
    } while (guess != randomNumber);
}

// Function to display the menu and let the user choose difficulty
void displayMenu() {
    cout << "\nWelcome to the Number Guessing Game!" << endl;
    cout << "Please choose a difficulty level:" << endl;
    cout << "1. Easy (1 to 50)" << endl;
    cout << "2. Medium (1 to 100)" << endl;
    cout << "3. Hard (1 to 200)" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int choice, lower, upper;
    bool playAgain = true;

    while (playAgain) {
        displayMenu();
        choice = getValidInput(); // Get valid menu choice

        switch (choice) {
            case 1:
                lower = 1;
                upper = 50;
                startGame(lower, upper);
                break;
            case 2:
                lower = 1;
                upper = 100;
                startGame(lower, upper);
                break;
            case 3:
                lower = 1;
                upper = 200;
                startGame(lower, upper);
                break;
            case 4:
                playAgain = false;
                cout << "Thank you for playing!" << endl;
                break;
            default:
                cout << "Invalid choice, please select a valid option." << endl;
        }

        if (playAgain) {
            cout << "\nWould you like to play again? (Y/N): ";
            char playAgainChoice;
            cin >> playAgainChoice;
            if (playAgainChoice == 'N' || playAgainChoice == 'n') {
                playAgain = false;
                cout << "Thank you for playing!" << endl;
            }
        }
    }

    return 0;
}
// Coded By Yatish Hemant Bharambe // Level 1 // Task 1
