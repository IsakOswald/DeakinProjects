#include "splashkit.h"

/*
1 | Create a book structure for the books data .
2 | Create a enum structre for the menu (user choice options).
3 | Create an function to make sure input is a valid integer that can be used as pages.
4 | Create a procedure to print the users book detials based on their inputs.
5 | Create a procedure to split the menu nicely and make it look neat.
6 | Create a switch menu procedure to allow user to have different effects when they chose what they want to do.
7 | Create a function to read the contents of the users book. This will tie into the switch based of the Enum.

9 | Doccument learning process.

*/

// A struct to allow us to create different books.
struct book
{
    string name;
    string location;
    int pages;
};

// enum for the menu, allows for easy switch statements and code structure.
enum menu
{
    read_book = 1,
    print_book,
    quit

};

// Function declarations go here.
book create_book();
int print_menu();
int is_valid_integer();
void book_details(book book_info);
void print_splitter();
void switch_menu(int choice, book new_book);
void read();

int main()
{
    // Create a new book
    book new_book = create_book();
    int choice;

    // Switch based on user choide, this is repeated untill user wants to quit.
    do
    {
        choice = print_menu();
        switch_menu(choice, new_book);

    } while (choice != 3); // Repeat untill user wants to quit (3 is the QUIT enum)
}

// Function to create a new book and return the newly created book.
book create_book()
{
    write_line("******* Book manager, created by Isak Oswald. *******");
    print_splitter();
    // Create a new instance of the book struct.
    book new_book;
    // Prompt for user input and use this input for the paramaters of the new book.
    write("What is the name of your book?: ");
    new_book.name = read_line();
    write("Where can I find your book?: ");
    new_book.location = read_line();
    write("How many pages is your book?: ");
    new_book.pages = is_valid_integer();

    // Return this new book for later use.
    return new_book;
}

// A function to create a menu which will corrospont to the enum and switch.
int print_menu()
{
    print_splitter();
    write_line("      |MENU|");
    write_line("1 | Read book.");
    write_line("2 | Print book.");
    write_line("3 | Quit");
    // Record what the user wants to do inside the choice
    int choice = is_valid_integer();
    // Return this choice for the switch statement
    return choice;
}

int is_valid_integer()
{
    string input;
    input = read_line();
    // Ensure that the value the user entered is a valid integer for book pages.
    // Loop untill they enter a valid number.
    while (!is_integer(input) || std::stoi(input) < 0)
    {
        write("Please enter a valid number: ");
        input = read_line();
    }
    // Return this valid integer
    return std::stoi(input);
}

// A procedure to print the book details based on the user created book.
void book_details(book book_info)
{
    print_splitter();
    write_line("      |Book Details|");
    write_line("Name: " + book_info.name);
    write_line("Location: " + book_info.location);
    write_line("Pages: " + std::to_string(book_info.pages));
}

// Create a splitter for neat terminal output.
void print_splitter()
{
    write_line("-------------------------");
}

// A procedure which is a switch based on the user choice and outputs the book data.
void switch_menu(int choice, book new_book)
{
    switch (choice)
    {
    case read_book:
        read();
        break;
    case print_book:
        book_details(new_book);
        break;
    case quit:
        write("Thanks for using my book manager!");
        break;
    }
}

/*
Read the users book contents. This was not required for this task but can be done by adding a
additional paramater in the book struct and using the create_book() function to also get the
book contents entered by the user.

*/
void read()
{

    print_splitter();
    for (int i = 0; i < 5; i++)
    {
        write_line("blahhh blaah bla");
    }
}