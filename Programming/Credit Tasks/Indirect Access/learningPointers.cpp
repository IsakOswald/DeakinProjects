#include "splashkit.h"
#include <iostream>

struct user_data
{
     string name;
     int age;
     bool admin;
};

void change_value(int* ptr);
void add_values(const int* ptr1, const int* ptr2);
void read_user(const user_data* user);

int main()
{

     int arr[5] = {1,2,3,4,5};

     int* arrPtr = &arr[0];

     for (int i = 0; i < 5; i++)
     {
          write_line(*arrPtr + i);
     }

     user_data user = {"Isak", 18, true};

     int number1 = 5;
     int number2 = 25;

     int* ptr1 = &number1;
     int* ptr2 = &number2;

     std::cout << "Number1 ptr: " << ptr1 << "\n";
     std::cout << "Number2 ptr: " << ptr2 << "\n";

     write_line("Access pointers");
     write_line("Pointer 1 points to: " + std::to_string(*ptr1));
     write_line("Pointer 2 points to: " + std::to_string(*ptr2));

     change_value(ptr1);
     write_line("Access pointers");
     write_line("Pointer 1 points to: " + std::to_string(*ptr1));
     write_line("Pointer 2 points to: " + std::to_string(*ptr2));

     add_values(ptr1, ptr2);

     read_user(&user);

     return 0;
}

void read_user(const user_data* user)
{
     std::cout << "Name is: " << user->name;


}

void change_value(int* ptr)
{
     write_line("What do you want to change the value to?: ");
     int input = std::stoi(read_line());

     *ptr = input;
     write_line("Pointer updated the value to: " + std::to_string(*ptr) + " indirectly!");

}

void add_values(const int* ptr1, const int* ptr2)
{

     int result = *ptr1 + *ptr2;

     write_line("Result: " + std::to_string(result));

}