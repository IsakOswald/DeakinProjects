#include "splashkit.h"

/*

//todo: add struct DONE
//todo: add populate_array DONE
//todo: add print DONE
//todo: add max DONE
//todo: add sum 
//todo: add mean 


*/

const int MAX_SIZE = 20;

struct number_data
{
    int current_size;
    double values[MAX_SIZE];

};


string read_string(string prompt);
double is_valid_double(string prompt);
int is_valid_integer(string prompt);
void add_nums(number_data& numbers);
void print_array(number_data& numbers);
void print_splitter();
double calculate_sum(number_data& numbers);



int main()
{
    number_data numbers = {0, {}};
    add_nums(numbers);
    print_array(numbers);
    write_line(calculate_sum(numbers));




    return 0;
}



void add_nums(number_data& numbers)
{
    print_splitter();

    int entries = is_valid_integer("How many enteries would you like?: ");
    string input;

    while (entries > MAX_SIZE || entries < 0)
    {
        entries = is_valid_integer("Please enter a valid input (0-20): ");
    }

    numbers.current_size = entries;

    for (int i = 0; i < numbers.current_size; i++)
    {
        print_splitter(); 

        numbers.values[i] = is_valid_double("Enter value number " + std::to_string(i+1) + ": ");
        
        
    }
}


string read_string(string prompt)
{
    string input;
    write(prompt);
 

    return read_line();

}

void print_splitter()
{
    write_line("    ***************************************     ");
}

double is_valid_double(string prompt)
{
    string input;

    write(prompt);
    input = read_line();

    while(! is_double(input))
    {
        write("Enter a valid double: ");
        input = read_line();
    }

    return std::stod(input);
}

int is_valid_integer(string prompt)
{
    string input;

    write(prompt);
    input = read_line();

    while(! is_integer(input))
    {
        write("Enter a valid positive integer: ");
        input = read_line();
    }

    return std::stoi(input);
}

void print_array(number_data& numbers)
{
    print_splitter();

    for (int i = 0; i < numbers.current_size; i++ )
    {
        write_line("Value " + std::to_string(i+1) + " is: " + std::to_string(numbers.values[i]));
    }
}

double calculate_sum(number_data& numbers)
{
    print_splitter();

    double sum;

    for (int i = 0; i < numbers.current_size; i++)
    {
        sum += numbers.values[i];
    }

    return sum;
}