#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h> // for getch()
#include <cstdlib> // for rand()
using namespace std;

/*
  CONSTANTS
  - can Change these easily without touching core logic.
*/
const int MAX_WORDS = 100;
const int MAX_WORD_LENGTH = 50;
const int MAX_ALLOWED_MISTAKES = 7;
const string WORDS_FILE = "words.txt";

/*
  Function: loadWords
  Purpose : Reads words from file into array and returns count.
  Anticipation of change: File name and limits defined globally.
*/
int loadWords(string wordList[], int maxWords)
{
    ifstream file(WORDS_FILE);

    if (!file)
    {
        cout << "Error: Could not open " << WORDS_FILE << endl;
        return 0;
    }

    int count = 0;
    while (count < maxWords && file >> wordList[count])
    {
        count++;
    }

    file.close();
    return count;
}

/*
  Function: displayWord
  Purpose : Shows the current guessing progress to the user.
*/
void displayWord(const string &word, const bool guessedLetters[])
{
    cout << "Current Word: ";
    for (int i = 0; i < word.length(); i++)
    {
        if (guessedLetters[i])
            cout << word[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

/*
  Function: chooseRandomWord
  Purpose : Pick a random word from the loaded list.
*/
string chooseRandomWord(const string wordList[], int totalWords)
{
    int randomIndex = rand() % totalWords;
    return wordList[randomIndex];
}

/*
  Function: toLowerCase
  Purpose : Manual conversion from uppercase to lowercase.
*/
char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

/*
  Function: processGuess
  Purpose : Handle a single user guess — updates state and counts.
  Returns : true if guess was correct, false otherwise.
*/
bool processGuess(char guess, const string &word, bool guessedLetters[], int &correctCount)
{
    bool found = false;
    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] == guess && !guessedLetters[i])
        {
            guessedLetters[i] = true;
            correctCount++;
            found = true;
        }
    }
    return found;
}

/*
  Function: playHangman
  Purpose : The main game logic (loop for guessing).
  Modularity: Keeps main() clean and focused.
*/
void playHangman()
{
    string wordList[MAX_WORDS];
    int totalWords = loadWords(wordList, MAX_WORDS);

    if (totalWords == 0)
    {
        cout << "No words loaded. Exiting game." << endl;
        return;
    }

    string secretWord = chooseRandomWord(wordList, totalWords);
    bool guessedLetters[MAX_WORD_LENGTH] = {false};

    int remainingMistakes = MAX_ALLOWED_MISTAKES;
    int correctCount = 0;
    int wordLength = secretWord.length();

    cout << "=== Hangman Game ===" << endl;
    cout << "You have " << remainingMistakes << " mistakes allowed." << endl;

    // Game Loop
    while (remainingMistakes > 0 && correctCount < wordLength)
    {
        displayWord(secretWord, guessedLetters);

        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        guess = toLowerCase(guess);

        bool correct = processGuess(guess, secretWord, guessedLetters, correctCount);

        if (correct)
            cout << "Correct guess!" << endl;
        else
        {
            remainingMistakes--;
            cout << "Incorrect guess! Remaining mistakes: " << remainingMistakes << endl;
        }

        cout << endl;
    }

    // Final result
    if (correctCount == wordLength)
        cout << "You win! The word was: " << secretWord << endl;
    else
        cout << "You lost. The word was: " << secretWord << endl;

    cout << "Press any key to exit..." << endl;
    getch();
}

/*
  Function: main
  Purpose : Initializes random seed and runs the game.
*/
int main()
{
    srand(time(0)); // Seed random number generator
    playHangman();
    return 0;
}
