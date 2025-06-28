#include "splashkit.h"
#include <iostream>

using std::string;
using std::stoi;
using std::to_string;
using std::stod;

int main()
{
    double total = 0, min = 0, mean = 0, max = 0;
    int count = 0;
    string answer, line;

    do
    {
        double value;

        write("Enter a value: ");
        line = read_line();
    
        while (!is_double(line))
        {
            write("Try again. Enter a valid number: ");
            line = read_line();
        }
    
        value = stod(line);
        count++;
        total += value;

        write_line("Count: " + to_string(count));

        if (count == 1 || value > max) 
        {
            max = value;
        }
        write_line("Max: " + to_string(max));

        if (count == 1 || value < min) 
        {
            min = value;
        }
        write_line("Min: " + to_string(min));

        mean = total / count;
        write_line("Average: " + to_string(mean));

        write("Go again?[y/n]: ");
        answer = read_line();
        
        while (answer != "y" && answer != "n" && answer != "Y" && answer != "N")
        {
            write("Invalid input. Try again: ");
            answer = read_line();
        }

    } while (answer == "y" || answer == "Y");

    return 0;
}
