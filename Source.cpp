#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <regex>


void processOneLetter(std::string userInput, std::string wordToGuess, std::string &stringToFill) {
    
        std::string userInputChar;
      
        userInputChar = userInput;

        //sprawdzamy czy ta litera jest w naszym słowie
        std::vector <int> positions{};
        //jeśli jest, dodajemy jego pozycję do wektora

        for (int j = 0; j < wordToGuess.length(); j++) {
            if (wordToGuess[j] == userInputChar[0]) {
                positions.push_back(j);
            }
        }
        //Jeśli w wektorze nie znaleziono ani jednej tej litery
        if (positions.size() == 0) {
            std::cout << "This letter doesn't appear in the word.\n\n";
            system("pause");
            std::system("CLS");
        }
        else {
            //bierzemy cyfry z wektora positions np. 1, 3
            //cyfry te są pozycją na której ta litera ma się znaleźć
            //przechodzimy po wektorze, bierzemy cyfry po kolei
            for (int x = 0; x < positions.size(); x++) {
                int position;
                position = positions[x]; //ta cyfra, np.3, ma nam powiedzieć w którym miejscu włożyć tą literę 
                stringToFill[position] = userInputChar[0];
            }
            std::cout << "Congrats! This letter is in the word!\n\n";
            system("pause");
            std::system("CLS");
        }    
}
bool isGuessCorrect(std::string userInput, std::string wordToGuess) {
    //sytuacja gdy mamy całe słowo
    //sprawdzamy czy całe słowo jest słowem które mamy zgadnąć
    if (userInput == wordToGuess) {
        std::cout << "Congratulations! You guessed the word!\n\n" << wordToGuess << std::endl;
        return true;
    }
    else {
        std::cout << "Wrong guess! Try again\n";
        system("pause");
        std::system("CLS");
        return false;
    }
}

void toUpper(std::string& word) {
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
}

std::string getInput() {
    std::string wordToGuess;
    do {
        std::cout << "Enter the word to guess:\n";
        std::cin >> wordToGuess;
        std::system("CLS");
        std::regex reg("[A-Za-z+]");

    } while (!std::regex_match(wordToGuess, std::regex("[A-Za-z]+")));

    toUpper(wordToGuess);
    return wordToGuess;
}

std::string getInput(int size) {
    std::string value;
    do {
        value = getInput(); 
    } while (value.size() != size);
    return value;
}

void playGame(std::string wordToGuess) {
    
    std::string stringToFill(wordToGuess.length(), '-');

    for (int i = 7; i > 0; i--) {

        std::cout << "\n\t" << stringToFill << std::endl; //nasz roboczy string w którym zgadujemy
        std::cout << "\nYou have " << i << " attempts left.\n\nEnter the letter or the word:";

        //bierzemy od użytkownika input w formie stringa
        std::string userInput;
        std::cin >> userInput;
        toUpper(userInput);

        //jeśli jest to string złożony z jednej litery -> char, jeśli string -> całe słowo
        if ((userInput.length()) == 1) {
            processOneLetter(userInput, wordToGuess, stringToFill);
        }
        else {
            if (isGuessCorrect(userInput, wordToGuess))
                break;
        }
        if (wordToGuess == stringToFill) {
            std::cout << "Congratulations! You won!\n\n" << stringToFill << std::endl;
            break;
        }
        else if (wordToGuess != stringToFill && i == 0) {
            std::cout << "Sorry, you lost!\n\n";
        }
    }
}
int main() {
    
    std::string wordToGuess = getInput();
    playGame(wordToGuess);
    int size = wordToGuess.length();
    std::system("CLS");
    std::string wordToGuess2 = getInput(size);
    playGame(wordToGuess2);

    return 0;
}