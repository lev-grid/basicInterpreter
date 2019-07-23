#include "functions.h"

std::string getInputString() {
    std::string input;
    std::cout << "$ ";
    std::getline(std::cin, input);
    return input;
}

std::string getResult(std::string input) {
    input += " ";
    std::string result = "";
    std::string word = "";
    std::string operation = "";
    std::list<std::string> operands;
    bool insideQuotes = false;
    bool firstWord = true;
    short countBrackets = 0;
    for (auto i: input) {
        switch (i) {
        case '"':
            insideQuotes = !insideQuotes;
            break;
        case '(':
            if (!insideQuotes) {
                if (countBrackets != 0) word += i;
                countBrackets++;
            } else {
                word += i;
            }
            break;
        case ')':
            if (!insideQuotes) {
                countBrackets--;
                if (countBrackets == 0) word = getResult(word);
                else word += i;
            } else word += i;
            break;
        case ' ':
            if (word == "") break;
            if (!insideQuotes && countBrackets == 0) {
                if (firstWord) {
                    operation = word;
                    firstWord = false;
                } else {
                    operands.push_back(word);
                }
                word = "";
            } else word += i;
            break;
        default:
            word += i;
        }
    }
    try {
        if (countBrackets != 0) throw "Incorrect number of brackets";
        if (insideQuotes) throw "Incorrect number of quotes";
        try {
            result = calculate(operation, operands);
        }
        catch(...) {
            throw "Incorrect operands";
        }
    }
    catch (const char* msg) {
        result = msg;
    }
    return result;
}

int main () {
    std::string input, output;
    std::cout << "\n* Start *\n---------\n";

    for (;;) {
        input.clear();
        input = getInputString();

        output = getResult(input);

        std::cout << "> " << output << "\n\n";
    }

    return 0;
}
