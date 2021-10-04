// Copyright [2021] Rohnin Barrette"  [legal/copyright]

// Created by: Rohnin Barrette
// Created on: Sept 2021
// This program asks the user to guess a number between 1-9 with a try statement

#include <iostream>
#include <random>

int main() {
    // This program asks the user to guess a
    // number between 1-9 with a try statement
    std::string guessed_string;
    int random_number;
    int guessed_number;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 10);  // [1,10]
    random_number = idist(rgen);

    // input,process and output
    while (true) {
        try {
            std::cout << "Enter a number between 1 and 10: ";
            std::cin >> guessed_string;
            std::cout << "" << std::endl;
            guessed_number = std::stoi(guessed_string);
            if (guessed_string.find_first_of(".") != std::string::npos) {
                std::cout << "Invalid input" <<std:: endl;
            } else {
                if (guessed_number == random_number) {
                    std::cout << "you guessed right";
                    break;
                } else {
                    if (guessed_number > random_number) {
                        std::cout << "too high, please try again" << std::endl;
                    } else {
                        if (guessed_number < random_number) {
                            std::cout << "too low, please try again"
                            << std::endl;
                        }
                    }
                }
            }
        } catch (std::invalid_argument) {
            std::cout << guessed_string << "is an invalid input" << std::endl;
        }
    }
    std::cout << "" << std::endl;
    std::cout << "\nDone." << std::endl;
}
