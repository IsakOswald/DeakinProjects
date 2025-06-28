#include "splashkit.h"

enum role_level
{
     NO_ACCESS = 0,
     USER,
     ADMIN,
     SUPER_USER


};

struct user_data
{
     string username;
     string password;
     role_level role;

};



string read_role(const user_data user);
string role_to_string(const role_level role);
void update_role(user_data &user);
void print_user_stats(user_data user);
void update_user (user_data &user);
int main_menu();



int main()
{
     user_data user = {"", "", NO_ACCESS};

     int choice;

     do 
     {
          choice = main_menu();

          switch(choice)
     {
          case 1:
               update_user(user);
               break;
          case 2:

               print_user_stats(user);
               break;
          case 3:
          write_line("Quitting!");
          break;

          default:
               write_line("Not a valid input!");
               break;
     }

     }while(choice != 3);




     return 0;
}


int main_menu()
{
     write_line("1. Update User");
     write_line("2. Print User");
     write_line("3. Quit");

     return std::stoi(read_line());
}

string read_role(const user_data user)
{

     return std::to_string(user.role);
}

string role_to_string(const role_level role)
{
     switch(role)
     {
          case 0:
               return "NO ACCESS";
               break;
          case 1:
               return "USER";
               break;
          case 2:
               return "ADMIN";
               break;
          case 3:
               return "SUPER USER";
               break;
          default:
               return "ERROR";
               break;
     }     
}

void print_user_stats(user_data user)
{
     write_line("Username: " + user.username);
     write_line("Role: " + role_to_string(user.role));

}
void update_user (user_data &user)
{
     write_line("Updated Username: ");
     user.username = read_line();

     write_line("Updated Password: ");
     user.password = read_line();
     
     update_role(user);
     
}

void update_role(user_data &user)
{
     write_line("Update Role [1: User. 2: Admin. 3: Super User]");

     int choice = std::stoi(read_line());

     switch (choice)
     {
          case 1: 
               user.role = USER;
               break;
          case 2:
               user.role = ADMIN;
               break;
          case 3:
               user.role = SUPER_USER;
               break;
          default:
               write_line("Error");
     }
}