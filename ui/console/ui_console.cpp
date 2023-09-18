#include <iostream>

#include "ui_console.h"
#include "../../user_input/keyboard_input.h"

void print_home_ui (void)
{
    std::cout << "Welcome to Console UI Home" << std::endl;

    std::string message = "Choose Number\n(1) 회원가입\n";
    char user_input = getUserInput(message);
    std::cout << "You entered: " << user_input << std::endl;
}