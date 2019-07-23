#include "functions.h"

std::string addFunction(std::list<std::string> args) {
    int result = 0;
    std::for_each(args.begin(), args.end(), [&] (std::string arg) {
        result += std::stoi(arg);
    });
    return std::to_string(result);
}

std::string subFunction(std::list<std::string> args) {
    int result = std::stoi(*args.begin());
    std::for_each(++args.begin(), args.end(), [&] (std::string arg) {
        result -= std::stoi(arg);
    });
    return std::to_string(result);
}

std::string multFunction(std::list<std::string> args) {
    int result = 1;
    std::for_each(args.begin(), args.end(), [&] (std::string arg) {
        result *= std::stoi(arg);
    });
    return std::to_string(result);
}

std::string concatFunction(std::list<std::string> args) {
    std::string result = "";
    std::for_each(args.begin(), args.end(), [&] (std::string arg) {
        result += arg;
    });
    return result;
}

std::string calculate(std::string operation, std::list<std::string> operands) {
    std::string result = "";

    if (operation == "quit") {
        std::cout << "--------\n* Exit *\n\n";
        std::exit(0);
    }
    else if (operation == "add") result = addFunction(operands);
    else if (operation == "sub") result = subFunction(operands);
    else if (operation == "mult") result = multFunction(operands);
    else if (operation == "concat") result = concatFunction(operands);
    else result = "Incorrect operation";

    return result;
}
