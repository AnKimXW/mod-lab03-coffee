// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1) {
    Automata a;
    EXPECT_EQ(a.getState(), Automata::OFF);
}

TEST(task, test2) {
    Automata a;
    a.on();
    a.coin(20);
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}

TEST(task, test3) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    EXPECT_EQ(a.getState(), Automata::CHECK);
}

TEST(task, test4) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    bool success = a.check();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(task, test5) {
    Automata a;
    a.on();
    a.coin(20);
    a.choice(1);
    EXPECT_FALSE(a.check());
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}

TEST(task, test6) {
    Automata a;
    a.on();
    a.coin(50);
    a.cancel();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(task, test7) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    a.cancel();
    EXPECT_EQ(a.getState(), Automata::WAIT);
}

TEST(task, test8) {
    Automata a;
    a.on();
    a.coin(20);
    a.coin(20);
    a.coin(20);
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
    a.choice(0);
    EXPECT_TRUE(a.check());
}

TEST(task, test9) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), Automata::WAIT);
    a.off();
    EXPECT_EQ(a.getState(), Automata::OFF);
}

TEST(task, test10) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(-1);
    EXPECT_EQ(a.getState(), Automata::ACCEPT);
}
