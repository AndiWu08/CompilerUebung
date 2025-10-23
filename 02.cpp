#include <iostream>
#include <string>
#include <regex>

bool regexA(const std::string& input) {
    std::regex pattern("1*0+");
    return std::regex_match(input, pattern);
}

bool regexB(const std::string& input) {
    std::regex pattern("[+-]?(0|[1-9][0-9]*)");
    return std::regex_match(input, pattern);
}

bool regexC(const std::string& input) {
    std::regex pattern("0|1[01]*");
    return std::regex_match(input, pattern);
}

int main() {
    std::string input;
    
    std::cout << "Eingabe für Teil a) (1*0*0): ";
    std::cin >> input;
    std::cout << "Ergebnis regex: " << (regexA(input) ? "Akzeptiert" : "Abgelehnt") << std::endl;
    
    std::cout << "Eingabe für Teil b) (Dezimalzahlen): ";
    std::cin >> input;
    std::cout << "Ergebnis regex: " << (regexB(input) ? "Akzeptiert" : "Abgelehnt") << std::endl;
    
    std::cout << "Eingabe für Teil c) (Binärzahlen): ";
    std::cin >> input;
    std::cout << "Ergebnis regex: " << (regexC(input) ? "Akzeptiert" : "Abgelehnt") << std::endl;
}