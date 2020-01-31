//
//  TextGenerator.cpp
//  ps6
//
//  Created by Omar Virk on 4/06/18.
//  Copyright © 2018 Omar Virk. All rights reserved.
//
#include <iostream>
#include <string>
#include "MarkovModel.hpp"

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        std::cout << "Use: ./TextGenerator (int K) (int T)\n";
        return 0;
    }
    std::string strA(argv[1]);
    std::string strB(argv[2]);
    int A = std::stoi(strA);
    int B = std::stoi(strB);
    std::string input = "";
    std::string currentText = "";
    while (std::cin >> currentText) {
        input += " " + currentText;
        currentText = "";
    }
    std::cout << "Actual Input Text:\n\n";
    for (int i = 0; i < B; i++) {
        std::cout << input[i];
        if (input[i] == '.' || input[i] == '!') {
            std::cout << "\n";
        }
    }
    std::string output_string = "";
    MarkovModel amazing(input, A);
    output_string += "" + amazing.gen(input.substr(0, A), B);
    std::cout << "\n\nFINAL OUTPUT TEXT\n\n";
    for (int i = 0; i < B; i++) {
        std::cout << output_string[i];
        if (output_string[i] == '.' || output_string[i] == '!') {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
    return 0;
}
