// main.cpp - the program's starting point.
// It reads commands you type, passes them to the KVStore, and prints results.
// This is called a REPL: Read, Evaluate, Print, Loop.
//
// You don't need to change this file in Stage 1 - read it to see how it works.

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

#include "kvstore.h"

int main() {
    KVStore store;

    std::cout << "kvstore - commands: SET key value | GET key | DEL key | SIZE | EXIT\n";

    std::string line;
    while (true) {
        std::cout << "> " << std::flush;

        // Read one full line. If input ends (Ctrl+D), stop.
        if (!std::getline(std::cin, line)) break;

        // Split the line into words: "SET name Vaishnavi" -> "SET", "name", "Vaishnavi"
        std::istringstream words(line);
        std::string cmd, key;
        words >> cmd >> key;

        // Make the command uppercase so "set" and "SET" both work.
        for (char& c : cmd) c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));

        if (cmd.empty()) {
            continue;  // blank line
        } else if (cmd == "SET") {
            // The value is everything after the key (so it can contain spaces).
            std::string value;
            std::getline(words >> std::ws, value);
            if (key.empty() || value.empty()) {
                std::cout << "usage: SET key value\n";
                continue;
            }
            store.set(key, value);
            std::cout << "OK\n";
        } else if (cmd == "GET") {
            if (key.empty()) { std::cout << "usage: GET key\n"; continue; }
            auto value = store.get(key);
            if (value) std::cout << *value << "\n";
            else       std::cout << "(not found)\n";
        } else if (cmd == "DEL") {
            if (key.empty()) { std::cout << "usage: DEL key\n"; continue; }
            std::cout << (store.del(key) ? "deleted\n" : "(not found)\n");
        } else if (cmd == "SIZE") {
            std::cout << store.size() << "\n";
        } else if (cmd == "EXIT" || cmd == "QUIT") {
            break;
        } else {
            std::cout << "unknown command: " << cmd << "\n";
        }
    }

    std::cout << "bye\n";
    return 0;
}
