#include "splashkit.h"

/*

Create spliiter and int/double conversion functions.
Create a function so a so a user can initially set their bank data.
Create a menu and menu template function.
Create a withdraw and depodit procedure.
Create a procedure which calculatues the intrest.


*/



//Create the bank struct.
struct bank_accounts
{
     string name;
     double balance;
     double intrest_rate;
};

//Functions
void print_splitter();
void deposit(bank_accounts &account);
void enter_initial(bank_accounts &account);
void menu_template();
int read_integer();
int main_menu(bank_accounts &account); 
void print_details(const bank_accounts &account);
void withdraw(bank_accounts &account);
int read_double();
void add_intrest(bank_accounts &account);
//---------------------------------------

int main()
{
     //Create a new instance of bank_accounts.
     bank_accounts account = {"", 0.0, 0.0};
     enter_initial(account);

     int option = 0;
     //Loop through the menu untill user quits.
     do
     {
          option = main_menu(account); 

     } while(option != 5);

     return 0;
}

//Prompt the user to enter the initial data to get some data to work with.
void enter_initial(bank_accounts &account)
{
     print_splitter();

     write("Enter account name: ");
     account.name = read_line();
     deposit(account);
     write("Enter the intrest rate as a %: ");
     account.intrest_rate = read_double();

}

//Allow the user to deposit money.
void deposit(bank_accounts &account)
{
     write("How much would you like to deposit?: $");
     string input = read_line();

     //Make sure the input is a double and is above 0.
     while(! is_double(input) || std::stod(input) < 0)
     {
          write("Please enter a valid amount!: $");
          input = read_line();
     }

     double usr_deposit = std::stod(input);

     //Add the validated input to the users balance.
     account.balance += usr_deposit; 
}

//Simple splitter for terminal output.
void print_splitter()
{
     write_line("   ***************************   ");
}

//Create a template for the menu which allows for easy modification later if needed.
void menu_template()
{
     print_splitter();
     write_line("Actions: ");

     write_line("1. Print account details");
     write_line("2. Deposit");
     write_line("3. Withdraw");
     write_line("4. Add interest");
     write_line("5. Quit");
     write("Choice: ");
}

//Create the real main menu where user can pick from the menu template.
int main_menu(bank_accounts &account) 
{
     menu_template();
     int choice = read_integer();

     switch(choice)
     {
          case 1:
               print_details(account);
               break;
          case 2:
               deposit(account);
               break;
          case 3:
               withdraw(account);
               break;
          case 4:
               add_intrest(account);
               break;
          case 5:
               write_line("Exiting program...");
               break;
     }

     return choice; 
}

//Allow the user to calculate the intrest rate (as entered initially) and how it would reflect in their balance.
void add_intrest(bank_accounts &account)
{
     print_splitter();
     write("How many days?: ");
     int days = read_integer();

     //Calculate the intrest rate and then make sure it is reflected with the users balance.
     double intrest = (account.intrest_rate / 365.0) * days;
     double result = (intrest / 100) * account.balance;

     //Output the results to the user and ensure to add it to the current balance.
     write_line("The intrest earned is: " + std::to_string(result));
     account.balance += result;
     write_line("This leaves your new balance as: " + std::to_string(account.balance));
}

//Withdraw money from the current balance.
void withdraw(bank_accounts &account)
{
     print_splitter();
     write("Withdraw ammount: ");
     int input = read_integer();

     //Make sure that user cant take out more money then they own.
     while(input > account.balance)
     {
          write_line("Cant widthdraw that much! Try again:");
          input = read_integer();
     }

     //Subtract the ammount reqested to widthdraw from the users balance.
     account.balance -= input;
     write_line("Widthdraw complete!");

}

//Print the details of the account (We have not included the name because is it only one account)
void print_details(const bank_accounts &account)
{

     print_splitter();
     write_line("Current balance: " + std::to_string(account.balance));
     write_line("Rate: " + std::to_string(account.intrest_rate));


}

//Simple commands to validate input (from user)
int read_integer()
{
     string input = read_line();

     while(! is_integer(input))
     {
          write_line("Enter valid input: ");
          input = read_line();
     }

     return std::stoi(input);
}

int read_double()
{
     string input = read_line();

     while(! is_double(input))
     {
          write_line("Enter valid input: ");
          input = read_line();
     }

     return std::stod(input);
}
//------------------------------------------------