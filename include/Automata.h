// Copyright 2025 Owner
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <vector>
class Automata {
 public:
    enum STATES {
        OFF, WAIT, ACCEPT, CHECK, COOK
    };
    Automata();
    void on();
    void off();
    void coin(int value);
    std::string getMenu();
    STATES getState() const;
    void choice(int option);
    bool check();
    void cancel();
    void cook();
    void finish();

 private:
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state;
    int selected;
};
#endif // INCLUDE_AUTOMATA_H_
