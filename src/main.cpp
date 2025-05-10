// Copyright 2025 Owner
#include "Automata.h"
#include <iostream>

int main() {
    Automata a;
    a.on();
    std::cout << a.getMenu();
    a.coin(50);
    a.choice(1);
    if (!a.check()) {
        a.cancel();
    }
    a.off();
    return 0;
}
