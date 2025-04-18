#pragma once

//* Our libs and headers for the project.
#include <stdlib.h>
#include <string.h>

#include <iostream>

#include "splashkit.h"

// A function which allows us to get a double based on the prompt
double get_double(std::string prompt)
{
    std::string input;

    write(prompt);
    input = read_line();

    while (!is_double(input))
    {
        write_line("Please enter a valid number!");
        input = read_line();
    }

    return std::stod(input);
}

// A function which allows us to get a double based on the prompt
int get_int(std::string prompt)
{
    std::string input;

    write(prompt);
    input = read_line();

    while (!is_integer(input))
    {
        write_line("Please enter a valid number!");
        input = read_line();
    }

    return std::stoi(input);
}

// A function for nicely formatted terminal output
void print_splitter() { write_line("*********************"); }