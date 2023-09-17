#include <iostream>
#include <boost/asio.hpp>

#include "keyboard_input.h"

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

boost::asio::io_service io_service;
boost::asio::posix::stream_descriptor input(io_service);

char getch() {
#ifdef _WIN32
    return _getch();
#else
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
#endif
}

char getUserInput(const std::string& message) {
    std::cout << message;
    input.assign(STDIN_FILENO);
    char userInput = 0;
    while (true) {
        userInput = getch();
        if (userInput == '\n') {
            std::cout << std::endl;
            break;
        }
        std::cout << '*';
    }
    return userInput;
}