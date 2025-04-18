#include "splashkit.h"
using std::stoi;
using std::to_string;


int MAX_GUESSES = 7;
int MAX_NUMBER = 100;

// add read string, read integer, and read integer range here
string read_string(string prompt)
{
    write(prompt);
    
    return read_line();
}

int read_int(string prompt)
{
    string input = read_string(prompt);

    while(! is_integer(input))
    {
        write_line("Enter a valid number!");
        read_string(prompt);
    }

    return stoi(input);
}

int read_int(string prompt, int min, int max)
{
    int value = read_int(prompt);

    while(value > max || value < min)
    {
        write_line("Enter within the specified range!");
        value = read_int(prompt);

    }

    return value;
} 

bool perform_guess(int guess_number, int target)
{
    int guess = read_int("Take a guess!: ");

    while(guess > 100 || guess < 0)
    {
        guess = read_int("Comon, make a resonable guess: ");
    }

    if (guess < target)
    {
        write_line("Your guess is below the target");
        return false;
    }
    else if (guess > target)
    {
        write_line("Your guess is above the target");
        return false;
    }
    else
    {
        write_line("You got it! the target was " + to_string(target));
        return true;
    }

}

void play_game()
{
    int guess_number, my_number;
    bool correct;

    my_number = rnd(1, MAX_NUMBER);
    guess_number = 0;

    write_line("I am thinking of a number between 1 and " + to_string(MAX_NUMBER) + ".");

    do
    {
        guess_number++;
        write_line("Guess No.: " + to_string(guess_number));
        correct = perform_guess(guess_number, my_number);


    }while(correct == false && guess_number < MAX_GUESSES);

    if (!correct)
    {
        write_line("Better luck next time! The correct answer was: " + to_string(my_number));
    }
   
    

}


// code the start of perform guess here

int main()
{

    play_game();

  return 0;
}


