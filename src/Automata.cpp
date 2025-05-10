// Copyright 2025 Owner
#include "Automata.h"
#include <iostream>
#include <string>
Automata::Automata() : cash(0), state(OFF), selected(-1) {
    menu = { "Tea", "Cofee", "Milk" };
    prices = { 30, 50, 40 };
}
void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Automata is ON\n";
    }
}
void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Automata is OFF\n";
    }
}
void Automata::coin(int value) {
    if (state == WAIT || state == ACCEPT) {
        cash += value;
        state = ACCEPT;
        std::cout << "Inserted: " << value << ", total: " << cash << "\n";
    } else {
        std::cout << "Cannot insert coin now\n";
    }
}
std::string Automata::getMenu() {
    std::string result = "Menu: \n";
    for (size_t i = 0; i < menu.size(); ++i) {
        result += std::to_string(i) + ") " + menu[i] + " - " +
            std::to_string(prices[i]) + "\n";
    }
    return result;
}
Automata::STATES Automata::getState() const {
    return state;
}
void Automata::choice(int option) {
    if (state == ACCEPT && option >= 0 && option < static_cast<int>(menu.size())) {
        selected = option;
        state = CHECK;
        std::cout << "Selected: " << menu[option] << "\n";
    } else {
        std::cout << "Invalid choice or wrong state\n";
    }
}
bool Automata::check() {
    if (state == CHECK && selected >= 0) {
        if (cash >= prices[selected]) {
            cook();
            return true;
        } else {
            std::cout << "Not enough money\n";
            state = ACCEPT;
            return false;
        }
    }
    std::cout << "Check not allowed\n";
    return false;
}
void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        std::cout << "Session canceled. Returned: " << cash << "\n";
        cash = 0;
        selected = -1;
        state = WAIT;
    } else {
        std::cout << "Cannot cancel now\n";
    }
}
void Automata::cook() {
    if (state == CHECK && selected >= 0 && cash >= prices[selected]) {
        state = COOK;
        std::cout << "Cooking " << menu[selected] << "...\n";
        finish();
    } else {
        std::cout << "Cannot cook\n";
    }
}
void Automata::finish() {
    if (state == COOK) {
        std::cout << "Your " << menu[selected] << " is ready. Enjoy!\n";
        cash -= prices[selected];
        selected = -1;
        state = WAIT;
    } else {
        std::cout << "Finish not allowed\n";
    }
}
