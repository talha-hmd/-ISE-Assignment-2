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
  Function: isAlphabet
  Purpose : Check if a character is an alphabetic letter.
  Robustness: Filters out digits and punctuation automatically.
-*/
bool isAlphabet(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

/*
  Function: cleanString
  Purpose : Remove spaces, punctuation, and normalize case.
  Anticipation of change: Can later be extended for Unicode.
-*/
string cleanString(const string &input)
{
    string cleanedText = "";

    for (int i = 0; i < input.length(); i++)
    {
        char current = input[i];
        if (isAlphabet(current)) // Keep only letters
        {
            cleanedText += toLowerCase(current);
        }
    }

    return cleanedText;
}

/*
  Function: isPalindrome
  Purpose : Check if a given cleaned string is palindrome.
-*/
bool isPalindrome(const string &text)
{
    int leftIndex = 0;
    int rightIndex = text.length() - 1;

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
  Purpose : Handles the input, cleaning, checking, and display.
  Robustness: Validates empty input and only processes valid strings.
-*/
void processPalindromeCheck()
{
    string inputText;
    cout << "Enter a word or phrase: ";
    getline(cin, inputText);

    // Clean and normalize the input
    string processedText = cleanString(inputText);

    // Robustness: Check for empty input or no valid characters
    if (processedText.empty())
    {
        cout << "Invalid input! Please enter at least one alphabetic character." << endl;
        return;
    }

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
  Robustness: Handles continuous user checks safely.
-*/
int main()
{
    char userChoice;

    cout << "=== Palindrome Checker ===" << endl;
    cout << "Press ESC to quit anytime." << endl;

    while (true)
    {
        processPalindromeCheck(); // Perform one full check

        cout << "Press any key to continue or ESC to quit..." << endl;
        userChoice = getch(); // Wait for user input without pressing Enter

        if (userChoice == 27) // 27 = ESC key
        {
            cout << "Program exited successfully." << endl;
            break;
        }

        cout << endl; // For spacing before next iteration
    }

    return 0;
}
