#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Enum to represent choices
enum Choice { ROCK = 1, PAPER, SCISSORS };

// Arrays to store comments for different outcomes
const string winningComments[] = {
    "Haha! Told you I'm the best!",
    "Too easy! Try harder next time.",
    "You didn't see that coming, did you?",
    "Victory is mine!",
    "Better luck next round!",
    "Outsmarted you this time!",
    "I told you, I'm unbeatable!",
    "This is why I'm the champion!",
    "That was a masterstroke!",
    "Feeling the heat yet?"
};

const string losingComments[] = {
    "Ouch! That hurt!",
    "I won't let that happen again!",
    "You're getting lucky today!",
    "Well played, human. But not for long.",
    "Enjoy your moment—it won't last!",
    "Nice move, but I'm coming back stronger!",
    "You got me this time!",
    "Not bad, but I'm not giving up!",
    "Okay, that was impressive.",
    "You're better than I thought!"
};

const string tieComments[] = {
    "It's a draw! How boring!",
    "We think alike this time!",
    "A tie? Really?",
    "I expected more excitement!",
    "No winner this round—how dull.",
    "Great minds think alike!",
    "We're evenly matched... for now.",
    "A tie won't stop me from winning!",
    "Still no points? Let's fix that.",
    "Neither of us wants to lose!"
};

// Function to get the computer's choice
Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3 + 1);
}

// Function to display the choices to the user
void displayChoices() {
    cout << "Choose an option:\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
}

// Function to display the chosen option
void displayChoice(Choice choice) {
    switch (choice) {
        case ROCK: cout << "Rock"; break;
        case PAPER: cout << "Paper"; break;
        case SCISSORS: cout << "Scissors"; break;
        default: cout << "Invalid Choice"; break;
    }
}

// Function to determine the winner of the round
void determineWinner(Choice userChoice, Choice computerChoice, int& userScore, int& computerScore, string& commentType) {
    if (userChoice == computerChoice) {
        cout << "It's a tie this round!" << endl;
        commentType = "tie";
    } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
               (userChoice == SCISSORS && computerChoice == PAPER) ||
               (userChoice == PAPER && computerChoice == ROCK)) {
        cout << "You win this round!" << endl;
        userScore++;
        commentType = "losing";
    } else {
        cout << "Computer wins this round!" << endl;
        computerScore++;
        commentType = "winning";
    }
}

// Function to display a comment from the computer based on the outcome
void displayComputerComment(const string& commentType) {
    int commentIndex = rand() % 10; 
    if (commentType == "winning") {
        cout << "Computer says: " << winningComments[commentIndex] << endl;
    } else if (commentType == "losing") {
        cout << "Computer says: " << losingComments[commentIndex] << endl;
    } else if (commentType == "tie") {
        cout << "Computer says: " << tieComments[commentIndex] << endl;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    Choice userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    string commentType;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "First to 5 points wins the game!" << endl;

    // Main game loop
    while (userScore < 5 && computerScore < 5) {
        displayChoices();

        // Get the user's choice
        while (true) {
            int choice;
            cout << "Enter your choice (1-3): ";
            cin >> choice;
            userChoice = static_cast<Choice>(choice);

            if (userChoice >= ROCK && userChoice <= SCISSORS) {
                break;
            } else {
                cout << "Invalid choice. Please choose a number between 1 and 3." << endl;
            }
        }

        computerChoice = getComputerChoice();

        cout << "You chose: ";
        displayChoice(userChoice);
        cout << endl;

        cout << "Computer chose: ";
        displayChoice(computerChoice);
        cout << endl;

        determineWinner(userChoice, computerChoice, userScore, computerScore, commentType);

        cout << "Current Scores: You - " << userScore << ", Computer - " << computerScore << endl;

        if (userScore < 5 && computerScore < 5) {
            displayComputerComment(commentType);
        }
        cout << endl;
    }

    // Display the final result
    if (userScore == 5) {
        cout << "Congratulations! You won the game!" << endl;
    } else {
        cout << "Computer wins the game! Better luck next time!" << endl;
    }

    return 0;
}