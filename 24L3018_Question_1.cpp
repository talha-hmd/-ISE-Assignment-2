#include <iostream>
#include <conio.h> // For getch() to detect ESC key
#include <string>
using namespace std;

/*
  Function: toLowerCase
  Purpose : Convert uppercase character to lowercase manually.
  Rationale: Avoids using built-in tolower() for full control.
-*/
char toLowerCase(char character)
{
    if (character >= 'A' && character <= 'Z')
        return character + 32; // Convert ASCII uppercase to lowercase
    return character;          // Return unchanged if already lowercase
}

/*
  Function: cleanString
  Purpose : Remove spaces and normalize letter casing.
  Anticipation of change: Can be extended later to ignore punctuation.
*/
string cleanString(const string &input)
{
    string cleanedText = "";

    for (int i = 0; i < input.length(); i++)
    {
        char current = input[i];

        // Only consider letters (skip spaces or special chars)
        if (current != ' ')
        {
            cleanedText += toLowerCase(current);
        }
    }

    return cleanedText;
}

/*
  Function: isPalindrome
  Purpose : Check if a given cleaned string is palindrome.
*/
bool isPalindrome(const string &text)
{
    int leftIndex = 0;
    int rightIndex = text.length() - 1;

    // Compare characters from both ends moving toward the center
    while (leftIndex < rightIndex)
    {
        if (text[leftIndex] != text[rightIndex])
            return false; // Mismatch found
        leftIndex++;
        rightIndex--;
    }

    return true; // All characters matched
}

/*
  Function: processPalindromeCheck
  Purpose : Handles the core interaction of reading input,
            cleaning it, checking palindrome, and displaying result.
  Modularity: Keeps main() minimal and readable.
*/
void processPalindromeCheck()
{
    string inputText;
    cout << "Enter a word or phrase: ";
    getline(cin, inputText); // Allows spaces in input

    // Clean and normalize the input
    string processedText = cleanString(inputText);

    // Determine and print result
    if (isPalindrome(processedText))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
}

/*
  Function: main
  Purpose : Controls program flow and user interaction.
  Documentation: Includes ESC key logic for graceful exit.
*/
int main()
{
    char userChoice;

    cout << "=== Palindrome Checker ===" << endl;
    cout << "Press ESC to quit anytime.\n" << endl;

    while (true)
    {
        processPalindromeCheck(); // Perform one full check

        cout << "\nPress any key to continue or ESC to quit..." << endl;
        userChoice = getch(); // Wait for user input without pressing Enter

        if (userChoice == 27)
        { // 27 = ASCII code for ESC key
            cout << "\nProgram exited successfully." << endl;
            break;
        }

        cout << endl; // For spacing before next loop iteration
    }

    return 0;
}
