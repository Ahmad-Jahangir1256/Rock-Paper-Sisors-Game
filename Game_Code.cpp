#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

int getComputerChoice() {
    return rand() % 3 + 1; 
}

void displayChoices() {
    cout << "Choose an option:\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
}

void displayChoice(int choice) {
    switch (choice) {
        case 1: cout << "Rock"; break;
        case 2: cout << "Paper"; break;
        case 3: cout << "Scissors"; break;
        default: cout << "Invalid Choice"; break;
    }
}

void determineWinner(int userChoice, int computerChoice, int& userScore, int& computerScore, string& commentType) {
    if (userChoice == computerChoice) {
        cout << "It's a tie this round!" << endl;
        commentType = "tie";
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 3 && computerChoice == 2) ||
               (userChoice == 2 && computerChoice == 1)) {
        cout << "You win this round!" << endl;
        userScore++;
        commentType = "losing";
    } else {
        cout << "Computer wins this round!" << endl;
        computerScore++;
        commentType = "winning";
    }
}

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
    srand(time(0)); 
    int userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    string commentType;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "First to 5 points wins the game!" << endl;

    while (userScore < 5 && computerScore < 5) {
        displayChoices();

        while (true) {
            cout << "Enter your choice (1-3): ";
            cin >> userChoice;

            if (userChoice >= 1 && userChoice <= 3) {
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

    if (userScore == 5) {
        cout << "Congratulations! You won the game!" << endl;
    } else {
        cout << "Computer wins the game! Better luck next time!" << endl;
    }

    return 0;
}