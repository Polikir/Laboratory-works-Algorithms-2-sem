#include <iostream>
#pragma once


#include <iostream>
#include <locale>
#include "BinaryTree.h"
#include "Complex.h"
#include "Function.h"
#include "Menu.h"
#include "Tests.h"
#include "BinaryHeap.h"


int main(int argc, char **argv) {
        std::cout << R"(
     /$$        /$$$$$$  /$$$$$$$   /$$$$$$         /$$$$$$
    | $$       /$$__  $$| $$__  $$ /$$__  $$       /$$__  $$
    | $$      | $$  \ $$| $$  \ $$| $$  \ $$      |__/  \ $$
    | $$      | $$$$$$$$| $$$$$$$ | $$$$$$$$         /$$$$$/
    | $$      | $$__  $$| $$__  $$| $$__  $$        |___  $$
    | $$      | $$  | $$| $$  \ $$| $$  | $$       /$$  \ $$
    | $$$$$$$$| $$  | $$| $$$$$$$/| $$  | $$      |  $$$$$$/
    |________/|__/  |__/|_______/ |__/  |__/       \______/
    )" << '\n';
    Test();
	menu();
}
