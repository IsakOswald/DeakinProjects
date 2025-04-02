#include "splashkit.h"

//? Create the dynamic array struct with the template which allows for any input.
template <typename T>
struct dynamic_array
{
     T *data;
     int current_size;
     int capacity;
};

//* Function declerations *
template <typename T>
dynamic_array<T> *create_dynamic_array(int capacity);
template <typename T>
void check_resize_array(dynamic_array<T> *array);
template <typename T>
void add_element(dynamic_array<T> *array, T element);
template <typename T>
void get_element(dynamic_array<T> *array, T value_to_find);
//**************************

int main()
{
     //? Call the crete_dynamic_array function to create a new instance of dynamic_array with a capacity of 4.
     dynamic_array<int> *array = create_dynamic_array<int>(4);
     //? Test by adding some elements and ensuring the check_resize_arry works as intended.
     add_element(array, 5);
     add_element(array, 23);
     add_element(array, 8);
     add_element(array, -1);
     check_resize_array(array);

     get_element(array, 23);
     get_element(array, 3);
     get_element(array, -1);
     check_resize_array(array);

     return 0;
}

//! A templated function which create the initial instance of dynamic_array dynamically
template <typename T>
// Return type should be a ptr of type dynamic_arry<T>.
dynamic_array<T> *create_dynamic_array(int capacity)
{
     dynamic_array<T> *array = nullptr;

     // Try to dynamically alocate memory for the new class instance.
     try
     {
          // Create a new instance and set some paramaters
          array = new dynamic_array<T>;

          array->capacity = capacity;

          array->current_size = 0;

          // Dynamically create the array of type T.
          array->data = new T[array->capacity];

          write_line("Array has been created! ");
          return array;
          write_line('\n');
     }

     //! If the allocation fails, free the memory which was initially created and return a null ptr.
     catch (const std::bad_alloc &)
     {
          write_line("Allocation failed! Removing the unused memory!");
          delete array;
          return nullptr;

          write_line('\n');
     }
}

//! Add a element to the dynamically created instance of dynamic_array
template <typename T>
// The user can enter what ever value they like with type T
void add_element(dynamic_array<T> *array, T element)
{
     // Set the new element to the free index and increase its size by one.
     array->data[array->current_size] = element;
     array->current_size++;

     write_line("The element " + std::to_string(element) + " has been added to the array");
     //! Make sure the array is not full!
     check_resize_array(array);
     write_line('\n');
}

//! Check the size of the array to make sure it isn't full
template <typename T>
void check_resize_array(dynamic_array<T> *array)
{
     // Try to resize the array if its full. If it is double the capacity
     try
     {
          if (array->current_size >= array->capacity)
          {
               int new_capacity = array->capacity * 2;

               T *new_data = new T[new_capacity];

               for (int i = 0; i < array->current_size; i++)
               {
                    new_data[i] = array->data[i];
               }

               delete[] array->data;

               array->data = new_data;
               write_line("The array has be resized!");
               write_line('\n');
          }

          // Check if the array is not full yet to avoid over resizing.
          else
          {
               write_line("The array has been checked and does not neet to be resized yet!");
               delay(1000);
               write_line('\n');
          }
     }

     //! If this fails, dont do anything
     catch (const std::bad_alloc &)
     {
          write_line("Allocation failed!");
          write_line("Array was not resized!");

          write_line('\n');
     }
}

//! check if a element of type T is in the array
template <typename T>
void get_element(dynamic_array<T> *array, T value_to_find)
{
     bool found = false;

     // Loop through the aray and search for the element we want to find
     for (int i = 0; i < array->current_size; i++)
     {
          if (array->data[i] == value_to_find)
          {
               write_line("The value is in the array @ index: " + std::to_string(i));
               found = true;
               write_line('\n');
          }
     }

     // If the array is not found, print some output.
     if (!found)
     {
          write_line("Sadly, your element was not found!");
          write_line('\n');
     }
}