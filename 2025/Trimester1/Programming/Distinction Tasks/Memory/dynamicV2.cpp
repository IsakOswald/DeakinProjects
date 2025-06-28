#include <iostream>
#include <string>

struct marker
{
     struct test_score1
     {
          int *test; // Pointer to a dynamic array
          int size;  // Size of the array

          // Constructor to initialize the dynamic array
          test_score1()
          {
               size = get_size();    // Get the size from the user
               test = new int[size]; // Allocate memory for the array

               if (test == nullptr)
               {
                    std::cout << "Memory allocation failed!" << std::endl;
                    exit(1); // Exit the program if memory allocation fails
               }

               // Initialize all grades to 0
               for (int i = 0; i < size; i++)
               {
                    test[i] = 0;
               }
          }

          // Destructor to free the dynamic array
          ~test_score1()
          {
               delete[] test;
               test = nullptr;
          }

          // Function to get the size of the array from the user
          int get_size()
          {
               int size;
               std::cout << "How many students' grades are going to be entered?: ";
               std::cin >> size;
               return size;
          }

          // Function to set grades for the array
          void set_grades()
          {
               for (int i = 0; i < size; i++)
               {
                    std::cout << "Enter grade for student " << i + 1 << ": ";
                    std::cin >> test[i];
               }

               std::cout << "Grades were successfully set!" << std::endl;
          }

          // Function to print the grades
          void print_grades()
          {
               std::cout << "Grades entered:" << std::endl;
               for (int i = 0; i < size; i++)
               {
                    std::cout << "Student " << i + 1 << " grade -> " << test[i] << std::endl;
               }
          }
     };
};

int main()
{
     // Create an instance of test_score1
     marker::test_score1 scores;

     // Set grades for the students
     scores.set_grades();

     // Print the grades
     scores.print_grades();

     return 0;
}