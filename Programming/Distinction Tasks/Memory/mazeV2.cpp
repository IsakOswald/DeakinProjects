#include <iostream>
#include <string>
#include <vector>

// For clean code
using std::cin;
using std::cout;
using std::string;

// Forward declare the Room struct so it can be used by the Path struct.
struct Room;

struct Path
{
     string description;

     // Holds a pointer to the next room we want to go to.
     Room *destination;

     // Constructor
     Path(const string &description, Room *destination)
     {
          this->description = description;
          this->destination = destination;
     }
};

struct Room
{
     // Variables
     string title;
     string description;
     Path **paths; // A pointer 'paths' that points to a array of pointers. This may be confusing initilaly, however it just means
                   // that 'paths' is just a pointer to a pointer. Its a variable 'paths' that points to the first element of the array
                   // which is another pointer to the 'Path" struct.
     int path_count;
     int path_capacity;

     // Constructor
     Room(const string title, const string description)
     {
          this->title = title;
          this->description = description;
          this->paths = nullptr;
          this->path_count = 0;
          this->path_capacity = 1;
          this->paths = new Path *[path_capacity];
     }

     // Free all paths in the array and then finally the array itself
     ~Room()
     {
          for (int i = 0; i < path_count; i++)
          {
               delete paths[i];
          }
          delete[] paths;
     }

     void add_path(const string &description, Room *destination)
     {
          // Check if the path is the same size as the capacity
          if (path_count == path_capacity)
          {
               // If it is, increase the capacity by 2.
               path_capacity *= 2;
               // Create a new vairable 'temp' which is a pointer to an array of Path*'s.
               Path **temp = new Path *[path_capacity];

               // Loop throuhg the initial array
               for (int i = 0; i < path_count; i++)
               {
                    // Copy elements from the array to our temp array
                    temp[i] = paths[i];
               }

               // Delete the pats array
               delete[] paths;
               // Update the pointer to point to the new array
               paths = temp;
          }

          // At the last position of the path array, insert a new path using the constructor.
          paths[path_count++] = new Path(description, destination);
     }
};

void play_game(Room *start_room)
{
     // Set the current room to the starting room (which is the entrace, only one way in)
     Room *current_room = start_room;

     // Loop so the user can continue moves
     while (true)
     {

          cout << "\nYou are in: " << current_room->title << "\n";
          // Find the current rooms description
          cout << current_room->description << "\n";

          // If the current rooms path_count is 0 there are no more paths
          if (current_room->path_count == 0)
          {
               cout << "There are no paths from this room. Game over!\n";
               break;
          }

          // If there are paths, loop throuhg the available options
          cout << "Paths:\n";
          for (int i = 0; i < current_room->path_count; i++)
          {
               cout << i + 1 << ". " << current_room->paths[i]->description << "\n";
          }

          // Tell the user the choices they have
          int choice;
          cout << "Choose a path (1-" << current_room->path_count << "): ";
          cin >> choice;

          // Check if the choice is out of range
          if (choice < 1 || choice > current_room->path_count)
          {
               cout << "Invalid choice. Try again.\n";
               continue;
          }

          // Set the current room to the new choice -1 (as its an array starting at 0)
          current_room = current_room->paths[choice - 1]->destination;
     }
}

int main()
{

     // Create some rooms.
     Room room1("Entrance", "This is the entrance of the maze.");
     Room room2("Hallway", "A long, dark hallway.");
     Room room3("Library", "A quiet library filled with dusty books.");
     Room room4("Garden", "A beautiful garden with blooming flowers.");
     Room room5("Treasure Room", "A room filled with gold and jewels!");

     // Create some paths with pointing to the address of the rooms
     room1.add_path("Go to the hallway", &room2);
     room2.add_path("Go to the library", &room3);
     room2.add_path("Go to the garden", &room4);
     room3.add_path("Go to the treasure room", &room5);
     room4.add_path("Go to the treasure room", &room5);

     // Pay the game starting at our initial room
     play_game(&room1);

     return 0;
}