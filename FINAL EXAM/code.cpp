#include <iostream>
using namespace std;

class LetterCounter {
private:
    int letters[26];
    int numbers[10];
    int totalLetters;
    int totalNumbers;
    int spaces;
public:
    LetterCounter() {
        totalLetters = 0;
        totalNumbers = 0;
        spaces = 0;
        for (int i = 0; i < 26; ++i) 
            letters[i] = 0;
        for (int i = 0; i < 10; ++i)
             numbers[i] = 0;
    }
   
    void countCharacter(char letter) {
        if (letter >= 'A' && letter <= 'Z') {
            letter = letter - 'A' + 'a';
        }

        if (letter >= 'a' && letter <= 'z') {
            ++letters[letter - 'a'];
            ++totalLetters;
        }
        else if (letter >= '0' && letter <= '9') {
            ++numbers[letter - '0'];
            ++totalNumbers;
        }
        else if (letter == ' ') {
            ++spaces;
        }
    }

    void printCounts() {
        cout << "The number of spaces is " << spaces << endl;
        cout << "The number of letters is " << totalLetters << endl;
        cout << "The number of numbers is " << totalNumbers << endl;
        cout << "----Histogram----" << endl;
        cout << " char   " << "   count" << endl;
        for (int i = 0; i < 26; ++i) {
            if (letters[i] > 0) {
                cout << "   " << char('a' + i) << "         " << letters[i] << endl;
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (numbers[i] > 0) {
                cout << "   " << i << "         " << numbers[i] << endl;
            }
        }
    }
};

int main() {
    LetterCounter counter;
    char input[256];
    cout << "Enter a string: ";
    cin.getline(input, 256);
    for (int i = 0; input[i] != '\0'; ++i) {
        counter.countCharacter(input[i]);
    }

    counter.printCounts();
    return 0;
}