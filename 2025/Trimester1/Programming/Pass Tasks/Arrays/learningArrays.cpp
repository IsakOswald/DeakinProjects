#include "splashkit.h"

const int MAX_SIZE = 3;


void search_array(string arr[], int MAX_SIZE, string search);
void total_length(string arr[], int MAX_SIZE);
void find_shortest_name(string arr[], int MAX_SIZE);

string read_string(string prompt)
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

int read_valid_integer(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

int main()
{
    string names[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        names[i] = read_string("What is your name: ");
    }


    for (int i = 0; i < MAX_SIZE; i++ )
    {
        write_line("Name " + std::to_string(i + 1) + " is: " + names[i]);
    }

    total_length(names, MAX_SIZE);
    search_array(names, MAX_SIZE, "Isak");
    find_shortest_name(names, MAX_SIZE);

    return 0;
}

void total_length(string arr[], int MAX_SIZE)
{
    int sum = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        sum += length_of(arr[i]);
    }

    write_line("There are " + std::to_string(sum) + " characters in the array");
   
}

void search_array(string arr[], int MAX_SIZE, string search)
{
    bool found = false;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (to_lowercase(search) == to_lowercase(arr[i]))
        {
            write_line("Its here! @ index: " + std::to_string(i));
            found = true;
            break;
        }
        
        
    }
    
    if(!found)
    {
        write_line("Not here!");
    }

}

void find_shortest_name(string arr[], int MAX_SIZE)
{
    string shortest = arr[0];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (length_of(arr[i]) < length_of(shortest))
        {
            shortest = arr[i];
        }
    }

    write_line("The shortest name is: " + shortest + " with " + std::to_string(length_of(shortest)) + " characters! ");
}