#include <iostream>
#include <conio.h>     // for getch()
#include <string>
using namespace std;

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

string cleanString(string str) {
    string cleaned = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {                // skip spaces
            cleaned += toLowerCase(str[i]); // normalize case
        }
    }
    return cleaned;
}

// Function to check palindrome
bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    char key;
    string word;

    cout << "=== Palindrome Checker ===" << endl;
    cout << "Press ESC to quit anytime.\n" << endl;

    while (true) {
        cout << "Enter a word or phrase: ";
        getline(cin, word);     // allows spaces

        string processed = cleanString(word);

        if (isPalindrome(processed))
            cout << "Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;

        cout << "\nPress any key to continue or ESC to quit..." << endl;
        key = getch();

        if (key == 27)  // 27 = ESC key
            break;

        cout << endl;
    }

    cout << "\nProgram exited." << endl;
    return 0;
}
