#include "splashkit.h"

/*

//todo: add struct DONE
//todo: add populate_array DONE
//todo: add print DONE
//todo: add max DONE
//todo: add sum DONE 
//todo: add mean DONE

ADDED: REMOVE ELEMENT


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
double calculate_mean(number_data& numbers);
double get_max(number_data& numbers);
void get_switch_input(number_data& numbers);
void user_menu();
void remove_elemnt(number_data& numbers);


int main()
{
    number_data numbers = {0, {}};

    get_switch_input(numbers);

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

double calculate_mean(number_data& numbers)
{
 
    if(numbers.current_size > 0)
    {
        return calculate_sum(numbers) / numbers.current_size;
    }
    else
    {
        return 0;
    }
    
}

double get_max(number_data& numbers)
{
    double max = numbers.values[0];

    print_splitter();

    if (numbers.current_size < 1)
    {
        return 0;
    }
    else
    {
        for (int i=0; i < numbers.current_size; i++)
        {
            if (numbers.values[i] > max)
            {
                max = numbers.values[i];
            }
        }

        return max;

    }
}

void user_menu()
{
    write_line("1. Add Values");
    write_line("2. Calculate Sum");
    write_line("3. Calculate Mean");
    write_line("4. Calculate Max");
    write_line("5. Remove Element");
    write_line("6. QUIT");
}

void get_switch_input(number_data& numbers)
{
    int choice;

    do
    {
        print_splitter();
        user_menu();
        choice = is_valid_integer("Enter a choice: ");

        while (((choice > 6) || (choice < 1)))
        {
            choice = is_valid_integer("Enter a valid choice!: ");
        }

        switch(choice)
        {
            case 1:
                add_nums(numbers);
                break;
            case 2:
                write_line("Sum: " + std::to_string(calculate_sum(numbers)));
                break;
            case 3:
                write_line("Mean: " + std::to_string(calculate_mean(numbers)));
                break;
            case 4:
                write_line("Max: " + std::to_string(get_max(numbers)));
                break;
            case 5:
                remove_elemnt(numbers);
                break;
            case 6:
                break;
        }

    } while (choice != 6);
}

void remove_elemnt(number_data& numbers)
{

    print_splitter();

    int index;

    if (numbers.current_size < 1)
    {
        write("Nothing to remove! ");
    }
    else
    {
        index = is_valid_integer("Enter an index to remove: ");

        for (int i = index; i < numbers.current_size - 1; i++)
        {
            numbers.values[i] = numbers.values[i + 1];
        }
        numbers.current_size--;

        write_line("Element Removed! ");



    }
}