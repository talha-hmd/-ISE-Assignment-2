#include <iostream>
#include <fstream>
#include <ctime>
#include <conio.h>
using namespace std;

int loadWords(string words[], int maxWords)
{
    ifstream file("words.txt");
    if (!file)
    {
        cout << "Error: Could not open words.txt" << endl;
        return 0;
    }

    int count = 0;
    while (count < maxWords && file >> words[count])
        count++;

    file.close();
    return count;
}

// Function to display the current guessed word state
void displayWord(const string &word, const bool guessed[])
{
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed[i])
            cout << word[i] << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));

    const int MAX_WORDS = 100;
    string words[MAX_WORDS];
    int totalWords = loadWords(words, MAX_WORDS);

    if (totalWords == 0)
    {
        cout << "No words found. Please check words.txt" << endl;
        return 0;
    }

    // Pick a random word
    string word = words[rand() % totalWords];
    bool guessed[50] = {false};

    int remainingMistakes = 7;
    int correctCount = 0;
    int wordLength = word.length();

    cout << "=== Hangman Game ===" << endl;
    cout << "You have " << remainingMistakes << " errors allowed." << endl;
    cout << "Guess the word below:" << endl;

    while (remainingMistakes > 0 && correctCount < wordLength)
    {
        displayWord(word, guessed);

        cout << "\nEnter a letter: ";
        char guess;
        cin >> guess;

        // Convert uppercase input to lowercase manually
        if (guess >= 'A' && guess <= 'Z')
            guess += 32;

        bool found = false;
        for (int i = 0; i < wordLength; i++)
        {
            if (word[i] == guess && !guessed[i])
            {
                guessed[i] = true;
                correctCount++;
                found = true;
            }
        }

        if (!found)
        {
            remainingMistakes--;
            cout << "Incorrect guess! Remaining mistakes: " << remainingMistakes << endl;
        }
        else
        {
            cout << "Correct guess!" << endl;
        }

        cout << endl;
    }

    if (correctCount == wordLength)
    {
        cout << "Declared winner! The word was: " << word << endl;
    }
    else
    {
        cout << "Unfortunate loser. The word was: " << word << endl;
    }

    cout << endl << "Press any key to exit...";
    getch();

    return 0;
}
